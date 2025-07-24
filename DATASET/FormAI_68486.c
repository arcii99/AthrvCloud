//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Donald Knuth
/* 
    User Input Sanitizer in C
    By: [Your Name]
    
    Based on the Donald Knuth Programming Style
    
    This program will demonstrate a unique user input sanitization process
    that will remove any non-alphabetic characters from the user's input.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char input[100];
    char sanitized[100];
    int i, j = 0;
    
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    
    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            sanitized[j] = tolower(input[i]);
            j++;
        }
    }
    
    sanitized[j] = '\0';
    
    printf("Sanitized Input: %s\n", sanitized);
    
    return 0;
}