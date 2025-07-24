//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char input_file_name[] = "input.txt";
    char output_file_name[] = "output.txt";

    // Open input file for reading
    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Could not open input file %s\n", input_file_name);
        return 1;
    }

    // Open output file for writing
    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Could not open output file %s\n", output_file_name);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    // Read input file line by line
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        // Remove newline character at the end of line
        line[strcspn(line, "\n")] = '\0';

        // Write modified line to output file
        fprintf(output_file, "%d: %s\n", line_number, line);

        line_number++;
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}