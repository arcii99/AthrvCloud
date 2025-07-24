//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[50];
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);

    char sanitized_input[50] = ""; // declare a new array for sanitized input
    for (int i = 0; i < strlen(input); ++i) {
        if (input[i] >= 'A' && input[i] <= 'Z') { // if the character is uppercase
            sanitized_input[i] = input[i] + 32; // convert to lowercase and add to sanitized input
        } else if (input[i] >= 'a' && input[i] <= 'z') { // if the character is lowercase
            sanitized_input[i] = input[i]; // add to sanitized input unchanged
        } else if (input[i] == ' ') { // if the character is a space
            sanitized_input[i] = '_'; // replace with an underscore
        } else { // otherwise
            sanitized_input[i] = '~'; // replace with a tilde
        }
    }

    printf("Sanitized input: %s\n", sanitized_input);

    return 0;
}