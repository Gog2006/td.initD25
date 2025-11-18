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

int main() {
  struct Element e1, e2;

  e1.type = ENTIER;
e1.valeur.caractere = 'A';
printf("e1 (caractère) : %c\n", e1.valeur.caractere);

  e2.type = FLOTTANT;
  e2.valeur.flottant = 3.14;

  printf("e1 : ");
  if (e1.type == ENTIER) {
    printf("entier = %d\n", e1.valeur.entier);
  }

  printf("e2 : ");
  if (e2.type == FLOTTANT) {
    printf("flottant = %.2lf\n", e2.valeur.flottant);
  }

  return 0;
}