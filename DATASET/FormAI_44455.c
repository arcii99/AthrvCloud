//FormAI DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *inputStr);

int main()
{
    char inputStr[1000];
    int wordCount;

    printf("Enter a sentence to count the number of words: ");
    fgets(inputStr, 1000, stdin);

    wordCount = countWords(inputStr);

    printf("The input string contains %d words.", wordCount);

    return 0;
}

int countWords(char *inputStr)
{
    int wordCount = 0;
    int i;

    for (i = 0; i < strlen(inputStr); i++)
    {
        if (inputStr[i] == ' ' || inputStr[i] == '\n' || inputStr[i] == '\t')
            wordCount++;
    }

    return wordCount + 1;
}