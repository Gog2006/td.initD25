/* Implementation of the simple todo functions used by main.c
 * - ajouterTache: append a new task line to todo.txt
 * - listerTaches: print non-completed tasks with their line number
 * - marquerTerminee: prefix the specified line with "x YYYY-MM-DD "
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "taches.h"

#define TODO_FILE "todo.txt"
#define MAX_LINE 1024

void ajouterTache(const char *description) {
    FILE *f = fopen(TODO_FILE, "a");
    if (!f) {
        perror("fopen");
        return;
    }
    fprintf(f, "%s\n", description);
    fclose(f);
}

void listerTaches(void) {
    FILE *f = fopen(TODO_FILE, "r");
    if (!f) return; /* no file -> nothing to list */
    char line[MAX_LINE];
    int lineno = 1;
    while (fgets(line, sizeof line, f)) {
        size_t len = strlen(line);
        if (len && line[len-1] == '\n') line[len-1] = '\0';
        if (strncmp(line, "x ", 2) != 0) {
            printf("%d %s\n", lineno, line);
        }
        lineno++;
    }
    fclose(f);
}

void marquerTerminee(int id) {
    FILE *f = fopen(TODO_FILE, "r");
    if (!f) return;
    char **lines = NULL;
    size_t n = 0;
    char buf[MAX_LINE];
    while (fgets(buf, sizeof buf, f)) {
        char *dup = strdup(buf);
        if (!dup) break;
        char **tmp = realloc(lines, (n+1) * sizeof *lines);
        if (!tmp) { free(dup); break; }
        lines = tmp;
        lines[n++] = dup;
    }
    fclose(f);

    if (id < 1 || id > (int)n) {
        fprintf(stderr, "ID invalide\n");
        for (size_t i = 0; i < n; ++i) free(lines[i]);
        free(lines);
        return;
    }

    /* If already marked, do nothing */
    if (strncmp(lines[id-1], "x ", 2) != 0) {
        /* remove trailing newline */
        size_t origlen = strlen(lines[id-1]);
        if (origlen && lines[id-1][origlen-1] == '\n') lines[id-1][origlen-1] = '\0';

        /* date */
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        char date[11];
        strftime(date, sizeof date, "%Y-%m-%d", &tm);

        size_t newlen = strlen("x ") + strlen(date) + 1 + strlen(lines[id-1]) + 2;
        char *newl = malloc(newlen);
        if (newl) {
            snprintf(newl, newlen, "x %s %s\n", date, lines[id-1]);
            free(lines[id-1]);
            lines[id-1] = newl;
        }
    }

    f = fopen(TODO_FILE, "w");
    if (!f) {
        perror("fopen");
        for (size_t i = 0; i < n; ++i) free(lines[i]);
        free(lines);
        return;
    }
    for (size_t i = 0; i < n; ++i) {
        fputs(lines[i], f);
        /* ensure newline */
        size_t L = strlen(lines[i]);
        if (L == 0 || lines[i][L-1] != '\n') fputc('\n', f);
        free(lines[i]);
    }
    free(lines);
    fclose(f);
}
