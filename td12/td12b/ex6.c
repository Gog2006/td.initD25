#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Noeud {
  int valeur;
  struct Noeud* suivant;
} Noeud;

Noeud* creerListeDunTab(int tab[], int n) {
  Noeud* tete = NULL;
  Noeud* dernier = NULL;
  for (int i = 0; i < n; ++i) {
    Noeud* node = malloc(sizeof(Noeud));
    node->valeur = tab[i];
    node->suivant = NULL;
    if (tete == NULL) tete = node;
    else dernier->suivant = node;
    dernier = node;
  }
  return tete;
}

void afficherListe(Noeud* liste) {
  Noeud* courant = liste;
  while (courant != NULL) {
    printf("%d -> ", courant->valeur);
    courant = courant->suivant;
  }
  printf("NULL\n");
}


void bubbleSortList(Noeud* tete, int n) {
  if (!tete) return;
  for (int i = 0; i < n; ++i) {
    Noeud* p = tete;
    while (p != NULL && p->suivant != NULL) {
      if (p->valeur > p->suivant->valeur) {
        int tmp = p->valeur;
        p->valeur = p->suivant->valeur;
        p->suivant->valeur = tmp;
      }
      p = p->suivant;
    }
  }
}

void libererListe(Noeud* liste) {
  Noeud* tmp;
  while (liste != NULL) {
    tmp = liste;
    liste = liste->suivant;
    free(tmp);
  }
}

int main(void) {
  int n;
  printf("Nombre d'éléments souhaité dans la liste: ");
  fflush(stdout);
  if (scanf("%d", &n) != 1 || n <= 0) return 1;

  printf("Entrez les éléments:\n");
  int* tab = malloc(sizeof(int) * n);
  if (!tab) return 1;
  for (int i = 0; i < n; ++i) {
    printf("Donner la valeur de l'entier du noeud %d: ", i+1);
    fflush(stdout);
    if (scanf("%d", &tab[i]) != 1) { free(tab); return 1; }
  }

  Noeud* liste = creerListeDunTab(tab, n);
  free(tab);

  printf("Les éléments de la liste:\n");
  afficherListe(liste);

  printf("Tri à bulles de la liste chainée à l'adresse %p de taille %d\n", (void*)liste, n);
  bubbleSortList(liste, n);

  printf("Les éléments de la liste après le tri:\n");
  afficherListe(liste);

  libererListe(liste);
  return 0;
}



