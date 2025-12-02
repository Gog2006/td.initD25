#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct Noeud {
    int valeur;
    struct Noeud* suivant;
} Noeud;


void permute(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Noeud* creerListeDunTab(int* tab, int taille) {
    Noeud* tete = NULL;
    Noeud* dernier = NULL;
    for (int i = 0; i < taille; ++i) {
        Noeud* node = malloc(sizeof(Noeud));
        node->valeur = tab[i];
        node->suivant = NULL;
        if (tete == NULL) {
            tete = node;
        } else {
            dernier->suivant = node;
        }
        dernier = node;
    }
    return tete;

}


void afficherListe(Noeud* liste) {
    printf("Liste: ");
    Noeud* courant = liste;
    while (courant != NULL) {
        printf("%d -> ", courant->valeur);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

void ajouterNoeud(Noeud** tete, int valeur) {
    Noeud* node = malloc(sizeof(Noeud));
    node->valeur = valeur;
    node->suivant = *tete;
    *tete = node;
}

Noeud* concatenerListes(Noeud* liste1, Noeud* liste2) {
    if (liste1 == NULL) {
        return liste2;
    }
    Noeud* courant = liste1;
    while (courant->suivant != NULL) {
        courant = courant->suivant;
    }
    courant->suivant = liste2;
    return liste1;
}


void triRapideListe(Noeud** liste) {

    if (liste == NULL || *liste == NULL || (*liste)->suivant == NULL) {
        return;
    }

    Noeud* pivot = *liste;
    Noeud* moins = NULL;
    Noeud* egale = NULL;
    Noeud* plus = NULL;

    Noeud* courant = *liste;
    while (courant != NULL) {
        if (courant->valeur < pivot->valeur) {
            ajouterNoeud(&moins, courant->valeur);
        } else if (courant->valeur == pivot->valeur) {
            ajouterNoeud(&egale, courant->valeur);
        } else {
            ajouterNoeud(&plus, courant->valeur);
        }
        courant = courant->suivant;
    }

    triRapideListe(&moins);
    triRapideListe(&plus);

    *liste = concatenerListes(moins, egale);
    *liste = concatenerListes(*liste, plus);
}




int main() {
  // Cas 0: Tableau de test aléatoire
  srand(time(NULL));
  int taille = 5 + rand() % 11;
  int tab[taille];
  for (int i = 0; i < taille; i++) {
    tab[i] = -99 + rand() % 200;
  }
  Noeud* list = creerListeDunTab(tab, taille);

  printf("Liste avant le tri : ");
  afficherListe(list);

  triRapideListe(&list);

  printf("Liste après le tri : ");
  afficherListe(list);

  return 0;
}
