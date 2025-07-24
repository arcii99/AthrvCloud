//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

int main(void)
{
    char input[MAX_INPUT_LENGTH];
    char sanitized_input[MAX_INPUT_LENGTH];
    int i, j;

    printf("Enter some text to sanitize: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input
    for (i = 0, j = 0; input[i] != '\0'; i++)
    {
        if (isalnum(input[i]) || isspace(input[i]))
        {
            sanitized_input[j] = input[i];
            j++;
        }
    }
    sanitized_input[j] = '\0';

    printf("Sanitized input: %s\n", sanitized_input);
    return 0;
}