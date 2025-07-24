//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: visionary
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100 /* Maximum size of array */

int main()
{
    char user_input[MAX_SIZE]; /* To store user input */
    
    printf("Please enter a string: ");
    fgets(user_input, MAX_SIZE, stdin); /* Get user input */
    
    /* Removing unwanted characters */
    for(int i=0; i<strlen(user_input); i++)
    {
        if(user_input[i] == '\n' || user_input[i] == '\r')
            user_input[i] = '\0';
    }
    
    /* Checking user input for unacceptable characters */
    for(int i=0; i<strlen(user_input); i++)
    {
        if(user_input[i] == '<' || user_input[i] == '>' || user_input[i] == '&' || user_input[i] == '"' || user_input[i] == '\'' || user_input[i] == '/')
        {
            printf("Unacceptable character found in input. Exiting program.");
            exit(0);
        }
    }
    
    printf("Processed input: %s", user_input);
    
    return 0;
}