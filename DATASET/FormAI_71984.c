//FormAI DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char text[1000];
    int wordCount = 0;

    printf("Enter your text: ");
    fgets(text, 1000, stdin);

    // Iterate through each character in text
    for (int i = 0; i < strlen(text); i++)
    {
        // Check if the character is whitespace or punctuation
        if (isspace(text[i]) || ispunct(text[i]))
        {
            wordCount++;
        }
    }

    // Add one to the word count for the last word
    wordCount++;

    printf("Your text has %d words.\n", wordCount);

    return 0;
}