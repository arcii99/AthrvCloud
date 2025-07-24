//FormAI DATASET v1.0 Category: Log analysis ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char **argv) {

    if(argc != 2) {
        printf("Usage: ./log_analysis <log_file>\n");
        return 1;
    }

    // Open the log file
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Failed to open log file: %s\n", argv[1]);
        return 1;
    }

    // Initialize variables
    int num_warnings = 0;
    int num_errors = 0;

    // Read the log file line by line
    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, fp) != NULL) {

        // Check for warnings
        char *warning_str = "WARNING";
        if(strstr(line, warning_str) != NULL) {
            num_warnings++;
        }

        // Check for errors
        char *error_str = "ERROR";
        if(strstr(line, error_str) != NULL) {
            num_errors++;
        }

    }

    // Close the log file
    fclose(fp);

    // Print the results
    printf("Log file: %s\n", argv[1]);
    printf("Number of warnings: %d\n", num_warnings);
    printf("Number of errors: %d\n", num_errors);

    return 0;
}