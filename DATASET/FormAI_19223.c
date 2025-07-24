//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * This program reads user input and sanitizes it by removing any non-alphanumeric characters and
 * converting all letters to lowercase. It then prints the sanitized input to the console.
 */

#define MAX_INPUT_LENGTH 100

int main()
{
    char input[MAX_INPUT_LENGTH];
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Removes trailing newline character from input

    char sanitizedInput[MAX_INPUT_LENGTH];
    int j = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (isalnum(input[i])) // Only add alphanumeric characters to sanitizedInput
        {
            sanitizedInput[j++] = tolower(input[i]); // Convert all letters to lowercase
        }
    }
    sanitizedInput[j] = '\0';

    printf("Sanitized input: %s\n", sanitizedInput);

    return 0;
}