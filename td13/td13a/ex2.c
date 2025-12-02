#include <stdio.h>
#include <stdlib.h> 
#include <time.h>


void permute(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void triRapide(int* tab, int iMin, int iMax){   
if (iMin < iMax) {
    int pivot = tab[iMax];
    int i = iMin - 1;

    for (int j = iMin; j < iMax; j++) {
        if (tab[j] <= pivot) {
            i++;
            permute(&tab[i], &tab[j]);
        }
    }
    permute(&tab[i + 1], &tab[iMax]);
    int pivotIndex = i + 1;

    triRapide(tab, iMin, pivotIndex - 1);
    triRapide(tab, pivotIndex + 1, iMax);   
}
}

void afficherTab(int* tab, int n) {
    if (!tab) { printf("{}\n"); return; }
    printf("{");
    for (int i = 0; i < n; ++i) {
        printf("%d", tab[i]);
        if (i + 1 < n) printf(", ");
    }
    printf("}\n");
}

int main() {
  // Cas 0: Tableau de test aléatoire
  srand(time(NULL));
  int taille = 5 + rand() % 11;
  int tab[taille];
  for (int i = 0; i < taille; i++) {
    tab[i] = -99 + rand() % 200;
  }
  puts("Tableau initial aléatoire:");
  afficherTab(tab, taille);
  triRapide(tab, 0, taille - 1);
  afficherTab(tab, taille);

  // Cas 1 : Tableau déjà trié (croissant)
  int tab1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  taille = sizeof(tab1) / sizeof(tab1[0]);
  puts("\nTableau déjà trié (croissant) :");
  afficherTab(tab1, taille);
  triRapide(tab1, 0, taille - 1);
  afficherTab(tab1, taille);

  // Cas 2 : Tableau déjà trié (décroissant)
  int tab2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  taille = sizeof(tab2) / sizeof(tab2[0]);
  puts("\nTableau déjà trié (décroissant) :");
  afficherTab(tab2, taille);
  triRapide(tab2, 0, taille - 1);
  afficherTab(tab2, taille);

  // Cas 3 : Tableau avec des éléments identiques
  int tab3[] = {5, 5, 5, 5, 5};
  taille = sizeof(tab3) / sizeof(tab3[0]);
  puts("\nTableau avec des éléments identiques :");
  afficherTab(tab3, taille);
  triRapide(tab3, 0, taille - 1);
  afficherTab(tab3, taille);

  // Cas 4 : Tableau vide
  int tab4[] = {};
  taille = sizeof(tab4) / sizeof(tab4[0]);
  puts("\nTableau vide :");
  afficherTab(tab4, taille);
  triRapide(tab4, 0, taille - 1);
  afficherTab(tab4, taille);

  // Cas 5 : Tableau avec un seul élément
  int tab5[] = {42};
  taille = sizeof(tab5) / sizeof(tab5[0]);
  puts("\nTableau avec un seul élément :");
  afficherTab(tab5, taille);
  triRapide(tab5, 0, taille - 1);
  afficherTab(tab5, taille);

  // Cas 6 : Tableau avec des éléments négatifs
  int tab6[] = {-3, -1, -7, -2, -9, -4};
  taille = sizeof(tab6) / sizeof(tab6[0]);
  puts("\nTableau avec des éléments négatifs :");
  afficherTab(tab6, taille);
  triRapide(tab6, 0, taille - 1);
  afficherTab(tab6, taille);

  // Cas 7 : Tableau avec des éléments mélangés (positifs et négatifs)
  int tab7[] = {0, -5, 3, -2, 8, -1, 7};
  taille = sizeof(tab7) / sizeof(tab7[0]);
  puts("\nTableau avec des éléments mélangés (positifs et négatifs) :");
  afficherTab(tab7, taille);
  triRapide(tab7, 0, taille - 1);
  afficherTab(tab7, taille);

  return 0;
}
