//FormAI DATASET v1.0 Category: Word Count Tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function to count words
int countWords(char *string)
{
    int count = 0;
    int isWord = 0;

    // Loop through string character by character
    for (int i = 0; i <= strlen(string); i++)
    {
        // If character is an alphabetical character, set isWord to true
        if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))
        {
            isWord = 1;
        }
        // If character is a space, punctuation, or end of string and isWord was true, increment count and reset isWord
        else if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t' || string[i] == '\0' || string[i] == '.' 
            || string[i] == ',' || string[i] == ';' || string[i] == ':' || string[i] == '-')
        {
            if (isWord)
            {
                count++;
                isWord = 0;
            }
        }
    }

    return count;
}

int main()
{
    char *string = malloc(1000); // Allocate memory for string

    printf("Enter a string: ");
    fgets(string, 1000, stdin); // Read user input

    int wordCount = countWords(string); // Count words in string
    printf("The string contains %d words.\n", wordCount);

    free(string); // Free allocated memory

    return 0;
}