//FormAI DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    // Check if a log file is provided
    if (argc < 2) {
        printf("Please provide a log file as an argument.\n");
        return 1;
    }

    // Open the log file
    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Failed to open log file.\n");
        return 1;
    }

    // Define variables
    char line[MAX_LINE_LENGTH];
    bool errors_found = false;
    int num_error_lines = 0;

    // Read each line of the log file
    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        // Check if an error is found in the line
        if (strstr(line, "ERROR") != NULL) {
            errors_found = true;
            num_error_lines++;

            // Print the error line
            printf("Error line %d: %s\n", num_error_lines, line);
        }
    }

    // Display results
    if (errors_found) {
        printf("Total number of error lines: %d\n", num_error_lines);
    } else {
        printf("No errors found in the log file.\n");
    }

    // Close the log file
    fclose(log_file);

    return 0;
}