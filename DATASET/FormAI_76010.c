//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void sanitize_input(char *input) // Declare function to sanitize input
{
    int i, j;
    char sanitized[MAX_INPUT_LENGTH + 1]; // Create new string to hold sanitized input
    
    for (i = 0, j = 0; i < strlen(input); i++) { // Loop through each character in the input
        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= '0' && input[i] <= '9')) {
            // If the character is alphanumeric, add it to the sanitized string
            sanitized[j] = input[i];
            j++;
        }
    }
    
    sanitized[j] = '\0'; // Add null terminator to end of string
    strcpy(input, sanitized); // Copy the sanitized string back into the input string
}

int main()
{
    char input[MAX_INPUT_LENGTH + 1]; // Declare variable to hold user input
    
    printf("Please enter some input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); // Get input from user
    
    sanitize_input(input); // Call the function to sanitize the input
    
    printf("Your sanitized input is: %s\n", input); // Print the sanitized input
    
    return 0;
}