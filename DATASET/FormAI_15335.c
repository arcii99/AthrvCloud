//FormAI DATASET v1.0 Category: Log analysis ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#define LINE_SIZE 1000

// Function prototypes
int processLine(char line[]);
int countErrors();
void printResults(int errorCount);

int main()
{
    char line[LINE_SIZE];
    int errorCount = 0;

    // Open the log file for reading
    FILE *logFile = fopen("server.log", "r");

    // Check if the log file exists
    if (logFile == NULL)
    {
        printf("Error: Could not open file\n");
        exit(1);
    }

    // Read each line of the log file
    while (fgets(line, LINE_SIZE, logFile) != NULL)
    {
        errorCount += processLine(line);
    }

    // Close the log file
    fclose(logFile);

    // Print the results
    printResults(errorCount);

    return 0;
}

// Process a single line of the log file and return 1 if an error is found
int processLine(char line[])
{
    if (strstr(line, "ERROR") != NULL)
    {
        printf("%s", line);
        return 1;
    }

    return 0;
}

// Count the total number of errors in the log file
int countErrors()
{
    char line[LINE_SIZE];
    int errorCount = 0;

    // Open the log file for reading
    FILE *logFile = fopen("server.log", "r");

    // Check if the log file exists
    if (logFile == NULL)
    {
        printf("Error: Could not open file\n");
        exit(1);
    }

    // Read each line of the log file
    while (fgets(line, LINE_SIZE, logFile) != NULL)
    {
        if (strstr(line, "ERROR") != NULL)
        {
            errorCount++;
        }
    }

    // Close the log file
    fclose(logFile);

    return errorCount;
}

// Print the results of the log analysis
void printResults(int errorCount)
{
    if (errorCount == 0)
    {
        printf("No errors found in log file\n");
    }
    else if (errorCount == 1)
    {
        printf("1 error found in log file\n");
    }
    else
    {
        printf("%d errors found in log file\n", errorCount);
    }
}