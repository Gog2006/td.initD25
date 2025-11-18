#include <stdio.h>
typedef struct {
  int lat;
  int lon;
} Coordonnees;


Coordonnees goSouthEast(Coordonnees position) {
  position.lat = position.lat - 1;  // Décrémente la latitude
  position.lon = position.lon + 1;  // Incrémente la longitude
  return position; 
}

int main() {
  Coordonnees position = {43, 7};
  printf("Coordonnées initiales: (%d, %d)\n", position.lat, position.lon);
 
  position = goSouthEast(position);
  printf("Coordonnées finales  : (%d, %d)\n", position.lat, position.lon);
  return 0;
}