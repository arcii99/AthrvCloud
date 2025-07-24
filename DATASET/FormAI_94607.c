//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    char *key = "secretkey"; // The encryption key

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Could not open input file: %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        printf("Could not open output file: %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    // Get the size of the input file
    fseek(input_file, 0L, SEEK_END);
    long int input_size = ftell(input_file);
    fseek(input_file, 0L, SEEK_SET);

    char *input_buffer = (char *)malloc(input_size);
    if (!input_buffer) {
        printf("Could not allocate memory for input buffer\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    // Read the input file into the buffer
    fread(input_buffer, 1, input_size, input_file);

    // Encrypt the buffer using the key
    for (int i = 0; i < input_size; i++) {
        input_buffer[i] ^= key[i % strlen(key)];
    }

    // Write the encrypted buffer to the output file
    fwrite(input_buffer, 1, input_size, output_file);

    // Cleanup
    free(input_buffer);
    fclose(input_file);
    fclose(output_file);

    printf("Encrypted %s to %s with key %s\n", argv[1], argv[2], key);

    return 0;
}