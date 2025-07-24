//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: medieval
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100

/* Function to sanitize user input */
void sanitize_input(char* str) {
    int i = 0;
    char sanitized[MAX_LENGTH];
  
    for (; str[i] != '\0'; i++) {
        
        /* Check if character is valid (printable ASCII character) */
        if (isprint(str[i])) {
            sanitized[i] = str[i];
        }
        
        /* Character is not valid, replace with space */
        else {
            sanitized[i] = ' ';
        }
    }
  
    /* Null-terminate the sanitized string */
    sanitized[i] = '\0';
  
    /* Copy sanitized string back into original string */
    for (i = 0; sanitized[i] != '\0'; i++) {
        str[i] = sanitized[i];
    }
    
    /* Null-terminate the original string */
    str[i] = '\0';
}

int main() {
    char input[MAX_LENGTH];
    
    printf("Enter some input: ");
    fgets(input, MAX_LENGTH, stdin);
    
    /* Sanitize user input */
    sanitize_input(input);
    
    printf("Sanitized input: %s", input);
    
    return 0;
}