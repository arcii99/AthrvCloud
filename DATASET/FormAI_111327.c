//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 50

bool is_input_valid(char* input) {
    // Check for forbidden characters
    char invalid_chars[] = {'<', '>', '&', '$', '|', '(', ')', '[', ']', '{', '}'};
    for (int i = 0; i < strlen(input); i++) {
        for (int j = 0; j < sizeof(invalid_chars); j++) {
            if (input[i] == invalid_chars[j]) {
                printf("Error: input contains forbidden character '%c'\n", input[i]);
                return false;
            }
        }
    }
    
    // Check for improper use of system commands
    char* system_commands[] = {"rm", "cd", "ls", "mv", "cp", "mkdir", "rmdir", "touch", "cat"};
    for (int i = 0; i < sizeof(system_commands) / sizeof(system_commands[0]); i++) {
        if (strstr(input, system_commands[i]) != NULL) {
            printf("Error: input contains prohibited system command '%s'\n", system_commands[i]);
            return false;
        }
    }
    
    return true;
}

char* sanitize_input(char* input) {
    int input_len = strlen(input);
    if (input_len == 0) {
        printf("Error: input is empty\n");
        return NULL;
    }
    if (input_len >= MAX_INPUT_SIZE) {
        printf("Error: input length exceeds maximum size of %d\n", MAX_INPUT_SIZE);
        return NULL;
    }
    if (!is_input_valid(input)) {
        return NULL;
    }
    
    // Replace any line breaks with spaces
    for (int i = 0; i < input_len; i++) {
        if (input[i] == '\n') {
            input[i] = ' ';
        }
    }
    
    // Tokenize input and copy to sanitized string
    char* sanitized_input = (char*) malloc(input_len * sizeof(char));
    if (sanitized_input == NULL) {
        printf("Error: memory allocation failed\n");
        return NULL;
    }
    char* token;
    token = strtok(input, " ");
    while (token != NULL) {
        strcat(sanitized_input, token);
        strcat(sanitized_input, " ");
        token = strtok(NULL, " ");
    }
    
    return sanitized_input;
}

int main() {
    // Get user input
    char input[MAX_INPUT_SIZE];
    printf("Enter a string to sanitize:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    
    // Sanitize input
    char* sanitized_input = sanitize_input(input);
    if (sanitized_input == NULL) {
        printf("Input could not be sanitized.\n");
        return 1;
    }
    
    // Output sanitized input
    printf("Sanitized input: %s\n", sanitized_input);
    
    // Free memory
    free(sanitized_input);
    
    return 0;
}