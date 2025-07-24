//FormAI DATASET v1.0 Category: Syntax parsing ; Style: optimized
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to check if a given character is a digit or not
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a given character is an alphabet or not
int isAlpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Function to check if a given character is a valid operator or not
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=');
}

// Function to check if a given character is a space or not
int isSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

// Function to remove spaces from a given string
void removeSpaces(char* str) {
    int i, j = 0;
    for (i = 0; str[i]; i++) {
        if (!isSpace(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to check if a given string is a keyword or not
int isKeyword(char* str) {
    if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "for") || !strcmp(str, "int") || !strcmp(str, "float") || !strcmp(str, "char")) {
        return 1;
    }
    return 0;
}

// Function to parse a given program and print the results
void parse(char* program) {
    // Remove all spaces from the program string
    removeSpaces(program);
    
    // Initialize the token buffer
    char buffer[MAX_LENGTH] = "";
    
    // Initialize the token type
    int type = -1;
    
    // Loop through each character in the program string
    for (int i = 0; program[i]; i++) {
        // If the current character is a digit
        if (isDigit(program[i])) {
            // Add the current character to the buffer
            strncat(buffer, &program[i], 1);
            
            // Set the token type to a number
            type = 1;
            
            // Check if the next character is also a digit
            while (isDigit(program[i+1])) {
                // Add the next character to the buffer
                strncat(buffer, &program[i+1], 1);
                
                // Move to the next character
                i++;
            }
        }
        // If the current character is an alphabet
        else if (isAlpha(program[i])) {
            // Add the current character to the buffer
            strncat(buffer, &program[i], 1);
            
            // Set the token type to an identifier
            type = 2;
            
            // Check if the next character is also an alphabet or a digit
            while (isAlpha(program[i+1]) || isDigit(program[i+1])) {
                // Add the next character to the buffer
                strncat(buffer, &program[i+1], 1);
                
                // Move to the next character
                i++;
            }
            
            // Check if the buffer contains a keyword
            if (isKeyword(buffer)) {
                // Set the token type to a keyword
                type = 3;
            }
        }
        // If the current character is an operator
        else if (isOperator(program[i])) {
            // Add the current character to the buffer
            strncat(buffer, &program[i], 1);
            
            // Set the token type to an operator
            type = 4;
            
            // Check if the next character is also an operator
            if (isOperator(program[i+1])) {
                // Add the next character to the buffer
                strncat(buffer, &program[i+1], 1);
                
                // Move to the next character
                i++;
            }
        }
        // If the current character is a space or a newline character
        else if (isSpace(program[i])) {
            // Print the current token
            printf("<%s, %d>\n", buffer, type);
            
            // Clear the buffer and reset the token type
            strcpy(buffer, "");
            type = -1;
        }
        // If the current character is not valid
        else {
            // Print an error message
            printf("Error: Invalid character '%c'\n", program[i]);
            
            // Clear the buffer and reset the token type
            strcpy(buffer, "");
            type = -1;
        }
    }
    
    // Print the last token
    printf("<%s, %d>\n", buffer, type);
}

// Main function
int main() {
    // Define a sample C program
    char program[] = "int main() {\n    int x = 10;\n    if (x > 5) {\n        printf(\"x is greater than 5\");\n    }\n    else {\n        printf(\"x is less than or equal to 5\");\n    }\n    while (x > 0) {\n        x--;\n    }\n    return 0;\n}";
    
    // Parse the sample C program and print the results
    parse(program);
    
    return 0;
}