//FormAI DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char logLine[100];
    int numErrors = 0;
    int numWarnings = 0;

    // Open log file for reading
    FILE *logFile = fopen("logfile.txt", "r");

    // Check if logfile was opened successfully
    if (logFile == NULL)
    {
        printf("Unable to open log file\n");
        return 1;
    }

    // Read each line of the log file
    while (fgets(logLine, 100, logFile) != NULL)
    {
        // If line contains "ERROR", increment the error count
        if (strstr(logLine, "ERROR") != NULL)
        {
            numErrors++;
        }
        // If line contains "WARNING", increment the warning count
        else if (strstr(logLine, "WARNING") != NULL)
        {
            numWarnings++;
        }
    }

    // Close the log file
    fclose(logFile);

    // Output results
    printf("Log Analysis Results\n");
    printf("--------------------\n");
    printf("Number of Errors: %d\n", numErrors);
    printf("Number of Warnings: %d\n", numWarnings);

    return 0;
}