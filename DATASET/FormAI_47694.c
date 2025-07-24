//FormAI DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Log Analyzer!\n");
    printf("Please enter the name of the log file you would like to analyze: ");

    char filename[100];
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    int error_count = 0;
    int line_count = 0;
    char line[256];

    while (fgets(line, sizeof(line), file))
    {
        line_count++;
        char *error_message = strstr(line, "ERROR");

        if (error_message != NULL)
        {
            error_count++;
            printf("Error found on line %d: %s", line_count, error_message);
            printf("Would you like to see the full message? (y/n): ");

            char response[5];
            fgets(response, 5, stdin);
            response[strcspn(response, "\n")] = 0;

            if (strcmp(response, "y") == 0)
            {
                printf("%s", line);
            }
        }
    }

    printf("Analysis complete. %d lines analyzed. %d errors found.\n", line_count, error_count);

    return 0;
}