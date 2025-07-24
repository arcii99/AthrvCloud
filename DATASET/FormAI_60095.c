//FormAI DATASET v1.0 Category: Syntax parsing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to parse the given C Syntax
void parseSyntax(char* syntax) {
    char* token = strtok(syntax, " "); // Split the syntax by space
    while (token != NULL) {
        if (strcmp(token, "int") == 0) { // Check if it is an integer declaration
            printf("Data Type: Integer\n");
        } else if (strcmp(token, "float") == 0) { // Check if it is a float declaration
            printf("Data Type: Float\n");
        } else if (strcmp(token, "char") == 0) { // Check if it is a character declaration
            printf("Data Type: Character\n");
        } else if (strcmp(token, "=") == 0) { // Check if it is an assignment operator
            printf("Operator: Assignment\n");
        } else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0) { // Check if it is a arithmetic operator
            printf("Operator: Arithmetic\n");
        } else if (strcmp(token, "==") == 0 || strcmp(token, "!=") == 0 || strcmp(token, ">") == 0 || strcmp(token, "<") == 0 || strcmp(token, ">=") == 0 || strcmp(token, "<=") == 0) { // Check if it is a comparison operator
            printf("Operator: Comparison\n");
        } else if (strcmp(token, "(") == 0) { // Check if it is the start of a function parameter list
            printf("Function Parameter List: Start\n");
        } else if (strcmp(token, ")") == 0) { // Check if it is the end of a function parameter list
            printf("Function Parameter List: End\n");
        } else if (strcmp(token, "{") == 0) { // Check if it is the start of a code block
            printf("Code Block: Start\n");
        } else if (strcmp(token, "}") == 0) { // Check if it is the end of a code block
            printf("Code Block: End\n");
        } else if (strcmp(token, ";") == 0) { // Check if it is the end of a statement
            printf("End of Statement\n");
        } else { // Otherwise, it is a variable or function name
            printf("Identifier: %s\n", token);
        }
        token = strtok(NULL, " "); // Continue to the next token
    }
}

int main() {
    char syntax[100]; // Create a character array to hold the syntax
    printf("Enter the C Syntax: ");
    fgets(syntax, 100, stdin); // Get the syntax from user input
    syntax[strcspn(syntax, "\n")] = 0; // Remove the newline character
    printf("Syntax Parsing Result:\n");
    parseSyntax(syntax); // Parse the syntax and print the result
    return 0;
}