//FormAI DATASET v1.0 Category: Text processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LEN 100

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("USAGE: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    char input_file_name[MAX_LINE_LEN];
    char output_file_name[MAX_LINE_LEN];
    strncpy(input_file_name, argv[1], MAX_LINE_LEN);
    strncpy(output_file_name, argv[2], MAX_LINE_LEN);
    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("ERROR: Cannot open input file '%s'\n", input_file_name);
        return 1;
    }
    char **lines = (char **)calloc(MAX_LINES, sizeof(char *));
    for (int i = 0; i < MAX_LINES; i++) {
        lines[i] = (char *)calloc(MAX_LINE_LEN, sizeof(char));
        if (fgets(lines[i], MAX_LINE_LEN, input_file) == NULL) {
            break;
        }
        strtok(lines[i], "\n"); // Remove newlines from the end of each line
    }
    fclose(input_file);
    int nlines = 0;
    while (lines[nlines][0] != '\0') {
        nlines++;
    }
    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("ERROR: Cannot open output file '%s'\n", output_file_name);
        return 1;
    }
    for (int i = nlines - 1; i >= 0; i--) { // Reverse order of lines
        fprintf(output_file, "%s\n", lines[i]);
    }
    fclose(output_file);
    for (int i = 0; i < MAX_LINES; i++) {
        free(lines[i]);
    }
    free(lines);
    return 0;
}