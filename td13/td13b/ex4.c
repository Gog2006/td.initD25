#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


unsigned fibRec(unsigned n) {
  if (n <= 1) 
  return n;
  return fibRec(n - 1) + fibRec(n - 2);
}


unsigned _fibRecMemo(unsigned n, unsigned memo[]) {
  if (memo[n] != UINT_MAX) return memo[n];
  if (n <= 1) {
    memo[n] = n;
    return n;
  }
  unsigned a = _fibRecMemo(n - 1, memo);
  unsigned b = _fibRecMemo(n - 2, memo);
  memo[n] = a + b;
  return memo[n];
}

unsigned fibRecMemo(unsigned n) {

  unsigned *memo = malloc((n + 1) * sizeof(unsigned));
  if (!memo) {
    fprintf(stderr, "Allocation mémoire échouée\n");
    exit(EXIT_FAILURE);
  }
  for (unsigned i = 0; i <= n; ++i) memo[i] = UINT_MAX;
  memo[0] = 0;
  if (n >= 1) memo[1] = 1;
  unsigned res = _fibRecMemo(n, memo);
  free(memo);
  return res;
}

int main() {
  unsigned n = 39;
  clock_t debut, fin;
  double duree;

  printf("Calcul de fibonacci(%d)\n", n);

  debut = clock();
  unsigned res = fibRec(n);
  fin = clock();
  duree = ((double)(fin - debut)) / CLOCKS_PER_SEC;
  printf("Version naïve: %u (temps: %f secondes)\n", res, duree);

  debut = clock();
  unsigned resMemo = fibRecMemo(n);
  fin = clock();
  duree = ((double)(fin - debut)) / CLOCKS_PER_SEC;
  printf("Version mémoïsation: %u (temps: %f secondes)\n", resMemo, duree);

  return 0;
}