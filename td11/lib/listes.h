#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct Noeud {
  int valeur;
  struct Noeud* suivant;
} Noeud;


void afficherListe(Noeud* tete);


unsigned longueurListe(Noeud* tete);

Noeud* creerListeDunTab(int tab[], int taille);

void libererListe(Noeud* tete); 
