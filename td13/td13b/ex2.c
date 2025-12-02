#include <stdio.h>

#include "../lib/tableaux.h"
#include "../lib/utils.h"

int partition(int tab[], int iMin, int iMax) {
  int iPivot = iMax;

  int i = iMin;
  while (iPivot > i) {
    if (tab[i] > tab[iPivot]) {
      permuteInt(&tab[i], &tab[iPivot]);
      iPivot--;
      permuteInt(&tab[i], &tab[iPivot]);
    } else
      i++;
    printf("i = %d iPivot = %d: ", i, iPivot);
    afficherTab(tab, iMax - iMin + 1);
  }
  return i;
}// cette function prend un tableau et deux indices et retourne l'indice du pivot après partitionnement 

int main() {
  int tab[] = {3, 8, 7, 1, 5};
  int taille = sizeof(tab) / sizeof(tab[0]);

  printf("Tableau initial:  ");
  afficherTab(tab, taille);

  printf("Partition renvoie: %d\n", partition(tab, 0, taille - 1));

  return 0;
}


