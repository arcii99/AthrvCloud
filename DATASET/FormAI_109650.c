//FormAI DATASET v1.0 Category: System boot optimizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256

void optimize_boot(char *input_file, char *output_file) {
    FILE *input, *output;
    char line[MAX_LINE_LEN];
    int line_count = 0;
    int optimized_count = 0;
    int optimization_flag = 0;

    input = fopen(input_file, "r");
    if(!input) {
        fprintf(stderr, "Error: Invalid input file\n");
        exit(1);
    }

    output = fopen(output_file, "w");
    if(!output) {
        fprintf(stderr, "Error: Invalid output file\n");
        fclose(input);
        exit(1);
    }

    // Read input file line by line
    while(fgets(line, MAX_LINE_LEN, input)) {
        line_count++;
        optimization_flag = 0;
        int len = strlen(line);

        // Remove comments and trailing whitespace
        for(int i = 0; i < len && line[i] != '#'; i++) {
            if(line[i] == '\n' || line[i] == ' ' || line[i] == '\t') {
                line[i] = '\0';
                optimization_flag = 1;
            }
        }

        // Discard empty lines and comments
        if(optimization_flag == 1 || len == 1) {
            optimized_count++;
            continue;
        }

        // Write optimized line to output file
        fprintf(output, "%s\n", line);
    }

    printf("Total lines optimized: %d/%d\n", optimized_count, line_count);

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    optimize_boot(argv[1], argv[2]);

    return 0;
}