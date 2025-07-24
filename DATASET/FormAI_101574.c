//FormAI DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char inputString[100];
    char searchWord[20];
    int count = 0;

    printf("Enter the string to be searched:\n");
    gets(inputString);

    printf("Enter the word to count:\n");
    gets(searchWord);

    char *token = strtok(inputString, " ");

    while (token != NULL)
    {
        if (strcmp(token, searchWord) == 0)
        {
            count++;
        }

        token = strtok(NULL, " ");
    }

    printf("The word %s appears %d times in the given string.\n", searchWord, count);

    return 0;
}