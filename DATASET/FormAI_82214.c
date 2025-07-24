//FormAI DATASET v1.0 Category: HTML beautifier ; Style: retro
#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *fp_in = fopen("input.html", "r");
    FILE *fp_out = fopen("output.html", "w");
    if (!fp_in) {
        printf("Error opening input file\n");
        return 1;
    }
    if (!fp_out) {
        printf("Error opening output file\n");
        return 1;
    }
    int indent = 0, ch;
    while ((ch = fgetc(fp_in)) != EOF) {
        switch (ch) {
            case '<':
                fputc(ch, fp_out);
                if (fgetc(fp_in) == '/') { // Closing Tag
                    indent -= 2;
                    fputc('\n', fp_out);
                    for (int i = 0; i < indent; i++) fputc(' ', fp_out);
                } else { // Opening Tag
                    fputc('\n', fp_out);
                    for (int i = 0; i < indent; i++) fputc(' ', fp_out);
                    indent += 2;
                }
                break;
            case '>':
                fputc(ch, fp_out);
                if (fgetc(fp_in) != '<') {
                    fputc('\n', fp_out);
                    for (int i = 0; i < indent; i++) fputc(' ', fp_out);
                }
                break;
            default:
                fputc(ch, fp_out);
                break;
        }
    }
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}