//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

int main()
{
    char filename[MAXSIZE], c;
    FILE *fp;
    int virus = 0, i;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: Could not open file\n");
        exit(1);
    }

    for (i = 0; i < 6; i++)
    {
        if (getc(fp) != "virus"[i])
        {
            virus = 1;
            break;
        }
    }

    if (virus == 0)
    {
        printf("Virus Detected!\n");
    }
    else
    {
        printf("File is Clean\n");
    }

    fclose(fp);

    return 0;
}