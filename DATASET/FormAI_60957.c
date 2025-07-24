//FormAI DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char** argv) {
    // Check for correct number of arguments
    if (argc != 2) {
        printf("Usage: %s [LOG_FILE]\n", argv[0]);
        exit(1);
    }

    // Open log file
    FILE* log_file = fopen(argv[1], "r");
    if (!log_file) {
        printf("Could not open log file: %s\n", argv[1]);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int num_lines = 0;
    int num_errors = 0;
    int num_warnings = 0;
    int num_criticals = 0;

    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        num_lines++;

        // Parse log level from line
        char* level_str = strtok(line, " ");
        if (!level_str) {
            continue;
        }

        // Convert level to uppercase for comparison
        for (int i = 0; level_str[i]; i++) {
            level_str[i] = toupper(level_str[i]);
        }

        // Count errors, warnings, and criticals
        if (strcmp(level_str, "ERROR") == 0) {
            num_errors++;
        } else if (strcmp(level_str, "WARNING") == 0) {
            num_warnings++;
        } else if (strcmp(level_str, "CRITICAL") == 0) {
            num_criticals++;
        }
    }

    // Print log analysis results
    printf("Log file: %s\n", argv[1]);
    printf("Number of lines: %d\n", num_lines);
    printf("Number of errors: %d\n", num_errors);
    printf("Number of warnings: %d\n", num_warnings);
    printf("Number of criticals: %d\n", num_criticals);

    // Close log file
    fclose(log_file);

    return 0;
}