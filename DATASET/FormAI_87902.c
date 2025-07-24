//FormAI DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000
#define LOG_FILE "server_log.txt"

int main(void)
{
    // Open the log file in read mode
    FILE *logFile = fopen(LOG_FILE, "r");
    if (logFile == NULL)
    {
        printf("Unable to open %s file\n", LOG_FILE);
        exit(EXIT_FAILURE);
    }

    char logLine[MAX_LENGTH];

    // Counters for error and info logs
    int errorCount = 0;
    int infoCount = 0;

    while (fgets(logLine, MAX_LENGTH, logFile) != NULL)
    {
        // Check if the current log line is an error or info log
        if (strncmp(logLine, "[ERROR]", 7) == 0)
        {
            errorCount++;
        }
        else if (strncmp(logLine, "[INFO]", 6) == 0)
        {
            infoCount++;
        }
    }

    // Close the log file
    fclose(logFile);

    printf("Log analysis complete!\n\n");

    // Print the results
    printf("%d error logs found\n", errorCount);
    printf("%d info logs found\n", infoCount);

    return 0;
}