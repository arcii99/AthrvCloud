//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char original_input[1000];
    char sanitized_input[1000];
    int original_len, sanitized_len = 0;
    
    printf("Hello there! Welcome to the input sanitizer program!\n");
    printf("Please enter a string to sanitize: ");
    
    fgets(original_input, 1000, stdin);
    original_len = strlen(original_input);
    
    printf("Great! Your original input was: %s\n", original_input);
    
    for(int i=0; i<original_len; i++) {
        if(isalnum(original_input[i]) || isspace(original_input[i])) {
            sanitized_input[sanitized_len++] = original_input[i];
        }
    }
    
    sanitized_input[sanitized_len] = '\0';
    
    printf("The sanitized version of your input is: %s\n", sanitized_input);
    
    printf("Thanks for using the input sanitizer program! Goodbye!\n");
    
    return 0;
}