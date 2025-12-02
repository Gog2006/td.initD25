# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

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

void libererListe(Noeud* liste) {
    Noeud* temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp);
    }
}

bool estTrieeListe (Noeud* liste) {
    if (liste == NULL || liste->suivant == NULL) {
        return true;
    }
    Noeud* courant = liste;
    while (courant->suivant != NULL) {
        if (courant->valeur > courant->suivant->valeur) {
            return false;
        }
        courant = courant->suivant;
    }
    return true;
}

Noeud* insereElementListe(Noeud* tete, int valeur) {
    Noeud* nouveau = malloc(sizeof(Noeud));
    nouveau->valeur = valeur;
    nouveau->suivant = NULL;

    if (tete == NULL || valeur < tete->valeur) {
        nouveau->suivant = tete;
        return nouveau;
    }

    Noeud* courant = tete;
    while (courant->suivant != NULL && courant->suivant->valeur < valeur) {
        courant = courant->suivant;
    }
    nouveau->suivant = courant->suivant;
    courant->suivant = nouveau;

    return tete;
}
 


Noeud* triListe (Noeud* liste) {
    Noeud* triee = NULL;
    Noeud* courant = liste;
    while (courant != NULL) {
        Noeud* suivant = courant->suivant;
        triee = insereElementListe(triee, courant->valeur);
        courant = suivant;
    }
    return triee;
}   




int main() {
  // listes chainées
  int tab[] = {1, 4, 5, 6, 2};
  Noeud* liste = creerListeDunTab(tab, 5);
  afficherListe(liste);
  printf("Liste %s triée.\n", estTrieeListe(liste) ? "" : "non");

  printf("\nOn trie la liste\n");
  liste = triListe(liste);
  afficherListe(liste);
  printf("Liste %s triée.\n", estTrieeListe(liste) ? "" : "non");

  // Test d'insertion en boucle
  printf("\nInsertion d'éléments\n");
  for (int i = 0; i < 6; i += 2) {
    printf("On insère la valeur %d\n", i);
    liste = insereElementListe(liste, i);
    afficherListe(liste);
  }

  // Libération de la mémoire
  libererListe(liste);

  return 0;
}