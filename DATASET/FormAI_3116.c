//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: future-proof
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sanitize_input(char *input) {
    int len = strlen(input);
    char *new_input = malloc(sizeof(char) * (len + 1)); // Allocate space for new string
    int j = 0; // Counter for new string index
    for (int i = 0; i < len; i++) {
        if (isalnum(input[i])) { // Check if character is alphanumeric
            new_input[j] = input[i]; // Add to new string
            j++;
        }
    }
    new_input[j] = '\0'; // Terminate new string
    strcpy(input, new_input); // Copy to original string
    free(new_input); // Free allocated space
}

int main() {
    char input[100];
    printf("Enter input: ");
    fgets(input, sizeof(input), stdin); // Get user input
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    sanitize_input(input); // Sanitize input
    printf("Sanitized input: %s", input);
    return 0;
}