//FormAI DATASET v1.0 Category: File Encyptor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0x53

void encrypt(char *filename) {
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *) calloc(size, sizeof(char));
    fread(buffer, sizeof(char), size, file);

    for (int i = 0; i < size; i++) {
        buffer[i] ^= KEY;
    }

    fseek(file, 0, SEEK_SET);
    fwrite(buffer, sizeof(char), size, file);

    free(buffer);
    fclose(file);
}

void prompt() {
    char filename[256];

    printf("Enter a filename to encrypt: ");
    scanf("%s", filename);

    encrypt(filename);
    printf("File '%s' encrypted successfully!\n", filename);
}

int main() {
    prompt();
    return 0;
}