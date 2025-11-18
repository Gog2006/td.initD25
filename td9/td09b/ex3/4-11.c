#include <stdio.h>
#include <string.h>

#define MAX_ETUDIANTS 100

typedef struct {
  int ine;
  char nom[20];
  char prenom[20];
  double note;
} Etudiant;

void afficherEtu(Etudiant etu) {
  printf("%d: %s %s (Note: %.2f)\n", etu.ine, etu.nom, etu.prenom, etu.note);
}

void initialiserListeEtudiants(Etudiant liste[]) {
  for (int i = 0; i < MAX_ETUDIANTS; i++) {
    liste[i].ine = 0;
  }
}

int nbEtudiant(Etudiant t[]) {
  int count = 0;
  while (count < MAX_ETUDIANTS && t[count].ine != 0) {
    count++;
  }
  return count;
}

void afficherListe(Etudiant t[]) {
  int nb = nbEtudiant(t);
  for (int i = 0; i < nb; i++) {
    afficherEtu(t[i]);
  }
}

// Insère un étudiant en gardant la liste triée par INE
// Intérêt: liste triée = recherche dichotomique plus rapide
void insererEtu(Etudiant t[], Etudiant nouvelEtudiant) {
  //  récupérer le nombre d'étudiants actuels
  int i = nbEtudiant(t);

  //  vérifier qu'il reste de la place
  if (i >= MAX_ETUDIANTS) {
    fprintf(stderr, "Nb d'étudiants maximum atteint\n");
    return;
  }

  //  si la liste est vide, insérer directement
  if (i == 0) {
    t[0] = nouvelEtudiant;
    return;
  }

  //  parcourir la liste de la fin vers le début
  int j = i - 1;
  // Étape 5: décaler les étudiants avec un INE plus grand vers la droite
  while (j >= 0 && t[j].ine > nouvelEtudiant.ine) {
    t[j + 1] = t[j];
    j--;
  }

  //  insérer le nouvel étudiant à sa position
  t[j + 1] = nouvelEtudiant;
}

int rechercherEtu(Etudiant t[], int numero) {
  int gauche = 0;
  int droite = nbEtudiant(t) - 1;

  while (gauche <= droite) {
    int milieu = (gauche + droite) / 2;

    if (t[milieu].ine == numero) {
      return milieu;
    } else if (t[milieu].ine < numero) {
      gauche = milieu + 1;
    } else {
      droite = milieu - 1;
    }
  }

  return -1;
}

int main() {
  // Déclaration de la liste d'étudiants
  Etudiant liste[MAX_ETUDIANTS];

  // initialise la liste en mettant les ine à 0
  initialiserListeEtudiants(liste);

  puts("Ajout de trois étudiants en les affichant");
  Etudiant etu1 = {123, "Seydoux", "Laura", 15.3};
  afficherEtu(etu1);
  insererEtu(liste, etu1);

  Etudiant etu2 = {324, "Alexis", "Manenti", 5.9};
  afficherEtu(etu2);
  insererEtu(liste, etu2);

  Etudiant etu3 = {255, "Camélia", "Jordana", 9.9};
  afficherEtu(etu3);
  insererEtu(liste, etu3);

  printf("\nVoici la liste de %d étudiants triée par ine\n", nbEtudiant(liste));
  afficherListe(liste);

  // Recherche d'un étudiant
  int numeroRecherche;
  printf("\nEntrez un numéro d'étudiant à rechercher: ");
  scanf("%d", &numeroRecherche);

  int indice = rechercherEtu(liste, numeroRecherche);
  if (indice != -1) {
    Etudiant etu = liste[indice];
    if (etu.note > 10) {
      printf("ADMIS:) ");
    } else if (etu.note >= 8) {
      printf("RATTRAPAGE:! ");
    } else {
      printf("RECALÉ! ");
    };
    afficherEtu(etu);
  } else {
    printf("Étudiant non trouvé.\n");
  }

  return 0;
}
