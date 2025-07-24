//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT 1024

char* sanitize_input(char* input);

int main()
{
    char input[MAX_INPUT];

    printf("Enter your name: ");
    fgets(input, MAX_INPUT, stdin);

    char* sanitized_input = sanitize_input(input);

    printf("Hello, %s\n", sanitized_input);

    free(sanitized_input);

    return 0;
}

char* sanitize_input(char* input)
{
    char* sanitized_input = (char*) malloc(MAX_INPUT * sizeof(char));
    int j = 0;

    for (int i = 0; i < strlen(input); i++) {

        // Convert to lowercase
        if (isupper(input[i])) {
            sanitized_input[j] = tolower(input[i]);
        } else {
            sanitized_input[j] = input[i];
        }

        // Remove spaces and non-alphanumeric characters
        if (isalnum(sanitized_input[j])) {
            j++;
        }
    }

    sanitized_input[j] = '\0'; // Add end of string character
   
    return sanitized_input;
}