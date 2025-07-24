//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];  // declaring a character array to store user input
    printf("Enter a string: \n");  // prompting the user for input
    fgets(input, 100, stdin);  // using fgets to get user input
    
    int i;
    for (i = 0; i < strlen(input); i++) {  // loop through the input string
        if (input[i] == '<' || input[i] == '>') {  // checking for angle brackets
            printf("Invalid character detected: %c\n", input[i]);  // informing user of invalid character
            input[i] = '\0';  // setting the character to null terminator
        }
        else if (input[i] == '\"' || input[i] == '\'') {  // checking for quotes
            printf("Invalid character detected: %c\n", input[i]);  // informing user of invalid character
            input[i] = '\0';  // setting the character to null terminator
        }
        else if (input[i] == '/') {  // checking for forward slashes
            printf("Invalid character detected: %c\n", input[i]);  // informing user of invalid character
            input[i] = '\0';  // setting the character to null terminator
        }
        else {  // if the character is valid
            continue;  // move to the next character
        }
    }
    
    printf("Sanitized input: %s\n", input);  // printing the sanitized input
    
    return 0;  // program execution complete
}