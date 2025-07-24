//FormAI DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void encrypt(char *filename, char *key) {
    FILE *file;
    int key_length = strlen(key);
    int i = 0;

    file = fopen(filename, "r+");
    if(file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char c;
    while((c = getc(file)) != EOF) {
        putc(c ^ key[i], file);
        i = (i+1) % key_length;
    }

    fclose(file);
}

void decrypt(char *filename, char *key) {
    FILE *file;
    int key_length = strlen(key);
    int i = 0;

    file = fopen(filename, "r+");
    if(file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char c;
    while((c = getc(file)) != EOF) {
        putc(c ^ key[i], file);
        i = (i+1) % key_length;
    }

    fclose(file);
}

int main() {
    char* filename = "example.txt";
    char* key = "secret";

    // encrypt file
    encrypt(filename, key);
    printf("File encrypted successfully\n");

    // decrypt file
    decrypt(filename, key);
    printf("File decrypted successfully\n");

    return 0;
}