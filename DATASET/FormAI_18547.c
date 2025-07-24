//FormAI DATASET v1.0 Category: Log analysis ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the log analysis program!\n");

    // Open the log file
    FILE *logFile = fopen("example.log", "r");

    // If the log file cannot be opened, exit the program
    if (logFile == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    // Variables to track log analysis data
    int totalEntries = 0;
    int errorEntries = 0;
    int warningEntries = 0;
    int infoEntries = 0;
    int debugEntries = 0;

    // Buffer to store each line of the log file
    char buffer[1000];

    // Loop through each line of the log file
    while (fgets(buffer, sizeof(buffer), logFile)) {

        // Increment total entries
        totalEntries++;

        // Determine log type and increment corresponding counter
        if (strstr(buffer, "ERROR")) {
            errorEntries++;
        } else if (strstr(buffer, "WARNING")) {
            warningEntries++;
        } else if (strstr(buffer, "INFO")) {
            infoEntries++;
        } else if (strstr(buffer, "DEBUG")) {
            debugEntries++;
        }
    }

    // Close the log file
    fclose(logFile);

    // Print log analysis results
    printf("Total log entries: %d\n", totalEntries);
    printf("Error entries: %d\n", errorEntries);
    printf("Warning entries: %d\n", warningEntries);
    printf("Info entries: %d\n", infoEntries);
    printf("Debug entries: %d\n", debugEntries);

    // Determine overall log status
    if (errorEntries > 0) {
        printf("Overall log status: ERROR\n");
    } else if (warningEntries > 0) {
        printf("Overall log status: WARNING\n");
    } else {
        printf("Overall log status: OK\n");
    }

    printf("Thanks for using the log analysis program!\n");
    return 0;
}