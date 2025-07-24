//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    int count = 0, word = 0;
    char filename[100], c;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

    while ((c = fgetc(fp)) != EOF)
    {
        if (isalnum(c))
        {
            word = 1;
        }
        else if (word)
        {
            word = 0;
            count++;
        }
    }

    fclose(fp);

    printf("Total number of words in file: %d\n", count);

    return 0;
}