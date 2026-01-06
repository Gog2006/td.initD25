#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define LENGTHDICO 20
#define MAX_WORD_LEN 200

typedef struct sMot {
    char *mot; /* chaine de caracteres */
    int lg;    /* longueur sans le \0 */
} sMot;

/* 1. effaceMots : parcourt le tableau et libere la memoire */
void effaceMots(sMot* dictionnaire[LENGTHDICO]) {
    for (int i = 0; i < LENGTHDICO; ++i) {
        if (dictionnaire[i]) {
            free(dictionnaire[i]->mot);
            free(dictionnaire[i]);
            dictionnaire[i] = NULL;
        }
    }
}

/* 2. longueurDico : renvoie le nombre de mots presents */
int longueurDico(sMot* dictionnaire[LENGTHDICO]) {
    int c = 0;
    for (int i = 0; i < LENGTHDICO; ++i) {
        if (dictionnaire[i]) ++c;
    }
    return c;
}

/* 3. ajouteMot : demande un mot a l'utilisateur et l'ajoute */
void ajouteMot(sMot* dictionnaire[LENGTHDICO]) {
    int idx = -1;
    for (int i = 0; i < LENGTHDICO; ++i) {
        if (dictionnaire[i] == NULL) { idx = i; break; }
    }
    if (idx == -1) {
        puts("Le dictionnaire est plein. Impossible d'ajouter un mot.");
        return;
    }

    char buffer[MAX_WORD_LEN];
    printf("Entrez un mot: ");
    if (scanf("%199s", buffer) != 1) {
        puts("Erreur de lecture du mot");
        return;
    }

    sMot *m = malloc(sizeof(sMot));
    if (!m) { perror("malloc"); return; }
    m->lg = (int)strlen(buffer);
    m->mot = malloc(m->lg + 1);
    if (!m->mot) { free(m); perror("malloc"); return; }
    strcpy(m->mot, buffer);

    dictionnaire[idx] = m;
}

/* 4. afficheDict : affiche les mots du dictionnaire */
void afficheDict(sMot* dictionnaire[LENGTHDICO]) {
    int n = longueurDico(dictionnaire);
    printf("Affichage du dictionnaire\n");
    for (int i = 0, shown = 0; i < LENGTHDICO && shown < n; ++i) {
        if (dictionnaire[i]) {
            printf("Mot %d: %s\n", shown, dictionnaire[i]->mot);
            ++shown;
        }
    }
}

/* Sauvegarde le dictionnaire dans un fichier (un mot par ligne) */
int sauvegardeDico(sMot* dictionnaire[LENGTHDICO], const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) { perror("fopen"); return -1; }
    for (int i = 0; i < LENGTHDICO; ++i) {
        if (dictionnaire[i]) {
            fprintf(f, "%s\n", dictionnaire[i]->mot);
        }
    }
    fclose(f);
    return 0;
}

/* Charge un dictionnaire depuis un fichier (un mot par ligne)
   Retourne le nombre de mots charges */
int chargeDico(sMot* dictionnaire[LENGTHDICO], const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) return 0; /* si fichier absent, rien a charger */
    char buffer[MAX_WORD_LEN];
    int count = 0;
    while (fgets(buffer, sizeof(buffer), f)) {
        /* retirer \n */
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') buffer[len-1] = '\0';
        if (count >= LENGTHDICO) break;
        sMot *m = malloc(sizeof(sMot));
        if (!m) { perror("malloc"); break; }
        m->lg = (int)strlen(buffer);
        m->mot = malloc(m->lg + 1);
        if (!m->mot) { free(m); perror("malloc"); break; }
        strcpy(m->mot, buffer);
        dictionnaire[count] = m;
        ++count;
    }
    fclose(f);
    return count;
}

int main(void) {
    sMot* dictionnaire[LENGTHDICO] = {0};

    printf("Combien de mots souhaitez-vous stocker? ");
    int n = 0;
    if (scanf("%d", &n) != 1) {
        puts("Entrée invalide");
        return 1;
    }
    if (n < 0) n = 0;
    if (n > LENGTHDICO) n = LENGTHDICO;

    for (int i = 0; i < n; ++i) {
        printf("Entrez un mot: ");
        char buffer[MAX_WORD_LEN];
        if (scanf("%199s", buffer) != 1) {
            puts("Erreur de lecture");
            break;
        }
        sMot *m = malloc(sizeof(sMot));
        if (!m) { perror("malloc"); break; }
        m->lg = (int)strlen(buffer);
        m->mot = malloc(m->lg + 1);
        if (!m->mot) { free(m); perror("malloc"); break; }
        strcpy(m->mot, buffer);
        /* stocker au premier emplacement vide */
        int idx = -1;
        for (int j = 0; j < LENGTHDICO; ++j) if (!dictionnaire[j]) { idx = j; break; }
        if (idx == -1) { puts("Dictionnaire plein"); free(m->mot); free(m); break; }
        dictionnaire[idx] = m;
    }

    /* affichage */
    afficheDict(dictionnaire);

    int taille = longueurDico(dictionnaire);
    printf("Longueur du dictionnaire: %d\n", taille);

    if (taille > 0) {

        srand((unsigned)time(NULL));
        int r = rand() % taille;

        int phys = -1;
        for (int i = 0, seen = 0; i < LENGTHDICO; ++i) {
            if (dictionnaire[i]) {
                if (seen == r) { phys = i; break; }
                ++seen;
            }
        }
        if (phys != -1) {
            printf("Choix au hasard d'un element:\nMot %d de longueur %d: %s\n",
                   r, dictionnaire[phys]->lg, dictionnaire[phys]->mot);
        }
    }


    if (sauvegardeDico(dictionnaire, "dico.txt") == 0) {
        printf("Dictionnaire sauvegarde dans dico.txt\n");
    }


    effaceMots(dictionnaire);
    printf("Remplissage du dictionnaire a partir de dico.txt\n");
    int loaded = chargeDico(dictionnaire, "dico.txt");
    afficheDict(dictionnaire);
    printf("Longueur du dictionnaire: %d\n", loaded);

    if (loaded > 0) {
        srand((unsigned)time(NULL) + 1);
        int r = rand() % loaded;
        int phys = -1;
        for (int i = 0, seen = 0; i < LENGTHDICO; ++i) {
            if (dictionnaire[i]) {
                if (seen == r) { phys = i; break; }
                ++seen;
            }
        }
        if (phys != -1) {
            printf("Choix au hasard d'un element: Mot %d de longueur %d: %s\n",
                   r, dictionnaire[phys]->lg, dictionnaire[phys]->mot);
        }
    }

    effaceMots(dictionnaire);
    return 0;
}
