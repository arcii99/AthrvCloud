//FormAI DATASET v1.0 Category: Word Count Tool ; Style: energetic
#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    int wordCount = 0, i, len;

    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    len = strlen(input);

    for (i = 0; i < len; i++)
    {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')
        {
            wordCount++;
        }
    }

    wordCount++; // Increment count to account for last word

    printf("\nTotal words in the given sentence: %d\n", wordCount);

    return 0;
}