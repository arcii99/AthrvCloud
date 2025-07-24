//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100]; //assuming input is no longer than 100 characters
    printf("Enter your input:\n");
    fgets(input, sizeof(input), stdin);  //getting user input with fgets

    //sanitize the input
    int i = 0, j = 0;
    char sanitized_input[100];
    while(input[i]) {
        if(isalnum(input[i])) {  //check if character is alphanumeric
            sanitized_input[j++] = input[i]; //copy alphanumeric characters to sanitized_input
        }
        i++;
    }
    sanitized_input[j] = '\0'; //terminate the sanitized_input string
    
    printf("Sanitized input: \n%s\n", sanitized_input);  //print sanitized input
    
    return 0;
}