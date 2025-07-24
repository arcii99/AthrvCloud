//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    char sanitized[1000];
    int i, j;
    int len;

    printf("Enter your input:\n");
    fgets(input, 1000, stdin);

    len = strlen(input);

    // Sanitize the input
    for (i = 0, j = 0; i < len; i++, j++)
    {
        if (input[i] == '"')
        {
            sanitized[j] = '\"';
            j++;
        }
        else if (input[i] == '\'')
        {
            sanitized[j] = '\'';
            j++;
        }
        else if (input[i] == '\\')
        {
            sanitized[j] = '\\';
            j++;
        }
        sanitized[j] = input[i];
    }
    sanitized[j] = '\0';

    printf("\nSanitized input: %s\n", sanitized);

    return 0;
}