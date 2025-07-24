//FormAI DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int main()
{
    FILE *fp;
    char log[MAX_SIZE];

    fp = fopen("application.log", "r");

    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int total_lines = 0;
    int error_count = 0;
    int warning_count = 0;
    int debug_count = 0;

    while(fgets(log, MAX_SIZE, fp))
    {
        total_lines++;

        if(strstr(log, "ERROR"))
        {
            error_count++;
        }

        if(strstr(log, "WARNING"))
        {
            warning_count++;
        }

        if(strstr(log, "DEBUG"))
        {
            debug_count++;
        }
    }

    printf("Total lines: %d\n", total_lines);
    printf("Error count: %d\n", error_count);
    printf("Warning count: %d\n", warning_count);
    printf("Debug count: %d\n", debug_count);

    fclose(fp);

    return 0;
}