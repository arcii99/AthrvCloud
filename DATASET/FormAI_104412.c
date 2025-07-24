//FormAI DATASET v1.0 Category: Log analysis ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Define variables
    FILE *logfile;
    char line[256];
    int warning_count = 0;
    int error_count = 0;
    int line_count = 0;

    // Check for correct usage
    if (argc != 2) {
        printf("Usage: %s [log file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the log file for reading
    logfile = fopen(argv[1], "r");

    // Check if the log file was successfully opened
    if (logfile == NULL) {
        printf("Error: The file '%s' could not be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read each line of the log file and count the number of warnings and errors
    while (fgets(line, sizeof(line), logfile)) {
        line_count++;
        if (strstr(line, "WARNING")) {
            warning_count++;
        }
        if (strstr(line, "ERROR")) {
            error_count++;
        }
    }

    // Close the log file
    fclose(logfile);

    // Print out the results
    printf("Log Analysis for '%s':\n", argv[1]);
    printf("%d lines analyzed\n", line_count);
    printf("%d warnings\n", warning_count);
    printf("%d errors\n", error_count);

    return EXIT_SUCCESS;
}