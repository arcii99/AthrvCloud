//FormAI DATASET v1.0 Category: Log analysis ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char fileName[30];
    printf("Enter name of log file to open: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");

    if (!file)
    {
        printf("Error opening file.\n");
        return -1;
    }

    char line[100];
    int lineNum = 0;
    int errorCount = 0;
    int warningCount = 0;

    while(fgets(line, 100, file) != NULL)
    {
        lineNum++;

        if (strstr(line, "ERROR"))
        {
            errorCount++;
        }

        if (strstr(line, "WARNING"))
        {
            warningCount++;
        }
    }

    printf("Total lines processed: %d\n", lineNum);
    printf("Number of errors: %d\n", errorCount);
    printf("Number of warnings: %d\n", warningCount);

    fclose(file);
    return 0;
}