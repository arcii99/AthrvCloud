//FormAI DATASET v1.0 Category: Syntax parsing ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void parseSyntax(char* code);

int main() {
    // Sample code with C syntax
    char* code = "int main() { \n\t printf(\"Hello, World!\"); \n\t return 0; \n}";
    
    // Parse the syntax of the code
    parseSyntax(code);
    
    return 0;
}

void parseSyntax(char* code) {
    int i = 0, openBraces = 0, closeBraces = 0, semicolons = 0;
    int inString = 0, inChar = 0, inSingleLineComment = 0, inMultiLineComment = 0;
    
    while(code[i] != '\0') {    
        // Check if the current character is within a string
        if(inString) {
            if(code[i] == '\"' && code[i-1] != '\\') {
                inString = 0;
            }
        }
        // Check if the current character is within a character
        else if(inChar) {
            if(code[i] == '\'' && code[i-1] != '\\') {
                inChar = 0;
            }
        }
        // Check if the current character is within a single-line comment
        else if(inSingleLineComment) {
            if(code[i] == '\n') {
                inSingleLineComment = 0;
            }
        }
        // Check if the current character is within a multi-line comment
        else if(inMultiLineComment) {
            if(code[i] == '*' && code[i+1] == '/') {
                inMultiLineComment = 0;
                i++;
            }
        }
        // Check for string/character/comment delimiters and count braces and semicolons
        else {
            if(code[i] == '\"') {
                inString = 1;
            }
            else if(code[i] == '\'') {
                inChar = 1;
            }
            else if(code[i] == '/' && code[i+1] == '/') {
                inSingleLineComment = 1;
                i++;
            }
            else if(code[i] == '/' && code[i+1] == '*') {
                inMultiLineComment = 1;
                i++;
            }
            else if(code[i] == '{') {
                openBraces++;
            }
            else if(code[i] == '}') {
                closeBraces++;
            }
            else if(code[i] == ';') {
                semicolons++;
            }
        }
        
        // Move to the next character
        i++;
    }
    
    // Check if the number of open braces, close braces and semicolons are equal
    if(openBraces != closeBraces) {
        printf("Error: Unequal number of open and close braces\n");
        exit(1);
    }
    else if(openBraces == 0 && closeBraces == 0 && semicolons == 0) {
        printf("Error: Empty code\n");
        exit(1);
    }
    else if(semicolons == 0) {
        printf("Error: Missing semicolons\n");
        exit(1);
    }
    else {
        printf("Syntax is correct!\n");
    }
}