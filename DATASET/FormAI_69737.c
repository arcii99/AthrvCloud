//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    FILE *fp;
    char *filename = "nonexistent_file.txt";
    int num;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: %d\n", errno);
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    if (fscanf(fp, "%d", &num) != 1)
    {
        if (ferror(fp))
        {
            fprintf(stderr, "Error reading from file: %d\n", errno);
            perror("fscanf");
        }
        else if (feof(fp))
        {
            fprintf(stderr, "End of file reached prematurely\n");
        }
        else
        {
            fprintf(stderr, "Unknown error occurred\n");
        }
        exit(EXIT_FAILURE);
    }

    printf("Read number: %d\n", num);

    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Error closing file: %d\n", errno);
        perror("fclose");
        exit(EXIT_FAILURE);
    }

    return 0;
}