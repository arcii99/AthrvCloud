//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main() {

    char input[50];     // array to store user input
    int len_input;      // length of user input

    printf("Enter a string (max 50 characters):\n");
    scanf("%s", input);
    len_input = strlen(input);

    // loop to check each character in input
    for (int i = 0; i < len_input; i++) {
        char c = input[i];

        // check if character is a letter or a digit
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            continue;   // if letter or digit, move to next character
        }

        // if character is not letter or digit, replace with '*'
        input[i] = '*';
    }

    printf("Sanitized string: %s\n", input);

    return 0;
}