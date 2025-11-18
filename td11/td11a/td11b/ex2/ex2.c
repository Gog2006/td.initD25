#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Noeud {
  int valeur;
  struct Noeud* suivant;
} Noeud;

void afficherListe(Noeud* tete) {
  Noeud* courant = tete;
  while (courant != NULL) {
    printf("%d -> ", courant->valeur);
    courant = courant->suivant;
  }
  printf("NULL\n");
}


int main() {
  Noeud* n1 = malloc(sizeof(Noeud));
  Noeud* n2 = malloc(sizeof(Noeud));
  Noeud* n3 = malloc(sizeof(Noeud));

  Noeud* tete = n1;


  n1->valeur = 12;
  n1->suivant = n2;
  n2->valeur = 99;
  n2->suivant = n3;
  n3->valeur = 37;
  n3->suivant = NULL;

afficherListe(tete);
  // libérer la mémoire  
  free(n1);
  free(n2);
  free(n3);
}