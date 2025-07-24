//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to sanitize the user input
void sanitize(char *str)
{
    int i=0,j=0;
    int len=strlen(str);
    char temp[len];

    // Loop through the input string character by character
    while(str[i]!='\0')
    {
        // Check if the character is alphanumeric or whitespace
        if(isalnum(str[i]) || isspace(str[i]))
        {
            // If alphanumeric or whitespace, store in temp variable
            temp[j]=str[i];
            j++;
        }
        i++;
    }
    // End the temp string with a null character
    temp[j]='\0';

    // Copy the sanitized string to the original string
    strcpy(str,temp);
}

int main()
{
    char input[100];

    // Prompt user to enter input
    printf("Enter a string: ");

    // Take input from user
    fgets(input, sizeof(input), stdin);

    // Call the sanitize function
    sanitize(input);

    // Print the sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}