//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: careful
#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000

/* This function removes any non-alphabetic characters from user input */
void sanitize_input(char input[])
{
    int i = 0;
    int j = 0;

    while (input[i] != '\0')
    {
        /* If character is not alphabetical */
        if (!isalpha(input[i]))
        {
            /* Shift all characters after non-alphabetic character to the left */
            for (int k = i; input[k] != '\0'; k++)
            {
                input[k] = input[k+1];
            }
        }
        else
        {
            i++;
        }
    }

    /* Convert the sanitized input to lowercase */
    while (input[j] != '\0')
    {
        input[j] = tolower(input[j]);
        j++;
    }
}

int main()
{
    char input[MAX_INPUT_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sanitize_input(input);

    printf("Sanitized with lowercase letters: %s\n", input);

    return 0;
}