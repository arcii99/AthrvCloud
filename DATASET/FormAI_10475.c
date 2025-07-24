//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to sanitize user input
void sanitizeInput(char* userInput) {
    int i, j;

    // iterate through the string
    for(i=0, j=0; i < strlen(userInput); i++) {

        // check if the character is alphanumeric or a space
        if(isalnum(userInput[i]) || isspace(userInput[i])) {

            // if so, add it to the sanitized string
            userInput[j++] = userInput[i];
        } 
    }
    userInput[j] = '\0'; // append null character at the end of the string
}

int main() {
    char input[100]; // maximum 100 character input

    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin); // get user input from stdin
    
    sanitizeInput(input); // call the sanitizer function

    printf("Sanitized input: %s", input); // print the sanitized input

    return 0;
}