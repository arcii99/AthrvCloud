//FormAI DATASET v1.0 Category: File Encyptor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 512

void encryptFile(char *fileName, char *key);
void decryptFile(char *fileName, char *key);

int main(int argc, char *argv[]) {
    // check if proper number of command line arguments are given
    if (argc != 4) {
        printf("Usage: %s <option:e/d> <input_file_name> <key>\n", argv[0]);
        return 1; // return error code 1
    }

    char *option = argv[1];
    char *fileName = argv[2];
    char *key = argv[3];

    if (strcmp(option, "-e") == 0) {
        encryptFile(fileName, key);
    } else if (strcmp(option, "-d") == 0) {
        decryptFile(fileName, key);
    } else {
        printf("Invalid option: %s\n", option);
        return 1; // return error code 1
    }

    return 0; // return success code 0
}

void encryptFile(char *fileName, char *key) {
    FILE *fileIn, *fileOut;
    unsigned char buffer[MAX_FILE_SIZE];
    int bytesRead, i;
    unsigned char keyChar;
    size_t keyIndex = 0;
    char *encryptedName = malloc(strlen(fileName) + 5); // memory allocation for encrypted file name
    strcpy(encryptedName, fileName);
    strcat(encryptedName, ".enc");

    printf("Encrypting file %s with key %s\n", fileName, key);

    fileIn = fopen(fileName, "rb");
    fileOut = fopen(encryptedName, "wb");

    while ((bytesRead = fread(buffer, sizeof(unsigned char), MAX_FILE_SIZE, fileIn)) > 0) {
        for (i = 0; i < bytesRead; i++) {
            keyChar = key[keyIndex % strlen(key)];
            buffer[i] = buffer[i] ^ keyChar;
            keyIndex++;
        }

        fwrite(buffer, sizeof(char), bytesRead, fileOut);
    }

    fclose(fileIn);
    fclose(fileOut);

    printf("File %s encrypted successfully, saved as %s\n", fileName, encryptedName);
}

void decryptFile(char *fileName, char *key) {
    FILE *fileIn, *fileOut;
    unsigned char buffer[MAX_FILE_SIZE];
    int bytesRead, i;
    unsigned char keyChar;
    size_t keyIndex = 0;
    char *decryptedName = malloc(strlen(fileName) - 4); // memory allocation for decrypted file name
    strncpy(decryptedName, fileName, strlen(fileName) - 4);
    decryptedName[strlen(fileName) - 4] = '\0';

    printf("Decrypting file %s with key %s\n", fileName, key);

    fileIn = fopen(fileName, "rb");
    fileOut = fopen(decryptedName, "wb");

    while ((bytesRead = fread(buffer, sizeof(unsigned char), MAX_FILE_SIZE, fileIn)) > 0) {
        for (i = 0; i < bytesRead; i++) {
            keyChar = key[keyIndex % strlen(key)];
            buffer[i] = buffer[i] ^ keyChar;
            keyIndex++;
        }

        fwrite(buffer, sizeof(unsigned char), bytesRead, fileOut);
    }

    fclose(fileIn);
    fclose(fileOut);

    printf("File %s decrypted successfully, saved as %s\n", fileName, decryptedName);
}