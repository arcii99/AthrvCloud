//FormAI DATASET v1.0 Category: Word Count Tool ; Style: introspective
/* 
   This is a C Word Count Tool example program that counts the number of words of a given input text. 
   The program splits the input text into words separated by spaces and punctuation marks and ignores numbers.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define IN 1
#define OUT 0

int main()
{
    int c, state, countWords;
    bool newWordStarted;

    state = OUT;
    countWords = 0;
    newWordStarted = false;

    printf("Enter your text for word count:\n");

    while((c = getchar()) != EOF)
    {
        if (isspace(c) || ispunct(c))
        {
            // Finish current word
            if (newWordStarted == true)
            {
                newWordStarted = false;
                countWords++;
            }
            state = OUT;
        }
        else if (isdigit(c))
        {
            // Ignore numbers
            state = OUT;
        }
        else
        {
            // Start new word
            state = IN;
            newWordStarted = true;
        }
    }

    // Check for last word
    if (newWordStarted == true)
    {
        countWords++;
    }

    printf("\nWord count: %d\n", countWords);

    return 0;
}