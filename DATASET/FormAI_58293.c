//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void sanitize_input(char *input, int len)
{
    int i, j;
    char c;

    for (i = 0, j = 0; i < len; i++, j++)
    {
        c = input[i];

        if (isalpha(c)) // if character is a letter
        {
            input[j] = tolower(c); // convert to lowercase
        }
        else if (isdigit(c)) // if character is a digit
        {
            input[j] = c; // keep as is
        }
        else // if character is special character or space
        {
            j--; // decrease the output buffer index
        }
    }

    // add null character at the end of sanitized input
    input[j] = '\0';
}

int main()
{
    int len = 20;
    char input[len], sanitized_input[len];

    printf("Enter input (letters, digits, spaces, special characters): ");
    fgets(input, len, stdin);

    printf("Original Input: %s\n", input);

    sanitize_input(input, len);

    printf("Sanitized Input: %s\n", input);

    return 0;
}