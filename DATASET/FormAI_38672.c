//FormAI DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>

int main() {
    // Open the input file
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    // Count the number of lines in the input file
    int num_lines = 0;
    char line[100];
    while (fgets(line, 100, input_file) != NULL) {
        num_lines++;
    }

    // Close the input file
    fclose(input_file);

    // Open the output file
    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file\n");
        return 1;
    }

    // Write the number of lines to the output file
    fprintf(output_file, "Number of lines: %d", num_lines);

    // Close the output file
    fclose(output_file);

    printf("Program complete\n");
    return 0;
}