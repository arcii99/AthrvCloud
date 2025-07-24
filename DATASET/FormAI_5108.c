//FormAI DATASET v1.0 Category: Log analysis ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *logfile = "example.log"; // The name of the log file to be analysed
    FILE *file = fopen(logfile, "r"); // Open the log file using read mode

    if (file == NULL) { // Check if the file exists
        printf("Could not open file %s\n", logfile);
        return 1;
    }

    char *line = NULL; // A pointer to a line of log to be read
    size_t len = 0; // The length of the line of log to be read
    ssize_t read; // The number of characters read from the line of log

    int count = 0; // A counter for the number of log entries analysed
    int error_count = 0; // A counter for the number of error log entries
    int warning_count = 0; // A counter for the number of warning log entries

    while ((read = getline(&line, &len, file)) != -1) { // Read each line of log file
        count++; // Increment the log entry counter

        if (strstr(line, "ERROR") != NULL) { // Check for ERROR keyword
            error_count++; // Increment the error log entry counter
        }

        if (strstr(line, "WARNING") != NULL) { // Check for WARNING keyword
            warning_count++; // Increment the warning log entry counter
        }
    }

    fclose(file); // Close the log file

    if (line) {
        free(line); // Free allocated memory
    }

    printf("Log file %s analysis:\n", logfile);
    printf("Total log entries analysed: %d\n", count);
    printf("Number of error log entries: %d\n", error_count);
    printf("Number of warning log entries: %d\n", warning_count);

    return 0;
}