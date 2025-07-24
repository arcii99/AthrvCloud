//FormAI DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char input[1000];

    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    int wordCount = 0, i = 0;

    while (input[i] != '\0')
    {
        // If current character is a letter and next is a space or end of line, it means end of word
        if (isalpha(input[i]) && (isspace(input[i + 1]) || input[i + 1] == '\0'))
        {
            wordCount++;
        }

        i++;
    }

    printf("\nTotal words: %d", wordCount);

    return 0;
}