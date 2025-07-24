//FormAI DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (!input) {
        printf("ERROR: Could not open input file %s\n", argv[1]);
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (!output) {
        printf("ERROR: Could not open output file %s\n", argv[2]);
        fclose(input);
        return 1;
    }

    // Generate a random key
    unsigned char key = rand() % 256;

    // Write the key to the beginning of the output file
    fwrite(&key, sizeof(key), 1, output);

    // Encrypt the input file and write it to the output file
    unsigned char buffer[BUFFER_SIZE];
    size_t size;
    while ((size = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input)) > 0) {
        for (int i = 0; i < size; i++) {
            buffer[i] ^= key;
        }
        fwrite(buffer, sizeof(unsigned char), size, output);
    }

    fclose(input);
    fclose(output);
    return 0;
}