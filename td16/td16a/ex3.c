#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *inname = "image.png";
    const char *outname = "image_copy.png";

    if (argc >= 2) inname = argv[1];
    if (argc >= 3) outname = argv[2];

    FILE *in = fopen(inname, "rb");
    if (!in) {
        perror("Erreur lors de l'ouverture du fichier d'entree");
        return 1;
    }

    FILE *out = fopen(outname, "wb");
    if (!out) {
        perror("Erreur lors de l'ouverture du fichier de sortie");
        fclose(in);
        return 2;
    }

    /* tampon de 4 KiO */
    unsigned char buffer[4096];
    size_t nread;

    while ((nread = fread(buffer, 1, sizeof(buffer), in)) > 0) {
        size_t nwritten = fwrite(buffer, 1, nread, out);
        if (nwritten != nread) {
            perror("Erreur d'ecriture");
            fclose(in);
            fclose(out);
            return 3;
        }
    }

    if (ferror(in)) {
        perror("Erreur lors de la lecture");
        fclose(in);
        fclose(out);
        return 4;
    }

    fclose(in);
    fclose(out);

    printf("Copie binaire terminée avec succès.\n");
    return 0;
}
