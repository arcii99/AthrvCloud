//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input[100];
    printf("Enter your username: ");
    fgets(input, 100, stdin); // Get username from user input
    input[strcspn(input, "\n")] = 0; // Remove the newline character from the end of input

    // Sanitize the input by removing any potential malicious characters
    char *sanitized_input = malloc(sizeof(char) * (strlen(input) + 1));
    int index = 0;

    for(int i = 0; i < strlen(input); i++) {
        if(input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z' || input[i] >= '0' && input[i] <= '9') {
            sanitized_input[index] = input[i];
            index++;
        }
    }

    sanitized_input[index] = '\0'; // Add null terminator to end of sanitized input

    printf("Sanitized username: %s\n", sanitized_input);

    free(sanitized_input); // Free memory allocated to sanitized_input

    return 0;
}