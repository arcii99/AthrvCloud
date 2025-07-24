//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 100

bool is_valid_input(char input[]);
void sanitize_input(char input[]);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); // read user input including whitespaces using fgets
    input[strcspn(input, "\n")] = '\0'; // remove newline character from input

    if(is_valid_input(input)) {
        printf("Your input is valid and sanitized: %s\n", input);
    }
    else {
        printf("Invalid input detected. Please try again.\n");
    }

    return 0;
}

bool is_valid_input(char input[]) {
    // check if input contains only alphanumeric characters
    for(int i = 0; i < strlen(input); i++) {
        if(!isalnum(input[i])) {
            return false;
        }
    }

    return true;
}

void sanitize_input(char input[]) {
    // replace any non-alphanumeric character with a space
    for(int i = 0; i < strlen(input); i++) {
        if(!isalnum(input[i])) {
            input[i] = ' ';
        }
    }
}