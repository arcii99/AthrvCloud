//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <ctype.h>

/* This module is used to sanitize user input by removing all special characters and 
keeping only letters and numbers*/

void sanitize_input(char *input) {
    char *p = input;
    while (*p != '\0') {
        if (isalnum(*p)) { 
        /* if the current character is a letter or a digit, keep it in the input string*/
            p++;
        }
        else {
        /* if the current character is not a letter or digit, remove it from the input by 
        shifting all remaining characters to the left by one position and setting the last 
        character to null*/
            char *q = p;
            while (*q != '\0') {
                *q = *(q + 1);
                q++;
            }
            *q = '\0';
        }
    }
}

/* This is the main function which takes input from user and calls the sanitize_input module. 
It then prints the sanitized input back to the user*/

int main() {
    char input[100];
    printf("Type something with special characters: ");
    fgets(input, sizeof(input), stdin); /* using fgets to get user input and prevent buffer overflow*/
    sanitize_input(input);
    printf("Sanitized input: %s", input);
    return 0;
}