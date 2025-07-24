//FormAI DATASET v1.0 Category: Syntax parsing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 256

void error(const char *msg) {
    fprintf(stderr, "ERROR: %s\n", msg);
    exit(1);
}

int main() {
    char str[MAX_SIZE];
    
    printf("Enter a print statement in C syntax: ");
    fgets(str, MAX_SIZE, stdin);
    
    // Remove newline character
    str[strcspn(str, "\n")] = '\0';
    
    // Check if syntax is correct
    if (strncmp(str, "printf(", 7) != 0) {
        error("Invalid syntax: missing 'printf('");
    }
    
    int len = strlen(str);
    if (str[len-1] != ')') {
        error("Invalid syntax: missing closing parenthesis ')'");
    }
    
    bool in_quote = false; // to check if we are currently within a string literal
    int i = 7; // start from the first argument of printf
    
    while (i < len-1) {
        if (str[i] == '\"') {
            // Toggle in_quote flag
            in_quote = !in_quote;
            i++;
        } else if (str[i] == '\\') {
            // Handle escape sequences within string literals
            if (in_quote) {
                if (str[i+1] != '\"' && str[i+1] != '\\') {
                    error("Invalid escape sequence");
                }
                i += 2;
            } else {
                error("Escape sequence outside of string literal");
            }
        } else if (in_quote) {
            // Skip non-escape characters within string literals
            i++;
        } else if (str[i] == ',' || str[i] == ' ') {
            // Ignore commas and spaces outside of string literals
            i++;
        } else {
            // Handle non-string arguments
            bool has_digit = false;
            while (i < len-1 && str[i] != ',' && str[i] != ' ') {
                if (str[i] >= '0' && str[i] <= '9') {
                    has_digit = true;
                }
                i++;
            }
            if (!has_digit) {
                error("Invalid argument: must contain at least one digit");
            }
        }
    }
    
    printf("Syntax is correct!\n");
    
    return 0;
}