//FormAI DATASET v1.0 Category: File Encyptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(char* filename, char* key) {
    FILE* file = fopen(filename, "rb+");
    if (file == NULL) {
        printf("Failed to open %s\n", filename);
        return;
    }

    // Read original file content
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    rewind(file);
    char* originalContent = (char*) malloc(sizeof(char) * fileSize);
    fread(originalContent, sizeof(char), fileSize, file);

    // Generate key stream
    int keyLength = strlen(key);
    char* keyStream = (char*) malloc(sizeof(char) * fileSize);
    for (int i = 0; i < fileSize; i++) {
        keyStream[i] = key[i % keyLength];
    }

    // Encrypt file content using XOR
    for (int i = 0; i < fileSize; i++) {
        char originalByte = originalContent[i];
        char keyByte = keyStream[i];
        char encryptedByte = originalByte ^ keyByte;
        originalContent[i] = encryptedByte;
    }

    // Write encrypted content back to the file
    rewind(file);
    fwrite(originalContent, sizeof(char), fileSize, file);
    fflush(file);
    fclose(file);

    printf("Encryption successful for file %s!\n", filename);
}

int main(void) {
    char* filename = "example.txt";
    char* key = "secret";
    encryptFile(filename, key);
    return 0;
}