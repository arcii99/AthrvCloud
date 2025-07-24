//FormAI DATASET v1.0 Category: Log analysis ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int num_lines = 0;

    int num_errors = 0;
    int num_warnings = 0;
    int num_debugs = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        num_lines++;

        if (strstr(line, "ERROR")) {
            num_errors++;
            printf("ERROR on line %d: %s", num_lines, line);
        }

        if (strstr(line, "WARNING")) {
            num_warnings++;
            printf("WARNING on line %d: %s", num_lines, line);
        }

        if (strstr(line, "DEBUG")) {
            num_debugs++;
            printf("DEBUG on line %d: %s", num_lines, line);
        }
    }

    printf("\n\n");
    printf("Total lines: %d\n", num_lines);
    printf("Total errors: %d\n", num_errors);
    printf("Total warnings: %d\n", num_warnings);
    printf("Total debugs: %d\n", num_debugs);

    fclose(file);
    return 0;
}