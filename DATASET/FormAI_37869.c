//FormAI DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Log Analysis Program.\n");

    // Open the log file
    FILE* logFile = fopen("example.log", "r");
    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    // Create variables to store log data
    int numWarnings = 0;
    int numErrors = 0;
    int numFatalErrors = 0;
    int numCriticalErrors = 0;
    int totalLines = 0;

    // Read each line of the log file
    char line[1024];
    while (fgets(line, 1024, logFile)) {
        // Count the total number of lines
        totalLines++;

        // Check for each type of error
        if (strstr(line, "WARNING")) {
            numWarnings++;
        }
        if (strstr(line, "ERROR")) {
            numErrors++;
        }
        if (strstr(line, "FATAL ERROR")) {
            numFatalErrors++;
        }
        if (strstr(line, "CRITICAL ERROR")) {
            numCriticalErrors++;
        }
    }

    // Close the log file
    fclose(logFile);

    // Print the log analysis results
    printf("Total number of lines in log file: %d\n", totalLines);
    printf("Number of WARNINGS: %d\n", numWarnings);
    printf("Number of ERRORS: %d\n", numErrors);
    printf("Number of FATAL ERRORS: %d\n", numFatalErrors);
    printf("Number of CRITICAL ERRORS: %d\n", numCriticalErrors);

    // Determine the severity of the errors
    int totalErrors = numErrors + numFatalErrors + numCriticalErrors;
    double errorPercentage = (double)totalErrors / totalLines;
    char* errorSeverity;

    if (errorPercentage > 0.1) {
        errorSeverity = "CRITICAL";
    } else if (errorPercentage > 0.05) {
        errorSeverity = "HIGH";
    } else if (errorPercentage > 0.01) {
        errorSeverity = "MEDIUM";
    } else {
        errorSeverity = "LOW";
    }

    // Print the error severity
    printf("Error severity: %s\n", errorSeverity);

    return 0;
}