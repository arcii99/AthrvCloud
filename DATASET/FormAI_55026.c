//FormAI DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *input_file;
    char *input_filename;
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int num_if_statements = 0;

    // Check command-line arguments and open input file
    if (argc != 2) {
        fprintf(stderr, "Usage: if_counter <input_file>\n");
        exit(1);
    }
    input_filename = argv[1];
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", input_filename);
        exit(1);
    }

    // Read input file line by line
    while (getline(&line_buf, &line_buf_size, input_file) != -1) {
        // Parse line for if statements
        char *if_str = "if";
        char *if_loc = strstr(line_buf, if_str);
        while (if_loc != NULL) {
            num_if_statements++;
            if_loc = strstr(if_loc + strlen(if_str), if_str);
        }
    }

    // Print number of if statements found
    printf("Number of if statements: %d\n", num_if_statements);

    // Clean up
    free(line_buf);
    fclose(input_file);
    return 0;
}