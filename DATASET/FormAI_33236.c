//FormAI DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *inputFile, char *outputFile);

int main() {
    char inputFile[50], outputFile[50];

    printf("Enter input file name: ");
    scanf("%s", inputFile);

    printf("Enter output file name: ");
    scanf("%s", outputFile);

    encrypt(inputFile, outputFile);

    printf("Encrpytion done!\n");

    return 0;
}

void encrypt(char *inputFile, char *outputFile) {
    FILE *fInput, *fOutput;
    char ch, key = 'C';

    fInput = fopen(inputFile, "r");
    if (fInput == NULL) {
        printf("Could not open file %s\n", inputFile);
        exit(EXIT_FAILURE);
    }

    fOutput = fopen(outputFile, "w");
    if (fOutput == NULL) {
        printf("Could not create file %s\n", outputFile);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fInput)) != EOF) {
        fputc(ch ^ key, fOutput);
    }

    fclose(fInput);
    fclose(fOutput);
}