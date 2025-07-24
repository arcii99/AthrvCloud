//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
char* sanitize_input(char* input) {
    int length = strlen(input);
    char* sanitized_input = (char*) malloc((length+1) * sizeof(char));
    int i, j;
    for(i = 0, j = 0; i < length; i++) {
        if(isalpha(input[i]) || isdigit(input[i])) { // check if the character is alphanumeric
            sanitized_input[j++] = input[i]; // add it to the sanitized input string
        }
    }
    sanitized_input[j] = '\0'; // add null character to end of string
    return sanitized_input; // return the sanitized input string
}

int main() {
    char input[100];
    printf("Enter your input: ");
    fgets(input, 100, stdin);
    char* sanitized_input = sanitize_input(input);
    printf("Sanitized input: %s\n", sanitized_input);
    free(sanitized_input);
    return 0;
}