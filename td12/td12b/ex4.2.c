# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct Noeud {
    int valeur;
    struct Noeud* suivant;
} Noeud;

Noeud* creerListeDunTab(int tab[], int n) {
    Noeud* tete = NULL;
    Noeud* dernier = NULL;
    for (int i = 0; i < n; ++i) {
        Noeud* node = malloc(sizeof(Noeud));
        node->valeur = tab[i];
        node->suivant = NULL;
        if (tete == NULL) {
            tete = node;
        } else {
            dernier->suivant = node;
        }
        dernier = node;
    }
    return tete;
}

void afficherListe(Noeud* liste) {
    printf("Liste: ");
    Noeud* courant = liste;
    while (courant != NULL) {
        printf("%d -> ", courant->valeur);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

void libererListe(Noeud* liste) {
    Noeud* temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp);
    }
}

bool estTrieeListe (Noeud* liste) {
    if (liste == NULL || liste->suivant == NULL) {
        return true;
    }
    Noeud* courant = liste;
    while (courant->suivant != NULL) {
        if (courant->valeur > courant->suivant->valeur) {
            return false;
        }
        courant = courant->suivant;
    }
    return true;
}

Noeud* insereElementListe(Noeud* tete, int valeur) {
    Noeud* nouveau = malloc(sizeof(Noeud));
    nouveau->valeur = valeur;
    nouveau->suivant = NULL;

    if (tete == NULL || valeur < tete->valeur) {
        nouveau->suivant = tete;
        return nouveau;
    }

    Noeud* courant = tete;
    while (courant->suivant != NULL && courant->suivant->valeur < valeur) {
        courant = courant->suivant;
    }
    nouveau->suivant = courant->suivant;
    courant->suivant = nouveau;

    return tete;
}
 


Noeud* triListe (Noeud* liste) {
    Noeud* triee = NULL;
    Noeud* courant = liste;
    while (courant != NULL) {
        Noeud* suivant = courant->suivant;
        triee = insereElementListe(triee, courant->valeur);
        courant = suivant;
    }
    return triee;
}   


int* tableauScanfTaille(int n) {
    if (n <= 0) return NULL;
    int* tab = malloc(sizeof(int) * n);
    if (!tab) { perror("malloc"); exit(EXIT_FAILURE); }
    printf("Entrez les éléments:\n");
    for (int i = 0; i < n; ++i) {
        printf("Donner la valeur de l'entier pour l'élément %d: ", i+1);
        fflush(stdout);
        if (scanf("%d", &tab[i]) != 1) { fprintf(stderr, "Lecture échouée\n"); free(tab); exit(EXIT_FAILURE); }
    }
    return tab;
}

void afficherTab(int* tab, int n) {
    if (!tab) { printf("{}\n"); return; }
    printf("{");
    for (int i = 0; i < n; ++i) {
        printf("%d", tab[i]);
        if (i + 1 < n) printf(", ");
    }
    printf("}\n");
}

bool estTrieeTab(int* tab, int n) {
    if (!tab || n <= 1) return true;
    for (int i = 0; i + 1 < n; ++i) if (tab[i] > tab[i+1]) return false;
    return true;
}

void triTab(int* tab, int n) {
    // simple insertion sort (stable, in-place)
    for (int i = 1; i < n; ++i) {
        int key = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > key) { tab[j+1] = tab[j]; --j; }
        tab[j+1] = key;
    }
}

void insereElementTabTrie(int** tabptr, int valeur, int* nptr) {
    if (!tabptr || !nptr) return;
    int n = *nptr;
    int* tab = *tabptr;
    int* ntab = realloc(tab, sizeof(int) * (n + 1));
    if (!ntab) { perror("realloc"); return; }
    int i = n - 1;
    while (i >= 0 && ntab[i] > valeur) { ntab[i+1] = ntab[i]; --i; }
    ntab[i+1] = valeur;
    *tabptr = ntab;
    *nptr = n + 1;
}

int main() {
  int taille;
  int* tab;
  printf("Quelle taille de tableau souhaitez-vous?\n");
  scanf("%d", &taille);
  printf("Créez un tableau de %d éléments non triés SVP\n", taille);
  tab = tableauScanfTaille(taille);

  afficherTab(tab, taille);
  printf("Tab %s trié\n", estTrieeTab(tab, taille) ? "" : "non");
  printf("On trie le Tab\n");
  triTab(tab, taille);
  afficherTab(tab, taille);

  printf("Tab %s trié.\n", estTrieeTab(tab, taille) ? "" : "non");

  // Test d'insertion en boucle
  printf("\nInsertion d'éléments\n");
  for (int i = 0; i < 6; i += 2) {
    printf("On insère la valeur %d\n", i);
    insereElementTabTrie(&tab, i, &taille);
    afficherTab(tab, taille);
  }

  // Libération de la mémoire
  free(tab);

  return 0;
}