//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: recursive
#include <stdio.h>
#include <ctype.h>

void sanitizeString(char* str, int index) {
    if (str[index] == '\0') { // base case
        return;
    }

    // recursive case
    if (!isalpha(str[index]) && !isdigit(str[index])) {
        // replace non-alphanumeric characters with a space
        str[index] = ' ';
    }

    sanitizeString(str, index+1); // move to next character
}

int main() {
    char userInput[100];

    printf("Enter a string: ");
    fgets(userInput, 100, stdin);

    sanitizeString(userInput, 0); // start recursion

    printf("Sanitized input: %s", userInput);

    return 0;
}