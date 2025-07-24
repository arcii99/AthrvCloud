//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Claude Shannon
/* User Input Sanitizer Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[1000]; // Holds user input
    char sanitized[1000]; // Holds sanitized input
    int i = 0, j = 0; // Index variables for loops

    printf("Enter text to sanitize: ");
    fgets(input, sizeof(input), stdin); // Get input from user

    /* Iterate through input string */
    for (i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i])) // Check if character is a letter
        {
            sanitized[j++] = tolower(input[i]); // Convert letter to lowercase and add to sanitized string
        }
        else if (isspace(input[i])) // Check if character is whitespace
        {
            sanitized[j++] = ' '; // Add a single space to sanitized string
            while (isspace(input[i])) i++; // Skip all consecutive whitespace characters
            i--; // Decrement i to adjust for the for loop incrementing it in the next iteration
        }
        else if (isdigit(input[i])) // Check if character is a digit
        {
            char digit[2] = {input[i], '\0'}; // Create a string containing the digit
            strcat(sanitized, digit); // Add the digit to sanitized string
            j++; // Increment j to account for the added digit
        }
        /* If character is not a letter, whitespace, or digit, ignore it */
    }

    printf("\nSanitized Text: %s\n", sanitized); // Display sanitized text

    return 0;
}