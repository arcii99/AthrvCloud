//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shocked
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 250

void sanitize_input(char *input, int input_length) 
{ 
    char temp; 
    int i, j; 

    for (i = 0; i < input_length; i++) { 
        temp = input[i]; 
        if (isalnum(temp)) { 
            for (j = i; j < input_length; j++) { 
                input[j] = input[j + 1]; 
            } 
            input_length--; 
            i--; 
        } 
    } 
} 

int main() 
{ 
    char user_input[MAX_INPUT_LENGTH];
    int input_length;
 
    printf("Please enter your input: "); 
    fgets(user_input, MAX_INPUT_LENGTH, stdin); 
 
    input_length = strlen(user_input); 
    sanitize_input(user_input, input_length);

    printf("Sanitized Input: %s\n", user_input); 
    return 0; 
}