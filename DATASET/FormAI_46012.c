//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: happy
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input[200], sanitized_input[200], c;
    int i, j;

    printf("Welcome to the User Input Sanitizer program!\n");
    printf("Please type in your input: ");

    // Read and store user input
    i = 0;
    while ((c = getchar()) != '\n' && i < 200)
    {
        input[i] = c;
        i++;
    }
    input[i] = '\0';

    // Sanitize the input by removing any non-alphanumeric characters
    j = 0;
    for(i = 0; input[i] != '\0'; i++)
    {
        if(isalnum(input[i]))
        {
            sanitized_input[j] = input[i];
            j++;
        }
    }
    sanitized_input[j] = '\0';

    // Check if any characters were removed during sanitation
    if(strcmp(input, sanitized_input) == 0)
    {
        printf("\nYour input has been sanitized and is safe to use: %s\n", sanitized_input);
    }
    else
    {
        printf("\nYour input contained non-alphanumeric characters and has been normalized to: %s\n", sanitized_input);
        printf("The following characters were removed: ");
        for(i = 0; input[i] != '\0'; i++)
        {
            if(!isalnum(input[i]))
            {
                printf("%c ", input[i]);
            }
        }
        printf("\n");
    }

    printf("\nThank you for using the User Input Sanitizer program!\n");

    return 0;
}