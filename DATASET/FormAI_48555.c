//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scalable
#include <stdio.h>

// Function to parse C syntax for a given string
void parseCSyntax(char *str) {
    int i = 0;

    // Loop over the string until the end is reached
    while (str[i] != '\0') {

        // Check for comments
        if (str[i] == '/') {

            // Single line comment
            if (str[i + 1] == '/') {
                printf("Single line comment found.\n");
                break;
            }

            // Multi-line comment
            else if (str[i + 1] == '*') {
                printf("Multi-line comment found.\n");
                break;
            }
        }

        // Check for variable assignments
        else if (str[i] == '=') {
            printf("Variable assignment found.\n");
        }

        // Check for function calls
        else if (str[i] == '(') {
            printf("Function call found.\n");

            // Find the closing parenthesis
            int j = i + 1;
            while (str[j] != ')') {
                j++;
            }

            // Print the function arguments
            printf("Function arguments: ");
            while (i < j) {
                i++;
                if (str[i] != ' ') {
                    printf("%c", str[i]);
                }
            }
            printf("\n");
        }

        // Check for structures
        else if (str[i] == '{') {
            printf("Structure start found.\n");
        }
        else if (str[i] == '}') {
            printf("Structure end found.\n");
        }

        i++;
    }
}

int main() {
    // Test the function with different strings
    parseCSyntax("int a = 5;");
    parseCSyntax("/* This is a comment */");
    parseCSyntax("printf(\"Hello, world!\");");
    parseCSyntax("struct { int x; int y; } point;");
    return 0;
}