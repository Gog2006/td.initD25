#include <stdio.h>
#include <stdlib.h>

typedef struct NoeudDouble {
  int data;
  struct NoeudDouble* prev;
  struct NoeudDouble* next;
} NoeudDouble;

int supprimeNoeudDouble(NoeudDouble** liste, NoeudDouble* noeud) {
  if (*liste == NULL || noeud == NULL) {
    fprintf(stderr, "Liste vide ou noeud NULL\n");
    exit(1);
  }
  int val = noeud->data;
  // Si en première position
  if (*liste == noeud) {
    *liste = noeud->next;
    if (*liste != NULL) {
      (*liste)->prev = NULL;
    }
  }
  if (noeud->prev != NULL) {
    noeud->prev->next = noeud->next;
  }
  if (noeud->next != NULL) {
    noeud->next->prev = noeud->prev;
  }
  free(noeud);
  return val;
}

void afficherListeDouble(NoeudDouble* liste) {
  NoeudDouble* courant = liste;
  while (courant != NULL) {
    printf("%d <-> ", courant->data);
    courant = courant->next;
  }
  printf("\n");
}

int main() {
  // Création d'une liste doublement chaînée : 1 <-> 2 <-> 3 <-> 4
  NoeudDouble* liste = NULL;

  // Ajout de nœuds (pour simplifier, on les ajoute en tête)
  for (int i = 4; i >= 1; i--) {
    NoeudDouble* nouveau = malloc(sizeof(NoeudDouble));
    nouveau->data = i;
    nouveau->prev = NULL;
    nouveau->next = liste;
    if (liste != NULL) {
      liste->prev = nouveau;
    }
    liste = nouveau;
  }

  printf("Liste initiale : ");
  afficherListeDouble(liste);

  // Test 1 : Suppression du nœud en tête (valeur 1)
  NoeudDouble* aSupprimer = liste;
  int val = supprimeNoeudDouble(&liste, aSupprimer);
  printf("Suppression de %d : ", val);
  afficherListeDouble(liste);

  // Test 2 : Suppression du nœud en milieu (valeur 2)
  aSupprimer = liste->next;
  val = supprimeNoeudDouble(&liste, aSupprimer);
  printf("Suppression de %d : ", val);
  afficherListeDouble(liste);

  // Test 3 : Suppression du nœud en queue (valeur 4)
  aSupprimer = liste;
  while (aSupprimer->next != NULL) {
    aSupprimer = aSupprimer->next;
  }
  val = supprimeNoeudDouble(&liste, aSupprimer);
  printf("Suppression de %d : ", val);
  afficherListeDouble(liste);

  // Test 4 : Suppression du dernier nœud restant (valeur 3)
  aSupprimer = liste;
  val = supprimeNoeudDouble(&liste, aSupprimer);
  printf("Suppression de %d : ", val);
  afficherListeDouble(liste);

  return 0;
}