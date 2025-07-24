//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mathematical
#include <stdio.h>
#include <string.h>

// Function to sanitize user input and remove any non-digit character
void sanitize_input(char* input, char* sanitized_input)
{
    int j = 0;
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] >= '0' && input[i] <= '9') // check if the character is a digit
        {
            sanitized_input[j] = input[i]; // if yes, store it in the sanitized_input
            j++;
        }
    }
    sanitized_input[j] = '\0'; // terminate the sanitized_input with null character
}

int main()
{
    char input[100], sanitized_input[100];

    printf("Enter a mathematical expression: ");
    fgets(input, 100, stdin); // read user input

    sanitize_input(input, sanitized_input); // sanitize the input

    printf("Sanitized input: %s", sanitized_input);

    return 0;
}