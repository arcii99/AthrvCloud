//FormAI DATASET v1.0 Category: Word Count Tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// function to count words in a sentence
int countWords(char sentence[])
{
    int count = 0;

    // loop through the sentence and count the number of spaces
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == ' ')
        {
            count++;
        }
    }

    // add 1 to the count to account for the last word
    return count + 1;
}

// main function
int main()
{
    // declare variables
    char sentence[100];
    int wordCount;

    // get sentence input from the user
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    // remove newline character from input
    sentence[strcspn(sentence, "\n")] = 0;

    // count the number of words in the sentence
    wordCount = countWords(sentence);

    // display the word count
    printf("The sentence '%s' has %d words.\n", sentence, wordCount);

    return 0;
}