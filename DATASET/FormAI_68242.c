//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// This function removes any special characters and converts lower case letters to upper case letters.
void sanitizeInput(char* input) {
    int i;  
    for (i = 0; input[i]; i++) {
        if (isalpha(input[i])) { // check if the character is an alphabet
            input[i] = toupper(input[i]);
        }
        else if (isspace(input[i])) { // check if the character is a space
            continue;
        }
        else { // if the character is a special character, replace it with an empty character
            input[i] = '\0';
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH]; 
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin); // get input from user
    
    input[strcspn(input, "\n")] = '\0'; // remove new line character
    
    sanitizeInput(input); // sanitize the input
    
    printf("The sanitized input is: %s", input);
    
    return 0;
}