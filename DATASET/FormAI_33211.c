//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: recursive
#include<stdio.h>
#include<string.h>

// Function declaration
void sanitize_input(char*);

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); // read input

    sanitize_input(input); // call sanitize function

    printf("Sanitized input: %s\n", input); // print sanitized input

    return 0;
}

// Function to sanitize user input
void sanitize_input(char* input) {
    // base case
    if (*input == '\0') {
        return;
    }

    // checking if character is valid
    if (*input >= 'a' && *input <= 'z' || *input >= 'A' && *input <= 'Z' || *input >= '0' && *input <= '9' || *input == ' ') {
        sanitize_input(input + 1); // recursive call
    }
    else {
        memmove(input, input + 1, strlen(input)); // removing current character and shifting string to left
        sanitize_input(input); // recursive call
    }
}