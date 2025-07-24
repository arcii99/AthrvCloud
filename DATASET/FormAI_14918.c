//FormAI DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define input and output file names
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

int main() {
    // Open input file for reading
    FILE *input_file = fopen(INPUT_FILE, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: could not open input file.\n");
        exit(1);
    }

    // Open output file for writing
    FILE *output_file = fopen(OUTPUT_FILE, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: could not open output file.\n");
        exit(1);
    }

    // Read data from input file and write result to output file
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_file) != NULL) {
        // Calculate length of line
        int length = strlen(buffer);

        // Reverse the line
        for (int i = 0; i < length / 2; i++) {
            char temp = buffer[i];
            buffer[i] = buffer[length - i - 1];
            buffer[length - i - 1] = temp;
        }

        // Write the reversed line to the output file
        fputs(buffer, output_file);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}