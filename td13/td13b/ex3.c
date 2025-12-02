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

void sacGloutonMasse(Livre tab[], int n, int capaSac){
    int masseTotale = 0;
    int prixTotal = 0;

    printf("---\n");
    printf("Algo glouton par masse\n");
    printf("---\n");

    printf("Capacite du sac: %d kg\n", capaSac);
    printf("Les livres sont deja triers par masse croissante ->\n");
    for(int i = 0; i < n; ++i){
        afficherLivre(tab[i]);
    }

    printf("\nRemplissage du sac\n");
    for(int i = 0; i < n; ++i){
        if(masseTotale + tab[i].masse <= capaSac){
            afficherLivre(tab[i]);
            masseTotale += tab[i].masse;
            prixTotal += tab[i].prix;
        }
    }

    printf("RESULTAT: %d€ (%dkg / %dkg)\n", prixTotal, masseTotale, capaSac);
}

int main() {
  int nbLivre = sizeof(livres) / sizeof(Livre);

  int capaSac = 5;  

  // Appel
  sacGloutonMasse(livres, nbLivre, capaSac);

  return 0;
}