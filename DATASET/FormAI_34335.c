//FormAI DATASET v1.0 Category: Log analysis ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the log file path is passed as an argument
    if (argc < 2) {
        printf("Usage: %s path/to/logfile\n", argv[0]);
        return 1;
    }

    // Open the log file for reading
    FILE *logfile = fopen(argv[1], "r");
    if (logfile == NULL) {
        printf("Unable to open logfile %s\n", argv[1]);
        return 1;
    }

    // Variables to store analysis results
    int total_lines = 0;
    int error_lines = 0;
    int warning_lines = 0;
    int info_lines = 0;
    int debug_lines = 0;
    char line[1024];

    // Read each line of the log file
    while (fgets(line, 1024, logfile)) {
        total_lines++;

        if (strstr(line, "ERROR")) {
            error_lines++;
        } else if (strstr(line, "WARNING")) {
            warning_lines++;
        } else if (strstr(line, "INFO")) {
            info_lines++;
        } else if (strstr(line, "DEBUG")) {
            debug_lines++;
        }
    }

    // Close the log file
    fclose(logfile);

    // Print analysis results
    printf("Total lines in log file: %d\n", total_lines);
    printf("Number of lines with ERROR: %d\n", error_lines);
    printf("Number of lines with WARNING: %d\n", warning_lines);
    printf("Number of lines with INFO: %d\n", info_lines);
    printf("Number of lines with DEBUG: %d\n", debug_lines);

    return 0;
}