//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <ctype.h>

int main()
{
    char input[100];
    int i, j;

    printf("Welcome to the User Input Sanitizer program!\n");
    printf("Enter your input to sanitize:\n");

    fgets(input, sizeof(input), stdin);

    for (i = 0, j = 0; input[i] != '\0'; i++)
    {
        if (isalnum(input[i]) || isspace(input[i]))
        {
            input[j++] = input[i];
        }
    }

    input[j] = '\0';

    printf("Here is the sanitized input:\n");
    printf("%s", input);

    return 0;
}