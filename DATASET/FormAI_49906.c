//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: recursive
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

void sanitize(char *input_string, int length) {
    // base case
    if (length <= 0) {
        return;
    }
    
    // check if the current character is valid
    if (!isalnum(input_string[length - 1])) {
        // if it's not valid, replace it with a space
        input_string[length - 1] = ' ';
    }
    
    // call the function recursively
    sanitize(input_string, length - 1);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    
    // read in user input
    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // get the length of the input string
    int length = strlen(input);
    
    // sanitize the input
    sanitize(input, length);
    
    // print the sanitized input
    printf("Sanitized input: %s\n", input);
    
    return 0;
}