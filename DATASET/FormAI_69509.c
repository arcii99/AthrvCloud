//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define maximum string length
#define MAX_STRING_LENGTH 1000

// Define constant 'c'
const char C = 'c';

int main()
{
    // Prompt the user for input string
    printf("Please enter a string: ");

    // Initialize variables
    int c_count = 0, total_count = 0;
    char current_char;
    char input_string[MAX_STRING_LENGTH];

    // Read input string from user
    fgets(input_string, MAX_STRING_LENGTH, stdin);

    // Loop through each character in the input string
    for (int i = 0; i < MAX_STRING_LENGTH && input_string[i] != '\0'; i++)
    {
        current_char = input_string[i];
        total_count++;

        // Convert character to lowercase
        current_char = tolower(current_char);

        // If the character is 'c', increment the count
        if (current_char == C)
        {
            c_count++;
        }
    }

    // Print results
    printf("\n\nThe input string contains %d total characters.\n", total_count);
    printf("The character 'c' appears %d times in the input string.\n", c_count);

    return 0;
}