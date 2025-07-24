//FormAI DATASET v1.0 Category: Log analysis ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr;
    char file_name[50], line[100];
    int count = 0, line_count = 0;

    printf("Enter the name of the log file: ");
    scanf("%s", file_name);

    fptr = fopen(file_name, "r");

    if (fptr == NULL)
    {
        printf("Error opening file.");
        exit(1);
    }

    while (fgets(line, sizeof(line), fptr))
    {
        line_count++;
        if (strstr(line, "ERROR") != NULL)
        {
            count++;
            printf("Error found on line %d: %s", line_count, line);
        }
    }

    printf("Total number of errors found: %d", count);

    fclose(fptr);
    return 0;
}