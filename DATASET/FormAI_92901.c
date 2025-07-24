//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: introspective
/* This program is a User Input Sanitizer, written in C. It takes user input, and removes any unwanted characters, such as non-alphanumeric characters or excessive whitespace.
It makes use of arrays, loops, and string manipulation functions to accomplish this task. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100 /* maximum length of user input */

int main() {
    char input[MAX_INPUT_LENGTH]; /* declare an array to store user input */
    char sanitized_input[MAX_INPUT_LENGTH]; /* declare an array to store sanitized input */
    int i, j; /* declare iterators for looping through arrays */
    
    printf("--- User Input Sanitizer ---\n");
    printf("Enter some text:\n");
    
    /* read user input into array */
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    /* iterate through input array and sanitize each character */
    for (i = 0, j = 0; i < strlen(input); i++) {
        /* check if character is alphanumeric or whitespace */
        if (isalnum(input[i]) || isspace(input[i])) {
            /* convert any uppercase letters to lowercase */
            if (isupper(input[i])) {
                input[i] = tolower(input[i]);
            }
            /* add character to sanitized_input array */
            sanitized_input[j] = input[i];
            j++;
        }
    }
    /* add null terminator to end of sanitized input array */
    sanitized_input[j] = '\0';
    
    /* print sanitized input */
    printf("Sanitized input:\n%s\n", sanitized_input);
    
    return 0; /* exit program */
}