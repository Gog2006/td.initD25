#include <stdio.h>
#include <stdlib.h> 
#define MAX_SIZE 100

typedef struct Noeud {
  int valeur;
  struct Noeud* suivant;
} Noeud;

typedef struct {
  Noeud* sommet;
} Pile;

Pile p = {NULL};

int estVide(Pile* pile) {
  return pile->sommet == NULL;
}

void empile(Pile* pile, int val) {
  Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
  if (!nouveau) {
    fprintf(stderr, "Erreur d'allocation memoire\n");
    return;
  }
  nouveau->valeur = val;
  nouveau->suivant = pile->sommet;
  pile->sommet = nouveau;
}

int depile(Pile* pile) {
  if (estVide(pile)) {
    fprintf(stderr, "Pile vide, impossible de depiler\n");
    exit(EXIT_FAILURE);
  }
  Noeud* temp = pile->sommet;
  int val = temp->valeur;
  pile->sommet = pile->sommet->suivant;
  free(temp);
  return val;
}
int getSommet(Pile* pile) {
  if (estVide(pile)) {
    fprintf(stderr, "Pile vide, aucun sommet\n");
    exit(1);
  }
  return pile->sommet->valeur;
}

int main(void) {

  printf("Pile initialisée, estVide renvoie: %d\n", estVide(&p));
  printf("Début de l'empilement.\n");

  empile(&p, 10);
  printf("Valeur empilee: 10\n");
  empile(&p, 20);
  printf("Valeur empilee: 20\n");
  empile(&p, 30);
  printf("Valeur empilee: 30\n");

  printf("Maintenant estVide renvoie: %d et getSommet: %d\n", estVide(&p), getSommet(&p));

  printf("Dépile et affiche tous les elements avec une boucle while\n");
  while (!estVide(&p)) {
    int v = depile(&p);
    printf("Dépile %d\n", v);
  }

  printf("Maintenant estVide renvoie: %d\n", estVide(&p));
  return 0;
}
