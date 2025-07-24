//FormAI DATASET v1.0 Category: System administration ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: This program requires 2 arguments.\n");
        printf("Usage: ./puzzle <input_file> <output_file>\n");
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    // Check if input file exists and can be opened for reading
    FILE *in = fopen(input_file, "r");
    if (in == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    // Check if output file exists and can be opened for writing
    FILE *out = fopen(output_file, "w");
    if (out == NULL) {
        printf("Error: Unable to open output file.\n");
        fclose(in);
        return 1;
    }

    // Read input file and write count of characters to output file
    int count = 0;
    char c;
    while ((c = getc(in)) != EOF) {
        count++;
    }
    fprintf(out, "Character count: %d", count);

    // Close input and output files
    fclose(in);
    fclose(out);

    printf("Puzzle solved successfully!\n");
    return 0;
}