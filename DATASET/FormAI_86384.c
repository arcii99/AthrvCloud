//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STR_LEN 100

int sanitize_input(char *input_string);

int main() {
    printf("Please enter a string to sanitize: ");
    char input[MAX_STR_LEN];
    fgets(input, MAX_STR_LEN, stdin);

    if(sanitize_input(input)) {
        printf("Sanitized input: %s\n", input);
    } else {
        printf("Input validation failed.\n");
    }

    return 0;
}

int sanitize_input(char *input_string) {
    char sanitized[MAX_STR_LEN];
    int i = 0;
    int j = 0;
    
    // Convert all characters to lowercase
    while(input_string[i]) {
        sanitized[j] = tolower(input_string[i]);
        i++;
        j++;
    }
    sanitized[j] = '\0';
    
    // Check for invalid characters
    for(i = 0; i < strlen(sanitized); i++) {
        if(!isalpha(sanitized[i])) {
            return 0;
        }
    }

    // Copy sanitized string back into input string
    strncpy(input_string, sanitized, MAX_STR_LEN);

    return 1;
}