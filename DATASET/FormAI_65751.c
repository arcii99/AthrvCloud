//FormAI DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

// Function to encrypt a file
void encryptFile(FILE *fp, char *key) {
    char line[MAX_STRING_LENGTH];
    int i = 0;

    while (fgets(line, MAX_STRING_LENGTH, fp)) {
        for (i = 0; i < strlen(line); i++) {
            line[i] ^= key[i % strlen(key)];
        }

        printf("%s", line);
    }
}

int main(int argc, char *argv[]) {
    // Check if the user has provided the required arguments
    if (argc != 3) {
        printf("\nOops! You forgot to provide the file path and the encryption key!\n\n");
        printf("Usage: %s <file path> <encryption key>\n\n", argv[0]);
        return 1;
    }

    // Open the file to be encrypted
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("\nOops! Unable to open the file!\n\n");
        return 1;
    }

    // Encrypt the file
    printf("\nEncrypting file \"%s\"...\n\n", argv[1]);
    encryptFile(fp, argv[2]);

    // Close the file
    fclose(fp);

    // Let the user know that the file has been encrypted
    printf("\nFile \"%s\" has been encrypted with key \"%s\"!\n\n", argv[1], argv[2]);

    return 0;
}