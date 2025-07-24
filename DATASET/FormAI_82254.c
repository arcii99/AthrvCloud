//FormAI DATASET v1.0 Category: File Encyptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(FILE *inputFile, FILE *outputFile, char *key) {
    int c, i = 0;
    size_t keylen = strlen(key);
    while ((c = fgetc(inputFile)) != EOF) {
        fputc(c ^ key[i++ % keylen], outputFile);
    }
}

int main(int argc, char *argv[]) {
    FILE *inputFile = NULL, *outputFile = NULL;
    char key[100], inputFileName[100], outputFileName[100];

    // Input file name
    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(EXIT_FAILURE);
    }

    // Output file name
    printf("Enter output file name: ");
    scanf("%s", outputFileName);
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: Unable to open output file.\n");
        exit(EXIT_FAILURE);
    }

    // Encryption key
    printf("Enter encryption key (max 100 characters): ");
    scanf("%s", key);

    // Encrypt file
    printf("Encrypting file...\n");
    encrypt(inputFile, outputFile, key);
    printf("File encrypted and saved as %s.\n", outputFileName);

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}