//FormAI DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 128

void compress(char *input_file_name, char *output_file_name) {
    FILE *input_file = fopen(input_file_name, "rb");
    FILE *output_file = fopen(output_file_name, "wb");

    // Allocate memory for chunk buffer.
    char *chunk = (char *)malloc(sizeof(char) * CHUNK_SIZE);

    // Initialize previous character and previous count.
    char prev_char = fgetc(input_file);
    int prev_count = 1;

    while (1) {
        char curr_char = fgetc(input_file);

        if (feof(input_file)) {
            // End of file reached; write remaining data to output file.
            fwrite(&prev_count, sizeof(int), 1, output_file);
            fwrite(&prev_char, sizeof(char), 1, output_file);
            break;
        }

        if (curr_char == prev_char && prev_count < 255) {
            // Same character as previous; increase count.
            prev_count++;
        } else {
            // Different character as previous; write previous chunk to output file.
            fwrite(&prev_count, sizeof(int), 1, output_file);
            fwrite(&prev_char, sizeof(char), 1, output_file);

            // Reset previous character and count.
            prev_char = curr_char;
            prev_count = 1;
        }
    }

    fclose(input_file);
    fclose(output_file);
    free(chunk);
}

void decompress(char *input_file_name, char *output_file_name) {
    FILE *input_file = fopen(input_file_name, "rb");
    FILE *output_file = fopen(output_file_name, "wb");

    while (1) {
        int count;
        char c;

        fread(&count, sizeof(int), 1, input_file);
        fread(&c, sizeof(char), 1, input_file);

        if (feof(input_file)) {
            // End of file reached.
            break;
        }

        // Write character count times to output file.
        for (int i = 0; i < count; i++) {
            fwrite(&c, sizeof(char), 1, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    char *input_file_name = "input.txt";
    char *compressed_file_name = "compressed.cmp";
    char *decompressed_file_name = "decompressed.txt";

    // Compress input file.
    compress(input_file_name, compressed_file_name);

    // Decompress compressed file.
    decompress(compressed_file_name, decompressed_file_name);

    return 0;
}