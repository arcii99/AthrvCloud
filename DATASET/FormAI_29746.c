//FormAI DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *filePath) {
    FILE *file = fopen(filePath, "rb+");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        fseek(file, 0, SEEK_SET);
        char *buffer = (char*) malloc(size + 1);
        
        fread(buffer, size, 1, file);
        rewind(file);
        int i;
        for (i = 0; i < size; i++) {
            buffer[i] ^= 0xff;
        }
        fwrite(buffer, size, 1, file);
        free(buffer);
        fclose(file);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char *path = argv[1];
    char *encPath = malloc(strlen(path) + 5);
    strcpy(encPath, path);
    strcat(encPath, ".enc");

    FILE *file = fopen(encPath, "r");
    if (file != NULL) {
        printf("Encrypted file already exists!\n");
        fclose(file);
        free(encPath);
        return 1;
    }

    encrypt(path);
    printf("File %s encrypted to %s\n", path, encPath);
    free(encPath);
    return 0;
}