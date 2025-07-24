//FormAI DATASET v1.0 Category: Log analysis ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_SIZE 150

void process_line(char *line, int *count);

int main()
{
    FILE *fptr;
    char line[MAX_LINE_SIZE];
    int line_count = 0;

    fptr = fopen("my_log_file.log", "r");

    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fptr) != NULL)
    {
        process_line(line, &line_count);
    }

    fclose(fptr);

    printf("Total number of lines processed: %d\n", line_count);

    return 0;
}

void process_line(char *line, int *count)
{
    char *token;

    // Check if line contains "ERROR"
    token = strtok(line, " ");
    while (token != NULL)
    {
        if (strcmp(token, "ERROR") == 0)
        {
            printf("Error found in line: %s", line);
        }
        token = strtok(NULL, " ");
    }

    (*count)++;
}