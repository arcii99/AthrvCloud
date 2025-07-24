//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: systematic
#include <stdio.h>
#include <ctype.h>  // For isalnum() and tolower() functions

#define MAX_INPUT_LENGTH 1000  // Maximum length of user input

void sanitizeInput(char *input) {
    char *src = input, *dst = input;
    while (*src) {
        if (isalnum(*src)) {  // If character is alphanumeric
            *dst++ = tolower(*src);  // Convert to lowercase and copy to output
        }
        ++src;
    }
    *dst = '\0';  // Null-terminate the sanitized input
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter some text to sanitize: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitizeInput(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}

/*
Sample Output:
Enter some text to sanitize: H3ll0 W0r1d!
Sanitized input: h3ll0w0r1d
*/