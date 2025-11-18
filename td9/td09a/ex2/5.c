#include <stdio.h>
#include <string.h>

typedef enum { ENTIER, FLOTTANT, CARACTERE } TypeDonnee;

union Donnee {
  int entier;
  double flottant;
  char caractere;
};

struct Element {
  TypeDonnee type;
  union Donnee valeur;
};

void afficherElement(struct Element e) {
  switch (e.type) {
    case ENTIER:
      printf("entier = %d\n", e.valeur.entier);
      break;
    case FLOTTANT:
      printf("flottant = %.2lf\n", e.valeur.flottant);
      break;
    case CARACTERE:
      printf("caractère = %c\n", e.valeur.caractere);
      break;
    default:
      printf("type inconnu\n");
  }
}

int main() {
  struct Element e1, e2, e3;


   e1.type = ENTIER;
  e1.valeur.entier = 42;


  e2.type = FLOTTANT;
  e2.valeur.flottant = 3.14;

  e3.type = CARACTERE;
  e3.valeur.caractere = 'A';

  printf("e1 : ");
  afficherElement(e1);

  printf("e2 : ");
  afficherElement(e2);

  printf("e3 : ");
  afficherElement(e3);

  return 0;
}