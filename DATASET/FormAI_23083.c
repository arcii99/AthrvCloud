//FormAI DATASET v1.0 Category: File Encyptor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encryptFile(char *fileName, char *key) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Unable to open file for encryption.");
        exit(1);
    }

    char *encryptedFileName = (char *)malloc(strlen(fileName) + 5);
    sprintf(encryptedFileName, "%s.enc", fileName);
    FILE *encryptedFile = fopen(encryptedFileName, "wb");
    if (encryptedFile == NULL) {
        printf("Unable to create encrypted file.");
        exit(1);
    }

    size_t keyLength = strlen(key);
    char *buffer = (char *)malloc(BUFFER_SIZE);
    size_t bytesRead = 0;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % keyLength];
        }
        fwrite(buffer, 1, bytesRead, encryptedFile);
    }

    free(buffer);
    free(encryptedFileName);
    fclose(file);
    fclose(encryptedFile);
}

void decryptFile(char *fileName, char *key) {
    FILE *encryptedFile = fopen(fileName, "rb");
    if (encryptedFile == NULL) {
        printf("Unable to open file for decryption.");
        exit(1);
    }

    char *decryptedFileName = (char *)malloc(strlen(fileName) - 4);
    strncpy(decryptedFileName, fileName, strlen(fileName) - 4);
    decryptedFileName[strlen(fileName) - 4] = '\0';
    FILE *decryptedFile = fopen(decryptedFileName, "wb");
    if (decryptedFile == NULL) {
        printf("Unable to create decrypted file.");
        exit(1);
    }

    size_t keyLength = strlen(key);
    char *buffer = (char *)malloc(BUFFER_SIZE);
    size_t bytesRead = 0;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, encryptedFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % keyLength];
        }
        fwrite(buffer, 1, bytesRead, decryptedFile);
    }

    free(buffer);
    free(decryptedFileName);
    fclose(encryptedFile);
    fclose(decryptedFile);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s {encrypt/decrypt} {filename} {key}\n", argv[0]);
        return 1;
    }

    char *fileName = argv[2];
    char *key = argv[3];

    if (strcmp(argv[1], "encrypt") == 0) {
        encryptFile(fileName, key);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decryptFile(fileName, key);
    } else {
        printf("Invalid command.\n");
        return 1;
    }

    return 0;
}