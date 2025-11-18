#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct NoeudStr {
  char* url;
  struct NoeudStr* suivant;
} NoeudStr;

typedef struct {
  NoeudStr* sommet;
} Pile;


void aller(NoeudStr** pile, const char* url) {
  NoeudStr* nouveau = malloc(sizeof(NoeudStr));
  nouveau->url = strdup(url);
  nouveau->suivant = *pile;
  *pile = nouveau;
}


char* revenir(NoeudStr** pile) {
  if (*pile == NULL) return NULL;
  NoeudStr* temp = *pile;
  *pile = (*pile)->suivant;
  char* url = temp->url;
  free(temp);
  return url;
}

void afficheUrl(NoeudStr* pile) {
  printf("Historique de navigation :\n");
  while (pile) {
    printf(" - %s\n", pile->url);
    pile = pile->suivant;
  }
}

void nettoieHistorique(NoeudStr* pile) {
  while (pile) {
    NoeudStr* temp = pile;
    pile = pile->suivant;
    free(temp->url);
    free(temp);
  }
}




int main() {
  puts("Début de navigation");

  NoeudStr* navigateur = {NULL};
  afficheUrl(navigateur);

  puts("\nSimulation de navigation");
  char urls[][128] = {"https://www.qwant.com", "https://www.framasoft.org",
                      "https://www.stackoverflow.com"};
  for (int i = 0; i < 3; i++) {
    char* url = urls[i];
    printf("Navigation vers; %s\n", url);
    aller(&navigateur, url);
    afficheUrl(navigateur);
  }

  puts("\nRetour en arrière");
  printf("Dépile %s\n", revenir(&navigateur));
  afficheUrl(navigateur);

  puts("\nNaviguer vers une nouvelle page");
  aller(&navigateur, "https://www.wikipedia.org");
  afficheUrl(navigateur);  // Affiche wikipedia

  // Libération
  puts("\nNettoyage de la mémoire dynamique\n");
  nettoieHistorique(navigateur);
  return 0;
}
