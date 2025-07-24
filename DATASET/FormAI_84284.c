//FormAI DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 200
#define MAX_ERROR_LENGTH 50

void analyzeLog(FILE *logFile) {
    char line[MAX_LINE_LENGTH];
    char errorMessage[MAX_ERROR_LENGTH];
    int lineNumber = 0;
    int numErrors = 0;

    // Loop through each line in the log file
    while (fgets(line, MAX_LINE_LENGTH, logFile)) {
        lineNumber++;

        // Check if the line contains an error
        if (strstr(line, "ERROR")) {
            numErrors++;

            // Extract the error message from the line
            sscanf(line, "%*s %*s %[^\n]", errorMessage);

            // Print the error message and line number
            printf("Error %d - Line %d: %s\n", numErrors, lineNumber, errorMessage);
        }
    }

    // Print the total number of errors found
    printf("Total Errors: %d\n", numErrors);
}

int main() {
    // Open the log file for reading
    FILE *logFile = fopen("example.log", "r");

    // Check if the log file was successfully opened
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    // Analyze the log file
    analyzeLog(logFile);

    // Close the log file
    fclose(logFile);

    return 0;
}