//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: intelligent
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

bool is_alpha_numeric(const char c)
{
    return isalnum(c);
}

void sanitize_input(char *input)
{
    const size_t length = strlen(input);
    char sanitized_input[MAX_INPUT_LENGTH] = {0};

    size_t sanitized_index = 0;
    for (size_t i = 0; i < length; i++)
    {
        // If character is alphanumeric, add it to our sanitized input
        if (is_alpha_numeric(input[i]))
        {
            sanitized_input[sanitized_index++] = input[i];
        }
    }

    // Copy the sanitized input back into the original input string
    strcpy(input, sanitized_input);
}

int main(void)
{
    char input[MAX_INPUT_LENGTH] = {0};
    printf("Enter input to sanitize: ");
    scanf("%99[^\n]", input); // read up to 99 characters until enter is pressed

    printf("Original input: %s\n", input);
    sanitize_input(input);
    printf("Sanitized input: %s\n", input);

    return 0;
}