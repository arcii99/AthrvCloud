//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    printf("Welcome to the Input Sanitizer program! Let's keep things clean and happy.\n");

    char input[100]; // declare input array
    int numChars; // declare integer to count characters
    int i;

    // loop until valid input is received
    while(1){
        printf("Enter a string to sanitize (max length 100): ");
        scanf("%s", input);

        numChars = strlen(input);

        // check for invalid characters
        for(i = 0; i < numChars; i++){
            if(!isalnum(input[i]) && !isspace(input[i])){ // if non-alphanumeric and non-whitespace character is found
                printf("Invalid input! Please enter a string with only letters, numbers, and spaces.\n");
                break; // stop iterating through the string
            }
            else if(i == numChars - 1){ // if all characters are valid
                printf("Sanitized input: %s\n", input);
                return 0; // exit program
            }
        }
    }

    return 0; // end of program
}