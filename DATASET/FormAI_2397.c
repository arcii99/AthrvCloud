//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * Retro Style User Input Sanitizer
 * by Chatbot
 */

int main()
{
    char input[50]; // Input buffer
    int i = 0; // Loop variable
    
    printf("Enter something: ");
    fgets(input, sizeof(input), stdin); // Get user input
    
    for(i = 0; i < strlen(input); i++)
    {
        if(input[i] == '\n') // Remove new line character
        {
            input[i] = '\0';
        }
        else if(input[i] > 126 || input[i] < 32) // Sanitize non-ASCII and control characters
        {
            input[i] = '*';
        }
    }
    
    printf("Sanitized input: %s\n", input); // Print sanitized input
    
    return 0;
}