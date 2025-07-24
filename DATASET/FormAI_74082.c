//FormAI DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file;                     // Declare file variable
    char fileName[] = "log.txt";    // Set file name
    char line[100];                 // Declare buffer variable for each line
    int countError = 0;             // Count of errors
    int countWarning = 0;           // Count of warnings
    int countInfo = 0;              // Count of info messages
    int countDebug = 0;             // Count of debug messages

    // Open file for reading
    file = fopen(fileName, "r");

    // Check if file exists
    if (file == NULL)
    {
        printf("Error: File not found\n");
        return 1;
    }

    printf("\nLog Analysis Results:\n");

    // Loop through each line of the file
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "ERROR")) {
            countError++;
            printf("Error: %s", line);
        }
        else if (strstr(line, "WARNING")) {
            countWarning++;
            printf("Warning: %s", line);
        }
        else if (strstr(line, "INFO")) {
            countInfo++;
            printf("Info: %s", line);
        }
        else if (strstr(line, "DEBUG")) {
            countDebug++;
            printf("Debug: %s", line);
        }
    }

    // Close file
    fclose(file);

    // Print analysis results
    printf("\n\nAnalysis Results:\n");
    printf("Total Errors: %d\n", countError);
    printf("Total Warnings: %d\n", countWarning);
    printf("Total Info Messages: %d\n", countInfo);
    printf("Total Debug Messages: %d\n", countDebug);

    return 0;
}