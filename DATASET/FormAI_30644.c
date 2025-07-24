//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to sanitize string input
char* sanitizeInput(char* input) {
    int len = strlen(input);
    char* output = (char*)malloc(sizeof(char) * len + 1); //Allocate memory 
    int i, pos = 0;
    for(i = 0; i < len; i++) {
        if((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || input[i] == '.' || input[i] == '@' || input[i] == '_' || input[i] == ' ') {
            output[pos++] = input[i]; //Only copy valid characters to output
        }
    }
    output[pos] = '\0'; //Add null character to end of output string
    return output;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin); //Read input string
    input[strlen(input) - 1] = '\0'; //Remove newline character from input string
    printf("Sanitized Input: %s\n", sanitizeInput(input)); //Print sanitized input
    return 0;
}