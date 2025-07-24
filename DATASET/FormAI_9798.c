//FormAI DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{

    if(argc < 2)
    {
        printf("Usage: log_analysis <log_file>\n");
        exit(1);
    }

    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *match = "error";
    int error_count = 0;

    fp = fopen(argv[1], "r");

    if(fp == NULL)
    {
        printf("Could not open file\n");
        exit(1);
    }

    while(fgets(line, MAX_LINE_LENGTH, fp) != NULL)
    {
        if(strstr(line, match) != NULL)
        {
            error_count++;
            printf("%s", line);
        }
    }

    printf("Total Error Count: %d", error_count);

    fclose(fp);

    return 0;
}