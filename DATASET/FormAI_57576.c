//FormAI DATASET v1.0 Category: Log analysis ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s logfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("Analyzing log file %s...\n", filename);

    unsigned int num_lines = 0;
    unsigned int num_errors = 0;
    unsigned int num_warnings = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        num_lines++;
        if (strstr(line, "ERROR") != NULL) {
            num_errors++;
        }
        if (strstr(line, "WARNING") != NULL) {
            num_warnings++;
        }
    }

    printf("Number of lines in log file: %u\n", num_lines);
    printf("Number of errors: %u\n", num_errors);
    printf("Number of warnings: %u\n", num_warnings);

    if (num_errors > 0) {
        printf("Errors found in log file:\n");
        rewind(fp);
        while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
            if (strstr(line, "ERROR") != NULL) {
                printf("%s", line);
            }
        }
    }

    fclose(fp);

    return 0;
}