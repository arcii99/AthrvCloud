//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 50 // Maximum size of input

char* sanitizeInput(char* input); // Function to sanitize input

int main()
{
    char* input = (char*)malloc(MAX_INPUT_SIZE * sizeof(char)); // Allocate memory for input string

    printf("Please enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin); // Get user input

    char* sanitizedInput = sanitizeInput(input); // Sanitize user input

    printf("Sanitized Input: %s\n", sanitizedInput); // Print sanitized input

    free(input); // Free memory allocated for input string
    free(sanitizedInput); // Free memory allocated for sanitized input

    return 0;
}

char* sanitizeInput(char* input)
{
    int inputLength = strlen(input);
    char* sanitizedInput = (char*)malloc(inputLength * sizeof(char)); // Allocate memory for the sanitized string
    int sanitizedIndex = 0;

    for (int i = 0; i < inputLength; i++)
    {
        if (isalnum(input[i]) || isspace(input[i])) // Only allow alphanumeric and space characters
        {
            sanitizedInput[sanitizedIndex++] = input[i]; // Add character to sanitized string
        }
    }

    sanitizedInput[sanitizedIndex] = '\0'; // Add null terminator to end of string

    return sanitizedInput;
}