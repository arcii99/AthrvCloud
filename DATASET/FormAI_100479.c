//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[50];
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0'; // remove the newline character
    
    char sanitized_input[50];
    int i, j = 0;
    for (i = 0; i < strlen(input); i++) {
        if (isalnum(input[i]) || isspace(input[i])) { // only allow alphanumeric and space characters
            sanitized_input[j++] = input[i];
        }
    }
    sanitized_input[j] = '\0'; // add null terminator to the end of the string
    
    printf("Sanitized input: %s\n", sanitized_input);
    
    return 0;
}