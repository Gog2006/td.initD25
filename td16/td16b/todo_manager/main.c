#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/taches.h"


int main(int argc, char* argv[]) {
  if ((argc < 2) || (argc > 3)) {
    fprintf(stderr, "Utilisation : %s <commande> [arguments]\n", argv[0]);
    fprintf(stderr, "Commandes :\n");
    fprintf(stderr, "  add \"tâche\" - Ajouter une nouvelle tâche\n");
    fprintf(stderr, "  list       - Lister les tâches en attente\n");
    fprintf(stderr, "  do <id>    - Marquer une tâche comme terminée\n");
    return 1;
  }

  if (strcmp(argv[1], "add") == 0 && argc == 3) {
    ajouterTache(argv[2]);
  } else if (strcmp(argv[1], "list") == 0 && argc == 2) {
    listerTaches();
  } else if (strcmp(argv[1], "do") == 0 && argc == 3) {
    marquerTerminee(atoi(argv[2]));
  } else {
    fprintf(stderr, "Commande invalide\n");
    return 1;
  }

  return 0;
}
