//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char input[100];
    char sanitized_input[100];

    printf("Enter some input: ");
    fgets(input, sizeof(input), stdin);

    int input_len = strlen(input);

    for(int i = 0; i < input_len; i++)
    {
        switch(input[i])
        {
            case '\t':
            case '\n':
            case '\r':
                sanitized_input[i] = ' ';
                break;
            case '\\':
                sanitized_input[i] = '/';
                break;
            default:
                sanitized_input[i] = input[i];
        }
    }

    sanitized_input[input_len] = '\0';

    printf("\nSanitized input: %s\n", sanitized_input);

    return 0;
}