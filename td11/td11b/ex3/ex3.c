#include <stdio.h>

#include "../../lib/listes.h"

int main() {
  // Initialisation de la liste
  int tab[] = {12, 99, 37};
  Noeud* tete = creerListeDunTab(tab, 3);

  puts("Affichage de la liste:");
  afficherListe(tete);
  printf("Longueur de la liste: %u", longueurListe(tete));

  // Libération de la mémoire allouée pour éviter les fuites de mémoire
  libererListe(tete);

  return 0;
}