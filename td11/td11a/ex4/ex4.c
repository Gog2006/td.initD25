#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct NoeudChar {
  char valeur;
  struct NoeudChar* suivant;
} NoeudChar;

typedef struct {
  NoeudChar* sommet;
} PileChar;

PileChar p = {NULL};

int estPleine(PileChar *p) {
  /* Liste chaînée : jamais pleine (sauf mémoire insuffisante) */
  (void)p;
  return 0;
}

int estVide(PileChar *p) {
  return p->sommet == NULL;
}

void empile(PileChar *p, char val) {
  if (estPleine(p)) {
    fprintf(stderr, "Pile pleine, impossible d'empiler %c\n", val);
    return;
  }
  NoeudChar* nouveau = malloc(sizeof(NoeudChar));
  if (!nouveau) {
    fprintf(stderr, "Erreur d'allocation memoire\n");
    exit(EXIT_FAILURE);
  }
  nouveau->valeur = val;
  nouveau->suivant = p->sommet;
  p->sommet = nouveau;
}

char depile(PileChar *p) {
  if (estVide(p)) {
    fprintf(stderr, "Pile vide, impossible de depiler\n");
    exit(EXIT_FAILURE);
  }
  NoeudChar* temp = p->sommet;
  char valeur = temp->valeur;
  p->sommet = temp->suivant;
  free(temp);
  return valeur;
}

char sommet(PileChar *p) {
  if (estVide(p)) {
    fprintf(stderr, "Pile vide, aucun sommet\n");
    exit(EXIT_FAILURE);
  }
  return p->sommet->valeur;
}

int main(void) {
  char s[MAX_SIZE];
  printf("Entrez une chaine (sans espaces) : ");
  if (scanf("%99s", s) != 1) {
    fprintf(stderr, "Erreur de lecture\n");
    return 1;
  }

  /* Empiler chaque caractère */
  for (size_t i = 0; s[i] != '\0'; ++i) {
    empile(&p, s[i]);
  }

  /* Dépiler et afficher pour obtenir la chaîne inversée */
  printf("Chaine inversee: ");
  while (!estVide(&p)) {
    putchar(depile(&p));
  }
  putchar('\n');
  return 0;
}

