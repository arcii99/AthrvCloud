//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: energetic
#include <stdio.h>
#include <string.h>
#define MAX_INPUT_SIZE 100 // Define a constant maximum input size

int main()
{
    char input[MAX_INPUT_SIZE]; // Declare a character array to hold user input
    int i, j, len; // Declare variables for iterator, length of input, and new length after sanitization
    char sanitized[MAX_INPUT_SIZE]; // Declare array for sanitized input
    
    printf("Welcome to the User Input Sanitizer!\n");
    printf("Please enter your input: ");
    fgets(input, sizeof(input), stdin); // Use fgets to get input from user
    
    len = strlen(input); // Get the length of user input
    
    // Loop through user input to remove any non-alphabetic characters
    for(i = 0, j = 0; i < len; i++)
    {
        if(isalpha(input[i]))
        {
            sanitized[j++] = input[i];
        }
    }
    
    sanitized[j] = '\0'; // Add null terminator to end of sanitized string
    
    printf("Your sanitized input is: %s\n", sanitized); // Print sanitized input
    
    return 0; // Exit program
}