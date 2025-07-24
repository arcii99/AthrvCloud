//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
void sanitize_input(char *input)
{
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (isdigit(input[i])) {
            continue;
        } else if (isalpha(input[i])) {
            input[i] = toupper(input[i]);
        } else {
            input[i] = ' ';
        }
    }
}

int main()
{
    char input[100];
    printf("Enter some input: ");
    fgets(input, 100, stdin);
    sanitize_input(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}