//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define Constants
#define MAX_FILENAME_LENGTH 100
#define MAX_FILESIZE        100000

// Define Functions
void encrypt(char *str);
void decrypt(char *str);
int fileExists(char *filename);

int main(int argc, char **argv) {

    // Check if we got enough arguments
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        exit(1);
    }

    // Get File Names
    char *file1 = argv[1];
    char *file2 = argv[2];

    // Check if Files Exist
    if (!fileExists(file1)) {
        printf("File doesn't exist: %s\n", file1);
        exit(1);
    }
    if (!fileExists(file2)) {
        printf("File doesn't exist: %s\n", file2);
        exit(1);
    }

    // Read File 1 contents
    FILE *f1 = fopen(file1, "r");
    char *content1 = malloc(MAX_FILESIZE * sizeof(char));
    memset(content1, 0, MAX_FILESIZE * sizeof(char));
    fread(content1, MAX_FILESIZE, sizeof(char), f1);

    // Read File 2 contents
    FILE *f2 = fopen(file2, "r");
    char *content2 = malloc(MAX_FILESIZE * sizeof(char));
    memset(content2, 0, MAX_FILESIZE * sizeof(char));
    fread(content2, MAX_FILESIZE, sizeof(char), f2);

    // Encrypt File 1 Contents
    encrypt(content1);

    // Encrypt File 2 Contents
    encrypt(content2);

    // Compare File Contents
    if (strcmp(content1, content2) == 0) {
        printf("Files are synchronized.\n");
    } else {
        printf("Files are not synchronized.\n");
    }

    // Free Memory
    free(content1);
    free(content2);

    // Close Files
    fclose(f1);
    fclose(f2);

    return 0;
}

void encrypt(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] ^= 0xFF;
    }
}

void decrypt(char *str) {
    encrypt(str);
}

int fileExists(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}