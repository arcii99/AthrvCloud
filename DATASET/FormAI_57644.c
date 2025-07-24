//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: light-weight
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void remove_special_characters(char *input_string);

int main()
{
    char user_input[100];

    printf("Please enter your input: ");
    fgets(user_input, 100, stdin);

    // Remove any special characters from the input
    remove_special_characters(user_input);

    printf("Your sanitized input is: %s", user_input);

    return 0;
}

void remove_special_characters(char *input_string)
{
    int i, j;
    char new_string[100];

    for (i = 0, j = 0; i < strlen(input_string); i++)
    {
        if (isalnum(input_string[i]))
        {
            new_string[j] = input_string[i];
            j++;
        }
    }

    // Add null terminator to the end of the new string
    new_string[j] = '\0';

    // Copy the new string back into the input string
    strcpy(input_string, new_string);
}