//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100]; // assuming input cannot exceed 100 characters
    char sanitizedInput[100];
    
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin); // reading user input using fgets()
    
    int inputLength = strlen(input);
    int sanitizedInputLength = 0;
    
    for (int i = 0; i < inputLength; i++) { // loop through each character in input
        char currentChar = input[i];
        
        if (isalpha(currentChar)) { // check if currentChar is an alphabetic character
            sanitizedInput[sanitizedInputLength] = toupper(currentChar); // convert to uppercase and add to sanitizedInput
            sanitizedInputLength++;
        }
    }
    
    printf("Sanitized input: %s\n", sanitizedInput);
    
    return 0;
}