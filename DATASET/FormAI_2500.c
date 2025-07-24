//FormAI DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(char *inputFile, char *outputFile, char *key) {
    FILE *fileIn, *fileOut;
    char ch;
    int i, j = 0;
    int keyLen = strlen(key);
    fileIn = fopen(inputFile, "r");
    if (fileIn == NULL) {
        printf("Error opening input file!");
        exit(1);
    }
    fileOut = fopen(outputFile, "w");
    while ((ch = fgetc(fileIn)) != EOF) {
        fputc(ch ^ key[j], fileOut);
        j = (j+1)%keyLen;
    }
    fclose(fileIn);
    fclose(fileOut);
}

int main() {
    char inputFile[50], outputFile[50], key[50];
    printf("Enter the name of input file: ");
    scanf("%s", inputFile);
    printf("Enter the name of output file: ");
    scanf("%s", outputFile);
    printf("Enter the encryption key: ");
    scanf("%s", key);

    encryptFile(inputFile, outputFile, key);
    printf("File encrypted successfully!\n");
    return 0;
}