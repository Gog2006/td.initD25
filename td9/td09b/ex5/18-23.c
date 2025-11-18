#include <stdio.h>
#include "tablistes.h"

int main() {
  TabListe maListe;
  maListe.taille = 0;
  printf("Liste vide de départ: ");
  afficherTabListe(&maListe);
  printf("Taille actuelle : %d\n", maListe.taille);

  ajouterElt(&maListe, 10);
  ajouterElt(&maListe, 20);
  ajouterElt(&maListe, 30);

  printf("Liste après 3 ajouts en fin de liste: ");
  afficherTabListe(&maListe);
  printf("Taille actuelle : %d\n", maListe.taille);

  retirerElt(&maListe);
  printf("Liste après suppression en fin: ");
  afficherTabListe(&maListe);
  printf("Taille actuelle : %d\n", maListe.taille);

  insererElt(&maListe, 1, 15);
  printf("Liste après ajout à l'indice 1: ");
  afficherTabListe(&maListe);
  printf("Taille actuelle : %d\n", maListe.taille);

  supprimerElt(&maListe, 0);
  printf("Liste après suppression à l'indice 0: ");
  afficherTabListe(&maListe);
  printf("Taille actuelle : %d\n", maListe.taille);

  return 0;
}
