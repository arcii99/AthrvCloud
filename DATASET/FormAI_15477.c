//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Open input file for reading
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file '%s'\n", argv[1]);
        return 1;
    }

    // Open output file for writing
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file '%s'\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    // Allocate memory buffer for reading input
    int buffer_size = 1024;
    char *buffer = malloc(buffer_size * sizeof(char));

    // Read input file and convert to ASCII art
    while (!feof(input_file)) {
        int bytes_read = fread(buffer, sizeof(char), buffer_size, input_file);
        for (int i = 0; i < bytes_read; i++) {
            // Convert byte (0-255) to ASCII character (32-127)
            char ascii_char = buffer[i] * 0.4 + 32;

            // Write ASCII character to output file
            fprintf(output_file, "%c", ascii_char);
        }
    }

    // Clean up resources
    fclose(input_file);
    fclose(output_file);
    free(buffer);

    return 0;
}