//FormAI DATASET v1.0 Category: Log analysis ; Style: creative
#include <stdio.h>
#include <string.h>

int main()
{
    char log[1000];
    int error_count = 0;
    int warning_count = 0;
    int debug_count = 0;
    int info_count = 0;

    // Sample logs
    strcpy(log, "ERROR: Failed to connect to database");
    printf("%s\n", log);

    strcpy(log, "WARNING: Invalid input");
    printf("%s\n", log);

    strcpy(log, "DEBUG: Variable value: 10");
    printf("%s\n", log);

    strcpy(log, "INFO: Program started successfully");
    printf("%s\n", log);

    // Analysis of logs
    char *token = strtok(log, ": ");

    while (token != NULL)
    {
        if (strcmp(token, "ERROR") == 0)
        {
            error_count++;
        }
        else if (strcmp(token, "WARNING") == 0)
        {
            warning_count++;
        }
        else if (strcmp(token, "DEBUG") == 0)
        {
            debug_count++;
        }
        else if (strcmp(token, "INFO") == 0)
        {
            info_count++;
        }
        token = strtok(NULL, ": ");
    }

    // Display the results of analysis
    printf("\nAnalysis of Logs:\n");
    printf("\nErrors: %d", error_count);
    printf("\nWarnings: %d", warning_count);
    printf("\nDebug messages: %d", debug_count);
    printf("\nInfo messages: %d", info_count);

    return 0;
}