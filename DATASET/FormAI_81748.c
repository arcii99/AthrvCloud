//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: excited
#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Welcome to the User Input Sanitizer!\n");
    
    char input[100];
    printf("Enter a string (maximum length 99 characters): ");
    fgets(input, sizeof(input), stdin); // get input from user
    
    printf("Sanitizing string...\n");
    
    // loop through input string and remove any non-alphanumeric characters
    int i, j;
    for(i=0, j=0; input[i]!='\0'; i++){
        if(isalnum(input[i])){ // if character is alphanumeric
            input[j++] = input[i]; // add it to the sanitized input string
        }
    }
    input[j] = '\0'; // terminate the sanitized input string
    
    printf("Sanitized string: %s\n", input);
    printf("Thank you for using the User Input Sanitizer!\n");
    
    return 0;
}