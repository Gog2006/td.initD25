 #include <stdio.h>
 #include <stdlib.h>

 int main() {
   int taille;
   printf("Entrez la taille du tableau : ");
   if (scanf("%d", &taille) != 1 || taille <= 0) {
     fprintf(stderr, "Erreur: taille invalide\n");
     return 1;
   }
   int *tableau = malloc(taille * sizeof *tableau);
   if (tableau == NULL) {
    fprintf(stderr, "Erreur: allocation mémoire échouée\n");
     return 1;
   }
   for (int i = 0; i < taille; i++) {
     printf("Entrez la valeur pour l'élément %d: \n", i);
     if (scanf("%d", &tableau[i]) != 1) {
       fprintf(stderr, "Erreur: valeur invalide\n");
       free(tableau);
       return 1;
     }
   }
   printf("{");
   for (int i = 0; i < taille; i++) {
     printf("%d", tableau[i]);
     if (i < taille - 1) {
       printf(", ");
     }
   }
   printf("}\n");
   free(tableau);

   return 0;
}