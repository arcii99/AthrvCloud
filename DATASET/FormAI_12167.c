//FormAI DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main()
{
    char fileName[100], logLine[MAX_LINE_SIZE];

    printf("Enter the name of the log file: ");
    scanf("%s", fileName);

    FILE *logFile = fopen(fileName, "r");

    if (logFile == NULL)
    {
        printf("Error opening file!");
        return (1);
    }

    int numWarnings = 0, numErrors = 0;

    while (fgets(logLine, MAX_LINE_SIZE, logFile) != NULL)
    {
        if (strstr(logLine, "WARNING") != NULL)
        {
            numWarnings++;
        }
        else if (strstr(logLine, "ERROR") != NULL)
        {
            numErrors++;
        }
    }

    fclose(logFile);

    printf("Number of warnings: %d\n", numWarnings);
    printf("Number of errors: %d\n", numErrors);

    return (0);
}