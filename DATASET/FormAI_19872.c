//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function to sanitize user input
void sanitize_input(char* user_input) {
    // Remove leading and trailing whitespaces
    int i = 0;
    while (isspace(user_input[i])) {
        i++;
    }
    strcpy(user_input, user_input + i);
    i = strlen(user_input) - 1;
    while (isspace(user_input[i])) {
        i--;
    }
    user_input[i + 1] = '\0';

    // Convert all alphabets to lowercase
    for (i = 0; user_input[i]; i++) {
        user_input[i] = tolower(user_input[i]);
    }
}

int main() {
    char user_input[MAX_INPUT_LENGTH];
    printf("Enter your name: ");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);

    // Sanitize user input
    sanitize_input(user_input);

    printf("Hello, %s!\n", user_input);
    return 0;
}