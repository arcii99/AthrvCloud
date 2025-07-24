//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
void sanitize(char input[], int size) {
    int i, j;

    // Removing white spaces from beginning and end of input
    i = 0;
    while (isspace((unsigned char) input[i])) {
        i++;
    }
    if (i > 0) {
        memmove(input, input + i, strlen(input) - i + 1);
    }
    j = strlen(input) - 1;
    while (j > 0 && isspace((unsigned char) input[j])) {
        input[j--] = '\0';
    }

    // Removing multiple white spaces between words
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isspace((unsigned char) input[i]) && isspace((unsigned char) input[i + 1])) {
            continue;
        }
        input[j++] = input[i];
    }
    input[j] = '\0';

    // Converting all alphabetical characters to uppercase
    for (i = 0; i < strlen(input); i++) {
        if (isalpha((unsigned char) input[i])) {
            input[i] = toupper((unsigned char) input[i]);
        }
    }
}

// Main function
int main() {
    char input[100];
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);
    sanitize(input, sizeof(input));
    printf("Sanitized input: %s\n", input);
    return 0;
}