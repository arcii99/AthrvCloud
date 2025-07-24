//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LENGTH 1000

char sanitized_input[MAX_LENGTH];

void sanitize_input(char *input);

int main(void)
{
    char input[MAX_LENGTH];

    // Get input from the user
    printf("Enter input: ");
    fgets(input, MAX_LENGTH, stdin);

    // Sanitize the user input
    sanitize_input(input);

    // Print the sanitized input
    printf("Sanitized input: %s", sanitized_input);

    return 0;
}

void sanitize_input(char *input)
{
    int i, j = 0;

    // Loop through the input
    for (i = 0; input[i] != '\0'; i++)
    {
        // Convert all letters to lowercase
        if (isalpha(input[i]))
        {
            sanitized_input[j] = tolower(input[i]);
            j++;
        }
        // Ignore all numbers and spaces
        else if (isdigit(input[i]) || isspace(input[i]))
        {
            continue;
        }
        // Replace all other characters with a space
        else
        {
            sanitized_input[j] = ' ';
            j++;
        }
    }

    // Set the last character to null
    sanitized_input[j] = '\0';
}