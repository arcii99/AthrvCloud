//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitizeInput(char* str ) {
    for ( int i = 0 ; i < strlen(str) ; i++ ) {
        if ( !(isalnum(str[i]) || isspace(str[i])) ) {
            str[i] = ' ';
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

int main(void) {
    char input[MAX_INPUT_LENGTH];
    
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sanitizeInput(input);
    
    printf("Your sanitized input is: %s", input);

    return 0;
}