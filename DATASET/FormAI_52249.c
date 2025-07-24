//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50

/* Declare function to sanitize user input */
void sanitize_input(char* input);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter your name: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitize_input(input);
    printf("Your sanitized name is: %s\n", input);
    return 0;
}

void sanitize_input(char* input) {
    /* Loop through each character in the input */
    for (int i = 0; i < strlen(input); i++) {
        /* Check if character is a letter */
        if (isalpha(input[i])) {
            /* Convert letter to uppercase */
            input[i] = toupper(input[i]);
        }
        /* Check if character is a number */
        else if (isdigit(input[i])) {
            /* Replace number with star symbol */
            input[i] = '*';
        }
        /* Check if character is a special character */
        else if (ispunct(input[i])) {
            /* Remove special character from input */
            memmove(&input[i], &input[i + 1], strlen(input) - i);
            i--;
        }
    }
    /* Remove any trailing whitespace */
    input[strcspn(input, "\n")] = 0;
}