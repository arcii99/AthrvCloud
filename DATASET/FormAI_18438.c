//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Alan Touring
#include<stdio.h>

//function to sanitize the input
void sanitizeInput(char *input) {
    int i = 0;
    while(input[i] != '\0') { //check each character until the end of the input
        if(input[i] == ';' || input[i] == '|' || input[i] == '&') { //check for forbidden characters
            input[i] = ' '; //replace the forbidden character with a space
        }
        else if(input[i] == '<' || input[i] == '>') { 
            input[i] = '_'; //replace the forbidden character with an underscore
        }
        i++; //go to the next character in the input
    }
}

int main() {
    char input[100];
    printf("Enter your input: ");
    fgets(input, 100, stdin); //take input from the user
    sanitizeInput(input); //call the sanitizeInput function
    printf("Sanitized input: %s", input); //print the sanitized input
    return 0;
}