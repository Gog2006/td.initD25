#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Nom du fichier où sont stockées les grilles */
#define SUDOKU_FILE "sudokus.txt"

/* Longueur d'une grille (81 chiffres) + 1 pour le \0 */
#define GRID_SIZE 82
/* Nombre de chiffres attendus */
#define GRID_LEN 81

static bool estValide(const char *grille) {
    if (grille == NULL) return false;
    if ((int)strlen(grille) != GRID_LEN) return false;
    for (int i = 0; i < GRID_LEN; ++i) {
        if (grille[i] < '0' || grille[i] > '9') return false;
    }
    return true;
}

static bool estDejaFaite(const char *grille) {
    FILE *f = fopen(SUDOKU_FILE, "r");
    if (!f) {
        /* Si le fichier n'existe pas, alors la grille ne peut pas être déjà présente */
        return false;
    }
    char line[GRID_SIZE];
    while (fgets(line, sizeof(line), f)) {
        /* retirer le \n éventuel */
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';
        if (strcmp(line, grille) == 0) {
            fclose(f);
            return true;
        }
    }
    fclose(f);
    return false;
}

static int ajouterSudoku(const char *grille) {
    FILE *f = fopen(SUDOKU_FILE, "a");
    if (!f) return -1;
    fprintf(f, "%s\n", grille);
    fclose(f);
    return 0;
}

int main(void) {
    /* crée le fichier s'il n'existe pas sans l'effacer grâce au mode "a" */
    FILE* f = fopen(SUDOKU_FILE, "a");
    if (f == NULL) {
        perror("Problème lors de l'ouverture du fichier");
        exit(1);
    }
    fclose(f);

    /* boucle principale */
    while (true) {
        char grille[GRID_SIZE] = "";
        printf("\nEntrez une grille de sudoku (ou STOP pour arrêter): ");

        if (scanf("%81s", grille) != 1) {
            /* EOF ou erreur */
            clearerr(stdin);
            break;
        }

        /* arrêt si STOP */
        if (strcmp(grille, "STOP") == 0) break;

        if (!estValide(grille)) {
            puts("\t:( La grille est invalide!\n\t\tune grille doit contenir exactement 81 chiffres");
        } else if (estDejaFaite(grille)) {
            puts("\t:( La grille a déjà été faite");
        } else {
            if (ajouterSudoku(grille) == 0) {
                puts("\t:) Grille ajoutée avec succès");
            } else {
                puts("\t:( Erreur lors de l'ajout de la grille");
            }
        }
    }

    printf("\n\tMerci, les nouvelles grilles ont été ajoutées au fichier %s\n", SUDOKU_FILE);
    return 0;
}