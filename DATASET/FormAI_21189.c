//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char user_input[MAX_INPUT_LENGTH];
    int i;

    printf("Welcome to the User Input Sanitizer Program!\n");
    printf("Please enter your input: ");

    // Read user input
    fgets(user_input, MAX_INPUT_LENGTH, stdin);

    // Convert input to lowercase
    for (i = 0; i < strlen(user_input); i++) {
        user_input[i] = tolower(user_input[i]);
    }

    // Check if input contains any malicious code
    if (strstr(user_input, "rm -rf") != NULL || strstr(user_input, "system") || strstr(user_input, "shutdown")) {
        printf("Sorry, your input cannot be accepted. Malicious code detected.\n");
        exit(1);
    }

    // Remove any unwanted characters from input
    for (i = 0; i < strlen(user_input); i++) {
        if (!isalnum(user_input[i]) && user_input[i] != ' ' && user_input[i] != '\n') {
            user_input[i] = '\0';
        }
    }

    // Print the sanitized input
    printf("Sanitized Input: %s\n", user_input);

    return 0;
}