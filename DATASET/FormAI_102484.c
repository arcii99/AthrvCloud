//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void encryptDecrypt(char *inputFile, char *outputFile, char *key) {
    uint8_t len = strlen(key);

    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "wb");

    int readChar;
    uint8_t count = 0;

    while((readChar = fgetc(input)) != EOF) {
        fputc(readChar ^ key[count], output);
        count++;
        if(count >= len) {
            count = 0;
        }
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("usage: ./crypto inputFile outputFile key\n");
        printf("\tinputFile: the file to encrypt/decrypt\n");
        printf("\toutputFile: the output file name\n");
        printf("\tkey: the key to use in encryption/decryption\n");
        exit(1);
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];
    char *key = argv[3];

    encryptDecrypt(inputFile, outputFile, key);

    return 0;
}