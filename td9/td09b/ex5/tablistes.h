#ifndef TABLISTES_H
#define TABLISTES_H

#define TAILLE_TAB 256

typedef struct {
    int tab[TAILLE_TAB];
    int taille;
} TabListe;

void afficherTabListe(TabListe *liste);

void ajouterElt(TabListe *liste, int valeur);

void retirerElt(TabListe *liste);

void insererElt(TabListe *liste, int indice, int valeur);

void supprimerElt(TabListe *liste, int indice);

#endif
