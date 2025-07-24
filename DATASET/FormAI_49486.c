//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Alan Touring
#include <stdio.h>
#include <ctype.h>

int main()
{
    char input[100];
    int i, len;
    int is_valid = 1; // flag to keep track of validity
    
    printf("Enter an expression: ");
    fgets(input, 100, stdin); // take input from user
    
    len = strlen(input);
    
    // Check if expression contains only numbers and operators
    for (i = 0; i < len; i++) {
        if (!isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/') {
            is_valid = 0; // Invalid character found
            break;
        }
    }
    
    if (is_valid) {
        printf("Valid expression\n");
    } else {
        printf("Invalid expression\n");
    }
    
    return 0;
}