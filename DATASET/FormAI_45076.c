//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100 // Maximum length of user input

void sanitize(char *input);

int main()
{
    char input[MAX_INPUT_LENGTH];

    printf("Enter your name: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); // Get user input
    sanitize(input); // Sanitize the user input

    printf("Hello, %s!\n", input);

    return 0;
}

void sanitize(char *input)
{
    int i;

    for (i = 0; i < strlen(input); i++) // Loop through each character in the input string
    {
        if (!isalpha(input[i])) // If the character is not a letter
        {
            input[i] = '\0'; // Replace it with null terminator
        }
        else
        {
            input[i] = tolower(input[i]); // Convert the character to lowercase
        }
    }
}