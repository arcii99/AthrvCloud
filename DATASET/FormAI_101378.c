//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    int input_length;
    
    printf("Please input something:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);  // gets user input and stores it in the 'input' variable
    input_length = strlen(input);  // gets the length of the user input
    
    printf("You have entered: %s", input);
    
    // sanitizing the input: removing any non-alphanumeric characters and converting to lowercase
    for (int i = 0; i < input_length; i++) {
        if (!isalnum(input[i])) {
            memmove(&input[i], &input[i+1], input_length-i);  // remove non-alphanumeric character
            input_length--;  // decrement the length of the string
            i--;  // move back one index to recheck the current index
        } else {
            input[i] = tolower(input[i]);  // convert the character to lowercase
        }
    }
    
    printf("Sanitized input: %s", input);
    
    return 0;
}