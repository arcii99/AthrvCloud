//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Donald Knuth
/**
 * Name: User Input Sanitizer
 * Author: Donald Knuth
 * Description: 
 * This program takes user input and sanitizes it to remove any special
 * characters and only allows alphanumeric characters. 
 */

#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Enter your input: ");
    char input[100];
    fgets(input, 100, stdin);
    
    int i, j;
    char sanitized[100];
    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i])) {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0';
    
    printf("Your sanitized input: %s", sanitized);
    return 0;
}