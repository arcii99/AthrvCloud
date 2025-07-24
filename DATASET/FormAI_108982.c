//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input[100];
    char sanitized_input[100];

    printf("Welcome! Let's sanitize some user input!\n");
    printf("Please enter your input: \n");
    fgets(input, sizeof(input), stdin);

    int input_len = strlen(input);

    // Check for new line character at the end of the input
    if(input[input_len - 1] == '\n') {
        input[input_len - 1] = '\0';
    }

    // Sanitize the input
    int j = 0;
    for(int i = 0; i < input_len; i++) {
        if(isalpha(input[i])) {
            sanitized_input[j] = input[i];
            j++;
        }
    }
    // Add null terminator at the end of sanitized input
    sanitized_input[j] = '\0';

    printf("The sanitized input is: %s\n", sanitized_input);
    printf("Thank you for using our input sanitizer!\n");
    return 0;
}