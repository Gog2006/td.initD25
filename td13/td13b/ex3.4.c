#include <stdio.h>

typedef struct {
  char titre[32];
  int masse;
  int prix;
} Livre;

// Données
Livre livres[] = {{"Livre poche", 1, 1},
                  {"Memo d'algorithmique", 1, 2},
                  {"Manuel de C", 2, 2},
                  {"Tout en un BUT1", 4, 10},
                  {"Collection complete de Knuth", 12, 4}};

void afficherLivre(Livre livre){
    printf("    %s (%d kg, %d euros)\n", livre.titre, livre.masse, livre.prix);
}


void trierParPrixDesc(Livre tab[], int n){
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(tab[j].prix / tab[j].masse > tab[i].prix / tab[i].masse){
                Livre tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
    }
}

void sacGloutonRatio(Livre tab[], int nbLivre, int capaSac){
    int prixTotal = 0;
    int masseTotale = 0;

    printf("---\n");
    printf("Algo glouton par ratio prix/masse\n");
    printf("---\n");

    printf("Capacite du sac: %d kg\n", capaSac);
    trierParPrixDesc(tab, nbLivre);
    printf("Tri des livres ->\n");
    for(int i = 0; i < nbLivre; ++i){
        afficherLivre(tab[i]);
    }

    printf("\nRemplissage du sac\n");
    for(int i = 0; i < nbLivre; ++i){
        if(masseTotale + tab[i].masse <= capaSac){
            afficherLivre(tab[i]);
            prixTotal += tab[i].prix;
            masseTotale += tab[i].masse;
        } else {
            break;
        }
    }

    printf("RÉSULTAT: %d€ (%dkg / %dkg)\n", prixTotal,masseTotale, capaSac);
}

int main() {
  int nbLivre = sizeof(livres) / sizeof(Livre);

  int capaSac = 5;  

  // Appel
  sacGloutonRatio(livres, nbLivre, capaSac);

  return 0;
}