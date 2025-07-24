//FormAI DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: Could not open logfile: %s\n", argv[1]);
        return 1;
    }

    long total_lines = 0;
    int line_count = 0;
    char line[MAX_LINE_LENGTH];
    char *token;
    char *delim = " ";
    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        ++total_lines;
        token = strtok(line, delim);
        while (token != NULL) {
            if (strcmp(token, "ERROR") == 0) {
                ++line_count;
                break;
            }
            token = strtok(NULL, delim);
        }
    }

    float error_rate = (float) line_count / total_lines * 100;
    printf("Total lines: %ld\nLines with errors: %d\nError rate: %.2f%%\n", total_lines, line_count, error_rate);

    fclose(log_file);
    return 0;
}