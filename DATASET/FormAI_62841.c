//FormAI DATASET v1.0 Category: Word Count Tool ; Style: retro
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000 // Define maximum string length
int main()
{
    char input_string[MAX_LENGTH];
    printf("Enter a sentence: ");
    fgets(input_string,MAX_LENGTH,stdin); // Read the input sentence from the user

    int count = 0;
    int is_word = 0; // Keep track of whether we are currently in a word or not
    for (int i = 0; i < strlen(input_string); i++)
    {
        if ((input_string[i] >= 'a' && input_string[i] <= 'z') || (input_string[i] >= 'A' && input_string[i] <= 'Z'))
        {
            if (!is_word) // If we're not currently in a word, this is the first letter of a new word
            {
                count++;
            }
            is_word = 1; // Mark that we are currently in a word
        }
        else
        {
            is_word = 0; // Mark that we are not currently in a word
        }
    }
    // Print the word count
    printf("Word count: %d\n", count);
    return 0;
}