#include <stdio.h>

struct Livre {
  char titre[100];
  char auteur[100];
  int anneePub;
};

void afficherLivre(struct Livre* livre) {
  printf("Titre: %s, Auteur: %s, Année: %d\n", livre->titre, livre->auteur,
         livre->anneePub);
}

int main() {
  struct Livre livre1 = {"Le Petit Prince", "Antoine de Saint-Exupéry", 1943};
  struct Livre livre2 = {"1984", "George Orwell", 1949};

  afficherLivre(&livre1);
  afficherLivre(&livre2);

  return 0;
}