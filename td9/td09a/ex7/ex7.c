#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int numerateur;
  int denominateur;
} Rationnel;

int pgcd(int a, int b) {
  a = abs(a);
  b = abs(b);
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

void simplifierRationnel(Rationnel *r) {
  if (r->denominateur == 0) {
    return;
  }
  
  int diviseur = pgcd(r->numerateur, r->denominateur);
  r->numerateur /= diviseur;
  r->denominateur /= diviseur;
  
  if (r->denominateur < 0) {
    r->numerateur = -r->numerateur;
    r->denominateur = -r->denominateur;
  }
}

Rationnel lireRationnel() {
  Rationnel r;
  
  printf("  Entrez le numérateur (une entier): ");
  scanf("%d", &r.numerateur);
  
  do {
    printf("  Entrez le dénominateur (une entier != 0): ");
    scanf("%d", &r.denominateur);
    
    if (r.denominateur == 0) {
      printf("    <---- Le denominateur ( = 0) n'est pas valide >\n");
    }
  } while (r.denominateur == 0);
  
  simplifierRationnel(&r);
  
  return r;
}

Rationnel sommeRationnel(Rationnel r1, Rationnel r2) {
  Rationnel resultat;
  
  resultat.numerateur = r1.numerateur * r2.denominateur + r2.numerateur * r1.denominateur;
  resultat.denominateur = r1.denominateur * r2.denominateur;
  
  simplifierRationnel(&resultat);
  
  return resultat;
}

void afficherRationnel(Rationnel r) {
  printf("%d/%d", r.numerateur, r.denominateur);
}

int main() {
  Rationnel r1, r2, somme;
  
  printf("Lire le premier rationnel:\n");
  r1 = lireRationnel();
  afficherRationnel(r1);
  printf("\n");
  
  printf("Lire le deuxieme rationnel:\n");
  r2 = lireRationnel();
  afficherRationnel(r2);
  printf("\n");
  
  somme = sommeRationnel(r1, r2);
  
  printf("La somme des deux rationnels est:\n");
  printf("     ");
  afficherRationnel(r1);
  printf(" + ");
  afficherRationnel(r2);
  printf(" = ");
  afficherRationnel(somme);
  printf("\n");
  
  return 0;
}
