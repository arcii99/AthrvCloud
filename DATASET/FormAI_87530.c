//FormAI DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000

void encrypt(char* source, char* destination, char* key) {
    FILE* source_file = fopen(source, "r");
    FILE* destination_file = fopen(destination, "w");
    int key_length = strlen(key);
    int key_index = 0;

    if (source_file == NULL || destination_file == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    char c;

    while ((c = fgetc(source_file)) != EOF) {
        fputc(c ^ key[key_index], destination_file);
        key_index = ++key_index % key_length;
    }

    fclose(source_file);
    fclose(destination_file);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <source_file> <destination_file> <key>\n", argv[0]);
        exit(1);
    }

    char* source_file = argv[1];
    char* destination_file = argv[2];
    char* key = argv[3];

    if (strlen(key) == 0) {
        printf("Key must not be empty.\n");
        exit(1);
    }

    encrypt(source_file, destination_file, key);

    printf("Encryption complete.\n");

    return 0;
}