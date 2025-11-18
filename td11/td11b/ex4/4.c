#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../lib/listes.h"

void ajouter(Noeud **tete, int nbAInserer) {
  Noeud* nouveau = malloc(sizeof(Noeud));
  if (!nouveau) {
    fprintf(stderr, "allocation failed\n");
    return;
  }
  nouveau->valeur = nbAInserer;
  nouveau->suivant = NULL;

  if (*tete == NULL) {
    *tete = nouveau;
    return;
  }

  Noeud* cur = *tete;
  while (cur->suivant != NULL) cur = cur->suivant;
  cur->suivant = nouveau;
}

int main() {
  srand(time(NULL));
  int nbAInserer;
  Noeud* tete = NULL;

  puts("Insertion de 7 nombres aléatoires entre 0 et 9");
  for (int i = 0; i < 7; i++) {
    nbAInserer = rand() % 10;
    ajouter(&tete, nbAInserer);
    printf("Ajout de %d\n", nbAInserer);
    afficherListe(tete);
  }

  puts("Libération de la mémoire");
  libererListe(tete);
  return 0;
}

// compilation gcc -Wall -Wextra -g3 /home/do501389/tdsinitD/td.initD25/td11/td11b/ex4/4.c /home/do501389/tdsinitD/td.initD25/td11/lib/listes.c -I/home/do501389/tdsinitD/td.initD25/td11/lib -o /home/do501389/tdsinitD/td.initD25/td11/td11b/ex4/output/4
// execution /home/do501389/tdsinitD/td.initD25/td11/td11b/ex4/output/4