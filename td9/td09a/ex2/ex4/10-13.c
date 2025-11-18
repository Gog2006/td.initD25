#include <stdio.h>
#include <string.h>

typedef enum { VERROUILLE, DEVERROUILLE, ALARME, MAINTENANCE } etatSysteme;

void afficherEtat(etatSysteme etat) {
  switch (etat) {
    case VERROUILLE:
      printf("Le système est verrouillé\n");
      break;
    case DEVERROUILLE:
      printf("Le système est déverrouillé\n");
      break;
    case ALARME:
      printf("Le système est en alarme\n");
      break;
    case MAINTENANCE:
      printf("Le système est en maintenance\n");
      break;
    default:
      printf("État inconnu\n");
  }
}

void changerEtat(etatSysteme *etat) {
  // Passer à l'état suivant avec un cycle
  *etat = (*etat + 1) % 4;
}

int main() {
  etatSysteme etat = VERROUILLE;
  
  printf("État initial:\n");
  afficherEtat(etat);
  printf("\n");
  
  // Boucle pour changer l'état 5 fois
  for (int i = 0; i < 5; i++) {
    changerEtat(&etat);
    printf("Changement d'état %d:\n", i + 1);
    afficherEtat(etat);
    printf("\n");
  }

  return 0;
}