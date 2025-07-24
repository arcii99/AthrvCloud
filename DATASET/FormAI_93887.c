//FormAI DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *logFile = fopen("log.txt", "r");
    if (logFile == NULL)
    {
        printf("Error: Unable to open log file\n");
        exit(1);
    }

    int errors = 0;
    int warnings = 0;
    int infos = 0;

    char currentLine[256];

    while(fgets(currentLine, 256, logFile) != NULL)
    {
        // Check if the line contains an error message
        if (strstr(currentLine, "[ERROR]"))
        {
            errors++;
        }
        // Check if the line contains a warning message
        else if (strstr(currentLine, "[WARNING]"))
        {
            warnings++;
        }
        // Check if the line contains an info message
        else if (strstr(currentLine, "[INFO]"))
        {
            infos++;
        }
    }

    // Print the results
    printf("Log analysis complete:\n");
    printf("Errors: %d\n", errors);
    printf("Warnings: %d\n", warnings);
    printf("Infos: %d\n", infos);

    fclose(logFile);

    return 0;
}