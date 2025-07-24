//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// define constants for max length of user input and error message
#define MAX_LENGTH 100
#define ERROR_MSG_LENGTH 200

// function to sanitize user input
void sanitize(char *input)
{
    int i = 0;
    while(input[i])
    {
        // check if the character is a letter or a space
        if(isalpha(input[i]) || isspace(input[i]))
        {
            // convert all letters to lowercase
            input[i] = tolower(input[i]);
            i++;
        }
        // if the character is not a letter or a space
        else
        {
            // replace the character with a space
            input[i] = ' ';
            i++;
        }
    }
}

int main()
{
    char input[MAX_LENGTH];
    char error_msg[ERROR_MSG_LENGTH];

    // prompt user for input
    printf("Enter a string: ");

    // read user input from console
    fgets(input, MAX_LENGTH, stdin);

    // check if user input exceeds max length
    if(strlen(input) == (MAX_LENGTH - 1) && input[MAX_LENGTH - 2] != '\n')
    {
        // if input exceeds max length, generate error message and exit program
        snprintf(error_msg, ERROR_MSG_LENGTH, "Error: Maximum input length exceeded! Please enter a string with a maximum length of %d characters.", MAX_LENGTH - 1);
        printf("%s\n", error_msg);
        exit(1);
    }

    // remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // sanitize user input
    sanitize(input);

    // print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}