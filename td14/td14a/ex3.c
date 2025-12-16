#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoeudAB {
    int valeur;
    struct NoeudAB *gauche;
    struct NoeudAB *droit;
} NoeudAB;


void afficherAB(NoeudAB *n) {
    if (n == NULL) {
        printf("Arbre vide ∅\n");
        return;
    }
    size_t cap = 128;
    NoeudAB **q = malloc(cap * sizeof(*q));
    if (!q) return;
    size_t head = 0, tail = 0;
    size_t nodesCurrent = 1, nodesNext = 0;

    q[tail++] = n;

    while (head < tail) {
        NoeudAB *cur = q[head++];
        printf(" %d", cur->valeur);

        if (cur->gauche) {
            if (tail + 1 >= cap) { cap *= 2; q = realloc(q, cap * sizeof(*q)); }
            q[tail++] = cur->gauche;
            nodesNext++;
        }
        if (cur->droit) {
            if (tail + 1 >= cap) { cap *= 2; q = realloc(q, cap * sizeof(*q)); }
            q[tail++] = cur->droit;
            nodesNext++;
        }

        nodesCurrent--;
        if (nodesCurrent == 0) {
            putchar('\n');
            nodesCurrent = nodesNext;
            nodesNext = 0;
        }
    }

    free(q);
}



void libererArbre(NoeudAB** racine) {
    if (*racine != NULL) {
        libererArbre(&((*racine)->gauche));
        libererArbre(&((*racine)->droit));
        free(*racine);
        *racine = NULL;
    }
}
typedef enum { PRE, IN, POST } DFSOrdre;

void parcourirProfondeurAB(NoeudAB* racine, DFSOrdre ordre, bool inverse) {
    if (racine == NULL) return;

    if (!inverse) {
        if (ordre == PRE) {
            printf("%d ", racine->valeur);
        }

        parcourirProfondeurAB(racine->gauche, ordre, inverse);

        if (ordre == IN) {
            printf("%d ", racine->valeur);
        }

        parcourirProfondeurAB(racine->droit, ordre, inverse);

        if (ordre == POST) {
            printf("%d ", racine->valeur);
        }
    } else {
        if (ordre == POST) {
            printf("%d ", racine->valeur);
        }

        parcourirProfondeurAB(racine->droit, ordre, inverse);

        if (ordre == IN) {
            printf("%d ", racine->valeur);
        }

        parcourirProfondeurAB(racine->gauche, ordre, inverse);

        if (ordre == PRE) {
            printf("%d ", racine->valeur);
        }
    }
}

static NoeudAB* creerNoeud(int v) {
    NoeudAB* n = malloc(sizeof(NoeudAB));
    if (!n) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    n->valeur = v;
    n->gauche = n->droit = NULL;
    return n;
}

NoeudAB* creerExempleAB(void) {
    // crée un arbre binaire d'exemple :
    //         2
    //      7     5        
    //   2    6      9
    //      5  11   4
    NoeudAB* r = creerNoeud(2);
    r->gauche = creerNoeud(7);
    r->droit  = creerNoeud(5);
    r->gauche->gauche = creerNoeud(2);
    r->gauche->droit  = creerNoeud(6);
    r->droit->droit   = creerNoeud(9);
    r->gauche->droit->droit = creerNoeud(11);
    r->gauche->droit->gauche = creerNoeud(5);
    r->droit->droit->gauche = creerNoeud(4);
    return r;
}

int main() {
    NoeudAB* racine = creerExempleAB();
    puts("Affichage de l'arbre créé");
    afficherAB(racine);
    puts("Libération de l'arbre");
    libererArbre(&racine);
    afficherAB(racine);
    return 0;
}