#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listes.h"




void afficherListe(Noeud* tete) {
  Noeud* courant = tete;
  while (courant != NULL) {
    printf("%d -> ", courant->valeur);
    courant = courant->suivant;
  }
  printf("NULL\n");
}


unsigned longueurListe(Noeud* tete){
    int count = 0;
    Noeud* courant = tete;
    while (courant != NULL) {
        count++;
        courant = courant->suivant;
    }
    return count;
}

Noeud* creerListeDunTab(int tab[], int taille){
    if(taille <= 0) return NULL;
    Noeud* tete = NULL;
    for(int i = taille - 1; i >= 0; i--){
        Noeud* nouveau = malloc(sizeof(Noeud));
        nouveau->valeur = tab[i];
        nouveau->suivant = tete;
        tete = nouveau;
    }
    return tete;

}

void libererListe(Noeud* tete){
    Noeud* courant = tete;
    while (courant != NULL) {
        Noeud* temp = courant;
        courant = courant->suivant;
        free(temp);
    }
}

