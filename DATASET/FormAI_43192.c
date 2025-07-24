//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the fun-filled CSV Reader program!\n");
    printf("Where we take your boring CSV files and turn them into a carnival!\n");

    FILE *fp;
    char filename[100], line[1024];
    int i, j;

    printf("Please enter the filename of your CSV file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("\nI'm sorry, we couldn't find that file! Maybe it's hiding under your bed?\n");
        return 1;
    }

    while (fgets(line, 1024, fp))
    {
        printf("Dancing with the stars!\n"); // Just for some fun!

        char *token;
        token = strtok(line, ",");
        while (token != NULL)
        {
            printf("%s, ", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    printf("\nTada! All done. Isn't your CSV file much more exciting now?\n");

    fclose(fp);
    return 0;
}