//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* This program takes user input and removes any potentially harmful characters */

int main() {
    char input[256];
    char sanitized_input[256];
    
    printf("Welcome to the User Input Sanitizer Program! \n");
    printf("Enter some text to be sanitized: ");
    fgets(input, sizeof(input), stdin); // read user input
    
    // sanitize user input
    for(int i=0; i<strlen(input); i++) {
        if(isalnum(input[i]) || isspace(input[i])) {
            sanitized_input[i] = input[i];
        }
        else {
            sanitized_input[i] = '_';
        }
    }
    
    // print sanitized input
    printf("\nSanitized input: %s\n", sanitized_input);
    
    return 0;
}