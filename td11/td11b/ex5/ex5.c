#include <stdio.h>
#include <stdlib.h>
#include "../../lib/listes.h"


void supprimerOccurrences(Noeud **tete, int val) {
  if (!tete || !*tete) return;

  /* Supprimer les têtes qui correspondent */
  while (*tete != NULL && (*tete)->valeur == val) {
    Noeud *tmp = *tete;
    *tete = (*tete)->suivant;
    free(tmp);
  }

  Noeud *cur = *tete;
  while (cur != NULL && cur->suivant != NULL) {
    if (cur->suivant->valeur == val) {
      Noeud *tmp = cur->suivant;
      cur->suivant = tmp->suivant;
      free(tmp);
    } else {
      cur = cur->suivant;
    }
  }
}

int main(void) {
  int tab[] = {1,2,2,3,3,3,4,4,4,4};
  Noeud *tete = creerListeDunTab(tab, 10);

  puts("Les elements de la liste:");
  afficherListe(tete);

  printf("Entrez l'entier a supprimer: \n");
  int x;
  if (scanf("%d", &x) != 1) {
    fprintf(stderr, "Entrée invalide\n");
    libererListe(tete);
    return EXIT_FAILURE;
  }

  supprimerOccurrences(&tete, x);

  puts("Les elements de la liste apres suppression:");
  afficherListe(tete);

  libererListe(tete);
  return EXIT_SUCCESS;
}
//mkdir -p /home/do501389/tdsinitD/td.initD25/td11/td11b/ex5/output && gcc -Wall -Wextra -g3 /home/do501389/tdsinitD/td.initD25/td11/td11b/ex5/ex5.c /home/do501389/tdsinitD/td.initD25/td11/lib/listes.c -I/home/do501389/tdsinitD/td.initD25/td11/lib -o /home/do501389/tdsinitD/td.initD25/td11/td11b/ex5/output/ex5
///home/do501389/tdsinitD/td.initD25/td11/td11b/ex5/output/ex5