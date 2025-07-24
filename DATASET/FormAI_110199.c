//FormAI DATASET v1.0 Category: Word Count Tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LEN 1000

int countWords(char *input);

int main()
{
    char input[MAX_INPUT_LEN];
    printf("Enter a sentence or phrase: ");
    fgets(input, MAX_INPUT_LEN, stdin);
    printf("Word count: %d\n", countWords(input));
    return 0;
}

int countWords(char *input)
{
    int wordCount = 0, i;
    if (strlen(input) > 0 && input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';
    for (i = 0; i < strlen(input); i++)
    {
        if (isalnum(input[i]))
        {
            while (isalnum(input[i]) && i < strlen(input))
                i++;
            wordCount++;
        }
    }
    return wordCount;
}