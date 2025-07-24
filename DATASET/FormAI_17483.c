//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void beautifyHTML(FILE *fp_in, FILE *fp_out) {
    char c, next_c;
    short int indent = 0;
    while ((c = fgetc(fp_in)) != EOF) {
        if (c == '<') {
            next_c = fgetc(fp_in);
            if (next_c == '/')
                indent--;
            if (indent > 0)
                fprintf(fp_out, "\n");
            fprintf(fp_out, "%c%c", c, next_c);
            indent++;
        }
        else if (c == '>') {
            fprintf(fp_out, "%c\n", c);
        }
        else {
            fprintf(fp_out, "%c", c);
        }
    }
}

int main() {
    FILE *fp_in, *fp_out;

    fp_in = fopen("input.html", "r");
    if (fp_in == NULL) {
        printf("Cannot open input.html\n");
        exit(EXIT_FAILURE);
    }

    fp_out = fopen("output.html", "w");
    if (fp_out == NULL) {
        printf("Cannot open output.html\n");
        exit(EXIT_FAILURE);
    }

    beautifyHTML(fp_in, fp_out);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}