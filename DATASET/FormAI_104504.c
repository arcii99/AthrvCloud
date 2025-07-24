//FormAI DATASET v1.0 Category: Log analysis ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main()
{
    FILE *log_file;
    char line[MAX_SIZE];
    int line_count = 0, error_count = 0, warning_count = 0;

    // Open log file for reading
    log_file = fopen("application.log", "r");

    // Check if file exists and can be opened
    if (log_file == NULL)
    {
        printf("Error opening log file.\n");
        exit(1);
    }

    // Read each line of the log file
    while (fgets(line, MAX_SIZE, log_file) != NULL)
    {
        line_count++;

        // Check if line contains an error message
        if (strstr(line, "ERROR") != NULL)
        {
            error_count++;
        }

        // Check if line contains a warning message
        if (strstr(line, "WARNING") != NULL)
        {
            warning_count++;
        }
    }

    // Print statistics
    printf("Total number of lines: %d\n", line_count);
    printf("Total number of errors: %d\n", error_count);
    printf("Total number of warnings: %d\n", warning_count);

    // Close log file
    fclose(log_file);

    return 0;
}