//FormAI DATASET v1.0 Category: Word Count Tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000];
    int wordCount = 0;
    printf("Welcome to the C Word Count Tool! Let's get started!\n");

    printf("Please enter some text:\n");
    fgets(input, 1000, stdin);

    char *token = strtok(input," \n\t\r");
    while(token != NULL)
    {
        wordCount++;
        token = strtok(NULL, " \n\t\r");
    }

    printf("=========================\n");
    printf("Word count: %d\n", wordCount);
    printf("=========================\n");

    return 0;
}