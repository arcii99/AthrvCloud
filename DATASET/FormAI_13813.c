//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

//function to sanitize user input
void sanitize_input(char* input) {
    int i = 0;
    while(input[i]) {
        if(!isalnum(input[i])) { //if the character is not alphanumeric
            input[i] = '_'; //replace it with underscore
        }
        i++;
    }
}

int main() {
    char input[MAX_INPUT_LENGTH]; //buffer for user input

    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); //get user input
    sanitize_input(input); //sanitize user input

    printf("Sanitized Input: %s\n", input); //print the sanitized input
    return 0;
}