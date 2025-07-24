//FormAI DATASET v1.0 Category: System boot optimizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256

// function prototypes
void optimize_boot(char *filename);

int main(int argc, char *argv[])
{
    char *filename;

    if(argc < 2)
    {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        filename = argv[1];
    }

    optimize_boot(filename);

    return 0;
}

void optimize_boot(char *filename)
{
    FILE *fp;
    char line[MAX_LINE_LEN];
    int modified = 0;

    fp = fopen(filename, "r+");

    if(fp == NULL)
    {
        printf("Error opening file %s for reading and writing.\n", filename);
        exit(EXIT_FAILURE);
    }

    // loop through each line of the file
    while(fgets(line, MAX_LINE_LEN, fp) != NULL)
    {
        // remove any lines that contain the word "debug"
        if(strstr(line, "debug") != NULL)
        {
            printf("Removing line: %s", line);
            modified = 1;
            continue;
        }

        // remove any lines that contain the word "verbose"
        if(strstr(line, "verbose") != NULL)
        {
            printf("Removing line: %s", line);
            modified = 1;
            continue;
        }

        // remove any lines that contain the word "trace"
        if(strstr(line, "trace") != NULL)
        {
            printf("Removing line: %s", line);
            modified = 1;
            continue;
        }
    }

    if(modified)
    {
        printf("File %s has been modified.\n", filename);
    }
    else
    {
        printf("File %s did not require modification.\n", filename);
    }

    fclose(fp);
}