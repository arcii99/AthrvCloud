//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(char* inputFilename, char* outputFilename, char* key) {
    FILE* inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Cannot open input file: %s\n", inputFilename);
        exit(EXIT_FAILURE);
    }

    FILE* outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Cannot open output file: %s\n", outputFilename);
        exit(EXIT_FAILURE);
    }

    int keyLength = strlen(key);
    int keyIndex = 0;

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, inputFile)) {
        int bufferLength = strlen(buffer);
        for (int i = 0; i < bufferLength; i++) {
            fputc(buffer[i] ^ key[keyIndex], outputFile);
            keyIndex = (keyIndex + 1) % keyLength;
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    char* key = "mysecretpassword";
    encrypt("input.txt", "output.txt", key);
    printf("Encryption completed successfully!\n");
    return 0;
}