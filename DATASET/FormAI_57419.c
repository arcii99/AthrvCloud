//FormAI DATASET v1.0 Category: Word Count Tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char c, filename[100];
    FILE *fp;
    int count = 0;

    printf("Enter the filename to open: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

    while((c = fgetc(fp)) != EOF)
    {
        if(isalpha(c))
        {
            count++;
            while(isalpha(c))
            {
                c = fgetc(fp);
            }
        }
    }

    printf("The number of words in file is %d\n", count);

    fclose(fp);

    return 0;
}