//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to perform encryption
void encrypt(char *inputFilePath, char *outputFilePath, char key) {
    FILE *inputFile, *outputFile;
    char ch;

    inputFile = fopen(inputFilePath, "r");
    outputFile = fopen(outputFilePath, "w");

    if(!inputFile) {
        printf("Error opening input file\n");
        exit(1);
    }

    if(!outputFile) {
        printf("Error opening output file\n");
        exit(1);
    }

    while((ch = fgetc(inputFile)) != EOF) {
        // perform encryption
        if(ch != '\n')
            ch = ch + key;

        fputc(ch, outputFile);
    }

    printf("Encryption complete\n");

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    char inputFilePath[100], outputFilePath[100], key;
    printf("Enter input file path: ");
    scanf("%s", inputFilePath);
    printf("Enter output file path: ");
    scanf("%s", outputFilePath);
    printf("Enter key (integer): ");
    scanf("%d", &key);

    encrypt(inputFilePath, outputFilePath, key);

    return 0;
}