//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Ada Lovelace
// Program to demonstrate User Input Sanitizer in C

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX_INPUT_LENGTH 256

int main(){
    char user_input[MAX_INPUT_LENGTH];
    char sanitized_input[MAX_INPUT_LENGTH];
    int i, j;

    printf("Enter some input: ");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);

    // Remove any leading or trailing whitespace
    i = 0;
    while(isspace(user_input[i])){
        i++;
    }
    j = strlen(user_input) - 1;
    while(isspace(user_input[j])){
        j--;
    }

    // Copy the sanitized input into a new buffer
    strncpy(sanitized_input, &user_input[i], (j-i+1));
    sanitized_input[j-i+1] = '\0';

    // Perform additional sanitization, remove any non-alphanumeric characters
    for(i=0; i<strlen(sanitized_input); i++){
        if(isalnum(sanitized_input[i])){
            sanitized_input[j] = sanitized_input[i];
            j++;
        }
    }
    sanitized_input[j] = '\0';

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    return 0;
}