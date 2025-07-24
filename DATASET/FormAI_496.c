//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100    // Maximum length of the input

int main() {
    char input[MAX_LENGTH], sanitized[MAX_LENGTH];    // Declare input and sanitized buffers
    int i, j = 0;    // Loop counters
    
    printf("Enter your input: ");
    fgets(input, MAX_LENGTH, stdin);    // Read input from user
    
    // Loop through each character in input and remove any non-alphanumeric characters
    for (i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            sanitized[j] = tolower(input[i]);    // Convert all characters to lowercase
            j++;
        }
    }
    sanitized[j] = '\0';    // Null-terminate the sanitized string
    
    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized);
    
    return 0;
}