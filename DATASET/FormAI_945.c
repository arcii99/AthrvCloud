//FormAI DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

void countWords(const char* inputText);

int main()
{
    printf("Welcome to the C Word Count Tool!\n\n");
    printf("Please input the text you would like to count:\n");

    char inputText[MAX_WORD_LENGTH];
    fgets(inputText, MAX_WORD_LENGTH, stdin);

    countWords(inputText);

    return 0;
}

void countWords(const char* inputText)
{
    int wordCount = 0;
    int index = 0;

    while (inputText[index] != '\0')
    {
        if (isalpha(inputText[index]))
        {
            // Found the start of a word
            wordCount++;

            // Move the index to the end of the word
            while (isalpha(inputText[index]))
            {
                index++;
            }
        }
        else
        {
            // Skip non-letter characters
            index++;
        }
    }

    printf("\nThere are %d words in the input text.\n", wordCount);
}