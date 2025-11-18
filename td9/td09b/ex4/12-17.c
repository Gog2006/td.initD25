#include <stdio.h>
#include <string.h>

#define TAILLE 100

typedef struct {
  char titre[TAILLE];
  char auteur[TAILLE];
  int anneePub;
} Livre;

typedef struct {
  char nom[TAILLE];
  int nbLivre;
  Livre livres[TAILLE];
} Bibliotheque;

void ajouterLivre(Bibliotheque *bib, Livre livre) {
  if (bib->nbLivre < TAILLE) {
    bib->livres[bib->nbLivre] = livre;
    bib->nbLivre++;
  }
}

void afficherBibliotheque(Bibliotheque *bib) {
  printf("Bibliothèque: %s, Nombre de livres: %d\n", bib->nom, bib->nbLivre);
  for (int i = 0; i < bib->nbLivre; i++) {
    printf("Titre: %s, Auteur: %s, Année: %d\n", 
           bib->livres[i].titre, bib->livres[i].auteur, bib->livres[i].anneePub);
  }
}

void rechercherLivreParAuteur(Bibliotheque *bib, char *auteur) {
  for (int i = 0; i < bib->nbLivre; i++) {
    if (strcmp(bib->livres[i].auteur, auteur) == 0) {
      printf("Titre: %s, Année: %d\n", bib->livres[i].titre, bib->livres[i].anneePub);
    }
  }
}

void trierParAnnee(Bibliotheque *bib) {
  for (int i = 1; i < bib->nbLivre; i++) {
    Livre cle = bib->livres[i];
    int j = i - 1;
    while (j >= 0 && bib->livres[j].anneePub > cle.anneePub) {
      bib->livres[j + 1] = bib->livres[j];
      j--;
    }
    bib->livres[j + 1] = cle;
  }
}

int main() {
  Bibliotheque maBib;
  strcpy(maBib.nom, "Ma Bibliothèque");
  maBib.nbLivre = 0;

  Livre livre1 = {"Le Petit Prince", "Antoine de Saint-Exupéry", 1943};
  ajouterLivre(&maBib, livre1);

  Livre livre2 = {"1984", "George Orwell", 1949};
  ajouterLivre(&maBib, livre2);

  Livre livre3 = {"Les Misérables", "Victor Hugo", 1862};
  ajouterLivre(&maBib, livre3);

  printf("Bibliothèque avant le tri:\n");
  afficherBibliotheque(&maBib);

  trierParAnnee(&maBib);

  printf("\nBibliothèque après le tri par année:\n");
  afficherBibliotheque(&maBib);

  printf("Livres de l'auteur George Orwell:\n");
  rechercherLivreParAuteur(&maBib, "George Orwell");

  return 0;
}
