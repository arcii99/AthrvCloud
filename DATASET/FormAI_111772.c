//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100]; //input buffer
    
    printf("Welcome to the User Input Sanitizer Program\n");
    printf("Please enter your input:\n");
    fgets(input, sizeof(input), stdin); //read user input
    
    //Sanitizing Input
    char sanitizedInput[100];
    int len = strlen(input);
    for(int i = 0, j = 0; i < len; i++) {
        if(isalnum(input[i])) {
            sanitizedInput[j] = input[i];
            j++;
        }
    }
    
    printf("\nYour original input was: %s", input);
    printf("\nYour sanitized input is: %s\n", sanitizedInput);
    
    return 0;
}