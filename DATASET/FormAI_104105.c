//FormAI DATASET v1.0 Category: Log analysis ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    // Make sure that a log file path is provided
    if (argc < 2) {
        printf("Usage: %s <log-file-path>\n", argv[0]);
        return 1;
    }

    // Open the log file
    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Unable to open log file: %s\n", argv[1]);
        return 1;
    }

    // Define variables for storing log analysis data
    int total_lines = 0;
    int error_lines = 0;
    int warning_lines = 0;
    int debug_lines = 0;
    char line[MAX_LINE_LENGTH];

    // Loop through each line in the log file
    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        total_lines++;

        // Determine the log level of the current line
        if (strstr(line, "ERROR") != NULL) {
            error_lines++;
        } else if (strstr(line, "WARNING") != NULL) {
            warning_lines++;
        } else if (strstr(line, "DEBUG") != NULL) {
            debug_lines++;
        }
    }

    // Print the log analysis results
    printf("Total lines: %d\nError lines: %d\nWarning lines: %d\nDebug lines: %d\n",
        total_lines, error_lines, warning_lines, debug_lines);

    // Close the log file
    fclose(log_file);

    return 0;
}