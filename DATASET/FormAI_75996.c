//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// This is a C Palindrome Checker program that checks if a word, phrase or sentence is a palindrome

int main()
{
    char input[1000], reverseInput[1000]; // declare input and reverseInput variables
    int i, j, length;

    printf("***** Welcome to the C Palindrome Checker Program! *****\n");
    printf("Please enter a word, phrase or sentence (max. 1000 characters):\n");
    fgets(input, 1000, stdin); // get user input

    length = strlen(input); // get length of input

    // remove whitespace and convert to lowercase
    for (i = 0, j = 0; i < length; i++)
    {
        if (!isspace(input[i]))
        {
            reverseInput[j++] = tolower(input[i]);
        }
    }
    reverseInput[j] = '\0'; // add null character at the end of reverseInput

    // check if reverseInput is a palindrome
    for (i = 0; i < j / 2; i++)
    {
        if (reverseInput[i] != reverseInput[j - i - 1])
        {
            printf("\nSorry, '%s' is not a palindrome.\n", input);
            return 0; // exit program if input is not a palindrome
        }
    }

    printf("\nCongratulations, '%s' is a palindrome!\n", input); // output palindrome message

    return 0;
}