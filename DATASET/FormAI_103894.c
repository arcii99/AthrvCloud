//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main() {
    char input[50];
    char sanitized[50];
    
    printf("Please enter your input string: ");
    fgets(input, 50, stdin);
    
    int i = 0; //initialize counter
    
    while(input[i] != '\0') {
        if(isalnum(input[i])) { //checks if input is alphanumeric
            if(isupper(input[i])) { //checks if input is uppercase
                sanitized[i] = tolower(input[i]); //convert to lowercase
            }
            else {
                sanitized[i] = input[i];
            }
        }
        else { //if input is not alphanumeric
            sanitized[i] = '_'; //replace with underscore character
        }
        i++; //increment counter
    }
    
    printf("Sanitized string: %s\n", sanitized);
    
    return 0;
}