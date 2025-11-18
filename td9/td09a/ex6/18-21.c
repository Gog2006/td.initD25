#include <stdio.h>
#include <string.h>

typedef enum {
  FORCE,
  VITESSE,
  INTELLIGENCE
} TypePouvoir;

typedef union {
  int force;
  float vitesse;
  int intelligence;
} Pouvoir;

typedef struct {
  char nom[50];
  TypePouvoir typePouvoir;
  Pouvoir pouvoir;
} SuperHeros;

void afficherSuperHeros(SuperHeros heros) {
  printf("Nom: %s\n", heros.nom);
  
  switch (heros.typePouvoir) {
    case FORCE:
      printf("Force: %d\n", heros.pouvoir.force);
      break;
    case VITESSE:
      printf("Vitesse: %f\n", heros.pouvoir.vitesse);
      break;
    case INTELLIGENCE:
      printf("Intelligence: %d\n", heros.pouvoir.intelligence);
      break;
    default:
      printf("Type de pouvoir inconnu\n");
  }
}

int main() {
  SuperHeros superman;
  strcpy(superman.nom, "Superman");
  superman.typePouvoir = FORCE;
  superman.pouvoir.force = 100;
  afficherSuperHeros(superman);
  
  SuperHeros flash;
  strcpy(flash.nom, "Flash");
  flash.typePouvoir = VITESSE;
  flash.pouvoir.vitesse = 99.9;
  afficherSuperHeros(flash);
  
  SuperHeros batman;
  strcpy(batman.nom, "Batman");
  batman.typePouvoir = INTELLIGENCE;
  batman.pouvoir.intelligence = 150;
  afficherSuperHeros(batman);
  
  return 0;
}
