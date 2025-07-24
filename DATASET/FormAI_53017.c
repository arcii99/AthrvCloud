//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: realistic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void sanitize_input(char *input);

int main()
{
    char input[50];
    printf("Enter your input: ");
    fgets(input, 50, stdin); // Read input from user
    sanitize_input(input); // Call function to sanitize input
    printf("Sanitized input: %s\n", input); // Print sanitized input
    return 0;
}

void sanitize_input(char *input)
{
    int i, j;
    char sanitized_input[50];
    j = 0;
    // Loop through input, removing non-alphanumeric characters and converting to lowercase
    for (i = 0; i < strlen(input); i++)
    {
        if (isalnum(input[i]))
        {
            sanitized_input[j] = tolower(input[i]);
            j++;
        }
    }
    sanitized_input[j] = '\0'; // Add null terminator to end of string
    strcpy(input, sanitized_input); // Copy sanitized input back to original variable
}