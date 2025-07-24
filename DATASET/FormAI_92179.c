//FormAI DATASET v1.0 Category: Word Count Tool ; Style: futuristic
#include <stdio.h>
#include <ctype.h>

int main()
{
    printf("Welcome to the C Word Count Tool!\n\n");

    // get user input
    printf("Please enter your text below:\n");
    char input[1000000];
    fgets(input, 1000000, stdin);

    // initialize count variables
    int wordCount = 0;
    int charCount = 0;

    // loop through each character in input
    for (int i = 0; input[i] != '\0'; i++)
    {
        // check if character is alphabetic
        if (isalpha(input[i]))
        {
            // increment character count
            charCount++;

            // check if character is followed by a non-alphabetic character (end of word)
            if (!isalpha(input[i+1]))
            {
                // increment word count
                wordCount++;
            }
        }
    }

    // output word and character counts
    printf("\nWord count: %d\n", wordCount);
    printf("Character count: %d\n", charCount);

    return 0;
}