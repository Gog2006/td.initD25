#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
  int sommet;
  int maxTaille;
  int tab[MAX_SIZE];
} PileTableau;

PileTableau pile = {.sommet = -1, .maxTaille = MAX_SIZE};

int estPleine(PileTableau *p) {
  return p->sommet >= p->maxTaille - 1;
}

int estVide(PileTableau *p) {
  return p->sommet == -1;
}

void empile(PileTableau *p, int val) {
  if (estPleine(p)) {
    fprintf(stderr, "Pile pleine, impossible d'empiler %d\n", val);
    return;
  }
  p->tab[++(p->sommet)] = val;
}

int depile(PileTableau *p) {
  if (estVide(p)) {
    fprintf(stderr, "Pile vide, impossible de depiler\n");
    return -1; /* valeur sentinelle */
  }
  return p->tab[(p->sommet)--];
}

int sommet(PileTableau *p) {
  if (estVide(p)) {
    fprintf(stderr, "Pile vide, aucun sommet\n");
    return -1;
  }
  return p->tab[p->sommet];
}

int main(void) {
  /* Affichage attendu */
  printf("Sortie attendue\n");
  printf("Empile 1 puis 3 puis 2 comme dans l'illustration\n");

  /* Empilements */
  empile(&pile, 1);
  empile(&pile, 3);
  empile(&pile, 2);

  printf("Le sommet est: %d\n\n", sommet(&pile));

  printf("Dépile deux fois comme dans l'illustration\n");
  int v1 = depile(&pile);
  printf("Dépile -> %d\n", v1);
  int v2 = depile(&pile);
  printf("Dépile -> %d\n", v2);

  printf("Le sommet est: %d\n", sommet(&pile));

  return 0;
}

