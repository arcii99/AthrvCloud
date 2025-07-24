//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];
    char sanitized_input[MAX_INPUT_SIZE];
    int i = 0;
    
    printf("Welcome to the Retro Input Sanitizer!\n");
    printf("--------------------------------------\n");
    printf("Please enter a string (max length: %d): ", MAX_INPUT_SIZE);
    fgets(input, MAX_INPUT_SIZE, stdin);
    
    while(input[i] != '\0' && i < MAX_INPUT_SIZE) {
        if(isalnum(input[i])) {
            sanitized_input[i] = tolower(input[i]);
        } else {
            sanitized_input[i] = ' ';
        }
        i++;
    }
    
    printf("\nSanitized Input:\n-----------------\n%s\n", sanitized_input);
    
    return 0;
}