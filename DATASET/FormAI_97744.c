//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if the correct amount of arguments are given
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    // Open the input and output files
    FILE *input_file = fopen(argv[1], "rb");
    FILE *output_file = fopen(argv[2], "wb");

    // Check if the files opened correctly
    if (input_file == NULL || output_file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    // Create the encryption key by hashing the user-provided key
    char *key = argv[3];
    int key_length = strlen(key);
    int hash = 0;
    for (int i = 0; i < key_length; i++) {
        hash += key[i];
    }

    // Read the input file, encrypt each byte with the hash key, and write to output file
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] = buffer[i] ^ hash;
        }
        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    return 0;
}