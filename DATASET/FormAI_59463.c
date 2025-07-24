//FormAI DATASET v1.0 Category: Text processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000

int main()
{
    // Get user input
    char input_string[MAX_LENGTH];
    printf("Enter a sentence: ");
    fgets(input_string, MAX_LENGTH, stdin);
    input_string[strcspn(input_string, "\n")] = 0;

    // Initialize variables
    int word_count = 0;
    int letter_count = 0;
    int i = 0;

    // Loop through each character in the input string
    while (input_string[i] != '\0')
    {
        // Check for whitespace to count words
        if (input_string[i] == ' ')
        {
            word_count++;
        }
        else
        {
            // Increment letter count for non-whitespace characters
            letter_count++;
        }

        i++;
    }

    // Increment the word count for the last word in the sentence (no space after it)
    if (letter_count > 0)
    {
        word_count++;
    }

    // Print results
    printf("Total Words: %d\n", word_count);
    printf("Total Letters: %d\n", letter_count);

    return 0;
}