//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: systematic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char userInput[MAX_INPUT_LENGTH + 1]; // allocate enough space for the input and null terminator
    printf("Enter some text: ");
    fgets(userInput, MAX_INPUT_LENGTH + 1, stdin); // read input from stdin into variable
    
    // Sanitize the input by removing non-alphanumeric characters and converting to lowercase 
    
    char sanitizedInput[MAX_INPUT_LENGTH + 1];
    int indexTracker = 0;
    for(int i = 0; i < strlen(userInput); i++) { // loop through each character in the input
        if(isalnum(userInput[i])) { // check if character is alphanumeric
            sanitizedInput[indexTracker++] = tolower(userInput[i]); // if so, add lowercased version to sanitized array
        }
    }
    sanitizedInput[indexTracker] = '\0'; // add null terminator to sanitized array
    
    // Print the sanitized input
    printf("Sanitized input: %s", sanitizedInput);
    
    return 0;
}