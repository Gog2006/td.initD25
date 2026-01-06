#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* fichier = fopen("exemple.txt", "r");
  if (fichier == NULL) {
    perror("Erreur lors de l'ouverture du fichier");
    return 1;
  }
  char buffer[256];
  while (fgets(buffer, sizeof(buffer), fichier) != NULL) {
    printf("%s", buffer);
  }
  fclose(fichier);
  return 0;
}