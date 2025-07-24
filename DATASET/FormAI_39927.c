//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];        // Input buffer
    char sanitized[100];    // Sanitized input
    int i, j = 0;           // Loop counter and index of sanitized array
    int len;                // Length of input string

    // Cyberpunk style welcome message
    printf("Loading User Input Sanitizer v1.0...\n");
    printf("Scanning for malicious code...\n");
    printf("Establishing secure connection with user...\n\n");

    // Prompt user for input
    printf("Please enter a string: ");
    fgets(input, sizeof(input), stdin);
    len = strlen(input);

    // Sanitize input
    for(i = 0; i < len; i++)
    {
        switch(input[i])
        {
            case '<':   // Replace less than symbol with its HTML entity
                sanitized[j++] = '&';
                sanitized[j++] = 'l';
                sanitized[j++] = 't';
                sanitized[j++] = ';';
                break;
            case '>':   // Replace greater than symbol with its HTML entity
                sanitized[j++] = '&';
                sanitized[j++] = 'g';
                sanitized[j++] = 't';
                sanitized[j++] = ';';
                break;
            case '/':   // Replace forward slash with backslash
                sanitized[j++] = '\\';
                break;
            case '\\':  // Replace backslash with forward slash
                sanitized[j++] = '/';
                break;
            default:    // Copy all other characters
                sanitized[j++] = input[i];
        }
    }

    // Null-terminate the sanitized string
    sanitized[j] = '\0';

    // Cyberpunk style output of the sanitized string
    printf("\nThe sanitized string is:\n");
    printf("%s\n", sanitized);
    printf("\nConnection terminated. Goodbye!\n");

    return 0;
}