#include <stdio.h>
#include "tablistes.h"

void afficherTabListe(TabListe *liste) {
    printf("[");
    for (int i = 0; i < liste->taille; i++) {
        printf("%d", liste->tab[i]);
        if (i < liste->taille - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void ajouterElt(TabListe *liste, int valeur) {
    if (liste->taille >= TAILLE_TAB) {
        printf("Erreur: le tableau est plein, impossible d'ajouter l'élément.\n");
        return;
    }
    liste->tab[liste->taille] = valeur;
    liste->taille++;
}

void retirerElt(TabListe *liste) {
    if (liste->taille <= 0) {
        printf("Erreur: le tableau est vide, impossible de retirer un élément.\n");
        return;
    }
    liste->taille--;
}

void insererElt(TabListe *liste, int indice, int valeur) {
    if (indice < 0 || indice > liste->taille) {
        printf("Erreur: position invalide pour l'insertion.\n");
        return;
    }
    if (liste->taille >= TAILLE_TAB) {
        printf("Erreur: le tableau est plein, impossible d'insérer l'élément.\n");
        return;
    }
    
    for (int i = liste->taille; i > indice; i--) {
        liste->tab[i] = liste->tab[i - 1];
    }
    
    liste->tab[indice] = valeur;
    liste->taille++;
}

void supprimerElt(TabListe *liste, int indice) {
    if (indice < 0 || indice >= liste->taille) {
        printf("Erreur: position invalide pour la suppression.\n");
        return;
    }
    
    for (int i = indice; i < liste->taille - 1; i++) {
        liste->tab[i] = liste->tab[i + 1];
    }
    
    liste->taille--;
}
