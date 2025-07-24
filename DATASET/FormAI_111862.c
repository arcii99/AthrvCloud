//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define BUFFER_SIZE 100

int main() {
    char input_buffer[BUFFER_SIZE];
    printf("Enter your input: ");
    fgets(input_buffer, BUFFER_SIZE, stdin);

    // Remove newline character at the end
    int len = strlen(input_buffer);
    if(input_buffer[len - 1] == '\n') {
        input_buffer[len - 1] = '\0';
    }

    // Sanitize the user input
    char* sanitized_input = (char*) malloc(BUFFER_SIZE * sizeof(char));
    int j = 0;
    for(int i = 0; i < len; i++) {
        if(isalpha(input_buffer[i])) {
            // If alphabets, convert to lowercase and copy to the sanitized input buffer
            sanitized_input[j] = tolower(input_buffer[i]);
            j++;
        } else if(isdigit(input_buffer[i])) {
            // If digits, copy to the sanitized input buffer
            sanitized_input[j] = input_buffer[i];
            j++;
        } else if(input_buffer[i] == ' ') {
            // If space, replace with underscore and copy to the sanitized input buffer
            sanitized_input[j] = '_';
            j++;
        }
    }
    sanitized_input[j] = '\0';

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free allocated memory
    free(sanitized_input);
    return 0;
}