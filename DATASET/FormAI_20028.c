//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char user_input[100]; // declaring a character array for user input
    int i, j = 0; // declaring variables for iteration

    printf("Enter your input:\n");
    fgets(user_input, sizeof(user_input), stdin); // taking user input using fgets()

    for (i = 0; i < strlen(user_input); i++) // iterating over each character
    {
        if (isalnum(user_input[i])) // checking if the character is alphanumeric
        {
            user_input[j++] = user_input[i]; // adding the character to the sanitized input
        }
    }

    printf("Sanitized input: %s\n", user_input); // printing the sanitized input

    return 0;
}