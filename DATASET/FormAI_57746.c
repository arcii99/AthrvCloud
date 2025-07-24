//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: protected
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function prototypes
char *sanitizeInput(char *input);

int main()
{
    char input[100];
    printf("Enter input: ");
    fgets(input, sizeof(input), stdin);

    char *sanitizedInput = sanitizeInput(input);
    printf("Sanitized input: %s", sanitizedInput);
    free(sanitizedInput);

    return 0;
}

char *sanitizeInput(char *input)
{
    char *sanitizedInput = malloc(strlen(input) + 1); // allocate memory for sanitized input

    int i = 0;
    int j = 0; // index for sanitized input

    while (input[i] != '\0')
    {
        if (isalnum(input[i])) // check if character is alphanumeric
        {
            if (isupper(input[i])) // convert uppercase to lowercase
            {
                sanitizedInput[j] = tolower(input[i]);
            }
            else
            {
                sanitizedInput[j] = input[i];
            }
            j++;
        }
        i++;
    }

    sanitizedInput[j] = '\0'; // add null terminator to end of sanitized input

    return sanitizedInput;
}