//FormAI DATASET v1.0 Category: System boot optimizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 512

void optimize_boot(char *filename);

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Invalid number of arguments. Usage: %s <bootfile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    optimize_boot(filename);

    return 0;
}

void optimize_boot(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    FILE *tmp_fp = tmpfile(); // Create temporary file for optimized boot code

    char line[MAXLINE];
    int flag = 0; // Flag to keep track of duplicate strings
    while (fgets(line, MAXLINE, fp) != NULL)
    {
        if (strstr(line, "LOAD_KERNEL") != NULL)
        {
            if (flag == 0) // First occurrence of string
            {
                fputs(line, tmp_fp); // Write to temporary file
                flag = 1;
                continue;
            }
            else // Duplicate string
            {
                continue;
            }
        }
        else
        {
            fputs(line, tmp_fp); // Write to temporary file
            continue;
        }
    }

    fclose(fp);

    fp = fopen(filename, "w"); // Overwrite original file with optimized code
    if (fp == NULL)
    {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Move file pointer of temporary file to beginning
    rewind(tmp_fp);

    while (fgets(line, MAXLINE, tmp_fp) != NULL)
    {
        fputs(line, fp);
    }

    fclose(fp);
    fclose(tmp_fp);

    printf("Boot optimization complete. File saved as %s.\n", filename);
}