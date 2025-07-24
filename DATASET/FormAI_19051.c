//FormAI DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char *inputFile, char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");
    if (in == NULL || out == NULL) {
        printf("Unable to read input/output files!");
        return;
    }

    int level = 0; // level of indentation
    char ch;
    while ((ch = fgetc(in)) != EOF) {
        if (ch == '<') {
            fputc('\n', out);
            for (int i = 0; i < level; i++) {
                fputc('\t', out);
            }
            fputc(ch, out);
            level++;
        } else if (ch == '>') {
            fputc(ch, out);
            level--;
        } else {
            fputc(ch, out);
        }
    }
    fclose(in);
    fclose(out);
}

int main() {
    char inputFile[100], outputFile[100];
    printf("Enter the input file name: ");
    scanf("%s", inputFile);
    printf("Enter the output file name: ");
    scanf("%s", outputFile);
    beautify(inputFile, outputFile);
    printf("Beautification successful!");
    return 0;
}