//FormAI DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    FILE *fp;
    char filename[100], ch;
    int space = 0, line = 0, character = 0;

    printf("Welcome to the Happy Log Analyzer Program!\n");
    printf("Please enter the name of the log file to analyze: ");
    scanf("%s", filename);
 
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Oops! File could not be opened.\n");
        printf("Please check if the file exists.\n");
        exit(0);
    }

    printf("Yay! File opened successfully!\n");
    printf("Let's start analyzing...\n");
 
    while ((ch = fgetc(fp)) != EOF)
    {
        character++;

        if (ch == '\n')
            line++;

        if (ch == ' ')
            space++;
    }

    printf("Yippee! Analysis is complete!\n");
    printf("Here are the statistics of the log file - %s\n", filename);
    printf("Total characters = %d\n", character);
    printf("Total lines = %d\n", line);
    printf("Total spaces = %d\n", space);

    printf("Hooray! Analysis complete! Thank you for using Happy Log Analyzer!\n");
    fclose(fp);
    return 0;
}