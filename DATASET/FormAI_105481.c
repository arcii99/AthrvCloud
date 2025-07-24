//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Sherlock Holmes
// The Adventure of the User Input Sanitizer
// By Chatlock Homes

#include <stdio.h>
#include <ctype.h>

int main()
{
    printf("Greetings, my dear Watson. Today, we shall embark on a journey to create a User Input Sanitizer program.\n");
    printf("First, let me explain the concept of input sanitization. It is the process of removing unwanted characters ");
    printf("from a user's input to ensure it does not cause any harm or errors in our program.\n");

    printf("\nLet us begin with the implementation of our user input sanitizer. We will take input from the user and remove any ");
    printf("non-alphanumeric characters.\n");

    char input[100];        // to store user input
    char sanitized[100];    // to store sanitized input
    int i, j;
    
    printf("\nPlease enter your input: ");
    fgets(input, sizeof(input), stdin);   // read input from user
    
    // Main Sanitization Loop
    for(i=0,j=0; input[i]!='\0'; i++)
    {
        // ignore non-alphanumeric characters
        if(isalnum(input[i]) != 0)
        {
            sanitized[j] = input[i];
            j++;
        }
    }
    sanitized[j] = '\0';    // terminate sanitized string
    
    printf("The sanitized input is: %s", sanitized);
    printf("\nThere you have it, Watson. A simple but effective user input sanitizer program.");

    return 0;
}