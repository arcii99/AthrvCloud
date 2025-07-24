//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    char* input_file_path = argv[1];
    char* output_file_path = argv[2];
    FILE* input_file = fopen(input_file_path, "r");
    FILE* output_file = fopen(output_file_path, "w");
    if (!input_file) {
        printf("Failed to open input file: %s\n", input_file_path);
        return 1;
    }
    if (!output_file) {
        printf("Failed to open output file: %s\n", output_file_path);
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        char* token = strtok(line, " ");
        int is_possible_intrusion = 0;
        while (token != NULL) {
            if (strcmp(token, "system") == 0 || strcmp(token, "exec") == 0 || strcmp(token, "/bin/sh") == 0) {
                is_possible_intrusion = 1;
                break;
            }
            token = strtok(NULL, " ");
        }
        if (is_possible_intrusion) {
            fprintf(output_file, "Possible intrusion on line %d: %s", line_number, line);
        }
        line_number++;
    }
    fclose(input_file);
    fclose(output_file);
    printf("Finished analyzing input file: %s\n", input_file_path);
    printf("Results written to output file: %s\n", output_file_path);
    return 0;
}