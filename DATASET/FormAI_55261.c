//FormAI DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define ENCRYPTION_KEY 12

void encryptFile(char* fileName) {
    FILE* file = fopen(fileName, "rb+");
    if (!file) {
        printf("Could not open file %s\n", fileName);
        return;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    // Read file data into buffer
    unsigned char* buffer = (unsigned char*) malloc(fileSize);
    fread(buffer, sizeof(unsigned char), fileSize, file);

    // Encrypt the data
    for (int i = 0; i < fileSize; i++) {
        buffer[i] ^= ENCRYPTION_KEY;
    }

    // Write encrypted data back to file
    rewind(file);
    fwrite(buffer, sizeof(unsigned char), fileSize, file);

    fclose(file);
    free(buffer);
}

int main() {
    char fileName[MAX_FILENAME_LENGTH];
    printf("Enter file name: ");
    fgets(fileName, MAX_FILENAME_LENGTH, stdin);
    fileName[strcspn(fileName, "\n")] = '\0'; // Remove newline character

    encryptFile(fileName);

    printf("Encryption done!\n");

    return 0;
}