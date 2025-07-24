//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Ada Lovelace
// This is a Spam Detection System program inspired by Ada Lovelace, written in C language
// Ada Lovelace, an English mathematician and writer, is known for her work on Charles Babbage's early mechanical general-purpose computer, the Analytical Engine

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// define constants for maximum input size and spam threshold
#define MAX_INPUT_SIZE 100
#define SPAM_THRESHOLD 0.5

// function to check if a string is a spam
int isSpam(char input[]);

int main()
{
    char input[MAX_INPUT_SIZE];
    float spamScore;

    printf("Welcome to the Spam Detection System program! \n\n");

    // loop to continue taking input until user enters "quit"
    while (1)
    {
        printf("Enter a sentence to check for spam (or enter 'quit' to exit): ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // remove newline character from fgets input
        if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n')) 
            input[strlen(input) - 1] = '\0';

        // check if user wants to quit the program
        if(strcmp(input, "quit") == 0)
        {
            printf("\nThank you for using the Spam Detection System program! Goodbye. \n");
            return 0;
        }

        // calculate spam score of input
        spamScore = (float)isSpam(input) / (float)strlen(input);

        // check if spam score is above threshold and print result
        if (spamScore >= SPAM_THRESHOLD)
        {
            printf("\nThis sentence seems to be a spam with a %0.2f spam score. \n", spamScore);
        }
        else
        {
            printf("\nThis sentence seems to be legitimate with a %0.2f spam score. \n", spamScore);
        }
    }
    return 0;
}

// function to check if a string is a spam
int isSpam(char input[])
{
    int i, spamCount = 0, totalCharCount = 0;

    // loop through each character in input
    for (i = 0; i < strlen(input); i++)
    {
        // only count if character is a letter or digit
        if (isalpha(input[i]) || isdigit(input[i]))
        {
            totalCharCount++;
            // increase spam count if character is a vowel or certain punctuation marks
            if (tolower(input[i]) == 'a' || tolower(input[i]) == 'e' || tolower(input[i]) == 'i' 
                || tolower(input[i]) == 'o' || tolower(input[i]) == 'u' || input[i] == '!' 
                || input[i] == '?' || input[i] == '.' || input[i] == ',')
            {
                spamCount++;
            }
        }
    }

    // return spam count
    return spamCount;
}