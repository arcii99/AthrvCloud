//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize_input(char* input_string);

int main() {
    char input[100];
    printf("Please enter input: ");
    fgets(input, sizeof(input), stdin); // gets user input
    
    sanitize_input(input); // call sanitize function
    
    printf("Sanitized Input: %s", input); // prints the sanitized input
    return 0;
}

// recursive function to sanitize user input
void sanitize_input(char* input_string) {
    if (*input_string != '\0') { // check if input string is not empty
        
        //check if the character is a letter e.g. 'a' to 'z' or 'A' to 'Z'
        if ((*input_string >= 'a' && *input_string <= 'z') || (*input_string >= 'A' && *input_string <= 'Z')) { 
            sanitize_input(input_string + 1); // call the function recursively with the next character
        } 
        
        // check if the character is a digit
        else if (*input_string >= '0' && *input_string <= '9') { 
            sanitize_input(input_string + 1); // call the function recursively with the next character
        } 
        
        // check if the character is a symbol or punctuation mark
        else if (*input_string == ' ' || *input_string == '.' || *input_string == ',' || *input_string == '?' || *input_string == '!' || *input_string == ':' || *input_string == ';') {
            sanitize_input(input_string + 1); // call the function recursively with the next character
        } 
        
        // if the character is not a letter, digit, symbol, or punctuation mark, then remove it
        else {
            memmove(input_string, input_string + 1, strlen(input_string)); // removing the current character from the string
            sanitize_input(input_string); // call the function recursively with the updated string
        }
    }
}