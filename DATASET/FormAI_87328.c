//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Ada Lovelace
// Ada Lovelace style C User Input Sanitizer
// By [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main()
{
    char input[MAX_INPUT_LENGTH];
    char sanitized[MAX_INPUT_LENGTH];
    int i, j, length, sanitized_length;

    // Get user input
    printf("Please enter some input:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove any newline characters
    length = strlen(input);
    if (input[length - 1] == '\n')
    {
        input[length - 1] = '\0';
        length--;
    }

    // Sanitize input by removing any non-alphanumeric characters
    sanitized_length = 0;
    for (i = 0; i < length; i++)
    {
        if ((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
        {
            sanitized[sanitized_length] = input[i];
            sanitized_length++;
        }
    }
    sanitized[sanitized_length] = '\0'; // Null terminate sanitized string

    // Print sanitized input
    printf("\nSanitized input:\n%s\n", sanitized);

    return 0;
}