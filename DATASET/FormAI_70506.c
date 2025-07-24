//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to check if the user input is valid
int check_input(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] == ';' || str[i] == '#' || str[i] == '$' || str[i] == '(' || str[i] == ')') {
            return 0;
        }
    }
    return 1;
}

// Function to sanitize the user input
void sanitize_input(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] == ';' || str[i] == '#' || str[i] == '$' || str[i] == '(' || str[i] == ')') {
            str[i] = '_';
        }
    }
}

int main() {
    char input[100];
    printf("Enter some input: ");
    fgets(input, 100, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = 0;

    // Check if the input is valid
    int valid_input = check_input(input);
    if(valid_input) {
        printf("Your input is valid.\n");
    } else {
        printf("Your input is not valid.\n");

        // Sanitize the input
        sanitize_input(input);

        printf("Here is the sanitized input: %s\n", input);
    }

    return 0;
}