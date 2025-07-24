//FormAI DATASET v1.0 Category: HTML beautifier ; Style: enthusiastic
#include<stdio.h>

int main() {

    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50], c;

    printf("Enter the name of HTML file to beautify: ");
    scanf("%s", inputFileName);

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open file!\n");
        return 1;
    }

    printf("Enter the name of output file: ");
    scanf("%s", outputFileName);

    outputFile = fopen(outputFileName, "w");

    if (outputFile == NULL) {
        printf("Error: Unable to open file!\n");
        return 1;
    }

    int indentCount = 0;
    while ((c = fgetc(inputFile)) != EOF) {

        if (c == '\n') {
            fputc(c, outputFile);
            putIndent(indentCount, outputFile);

        } else if (c == '<') {
            indentCount++;
            fputc(c, outputFile);
            if (fgetc(inputFile) != '/') {
                fputc('\n', outputFile);
                putIndent(indentCount, outputFile);
            }
            ungetc(c, inputFile);

        } else if (c == '>') {
            fputc(c, outputFile);
            fputc('\n', outputFile);
            ungetc(c, inputFile);
            indentCount--;

            if (fgetc(inputFile) == '<') {
                ungetc('<', inputFile);
            }
            putIndent(indentCount, outputFile);

        } else {
            fputc(c, outputFile);

        }
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Beautified HTML written to %s.\n", outputFileName);
    return 0;
}

void putIndent(int count, FILE *output) {

    for (int i = 0; i < count; i++) {
        fprintf(output, "\t");
    }
}