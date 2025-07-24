//FormAI DATASET v1.0 Category: Syntax parsing ; Style: automated
#include <stdio.h>

// function prototype
void parseSyntax(char*);

// main function
int main() {
    // example C syntax code to parse
    char* code = "int main() {\n    printf(\"Hello World!\");\n    return 0;\n}";

    // call parseSyntax function
    parseSyntax(code);

    return 0;
}

// function to parse C syntax
void parseSyntax(char* code) {
    // variable to count and store number of lines in code
    int lines = 1;

    // loop through each char in code
    for (int i = 0; code[i] != '\0'; i++) {
        // if newline character is found, increment lines counter
        if (code[i] == '\n') {
            ++lines;
        }

        // check for opening curly brace
        if (code[i] == '{') {
            printf("Opening curly brace found on line %d\n", lines);
        }

        // check for closing curly brace
        if (code[i] == '}') {
            printf("Closing curly brace found on line %d\n", lines);
        }

        // check for semicolon
        if (code[i] == ';') {
            printf("Semicolon found on line %d\n", lines);
        }

        // check for variable declaration
        if (code[i] == 'i' && code[i+1] == 'n' && code[i+2] == 't') {
            printf("Variable declaration found on line %d\n", lines);
        }

        // check for function declaration
        if (code[i] == 'i' && code[i+1] == 'n' && code[i+2] == 't' && code[i+3] == ' ' && code[i+4] != 'm') {
            printf("Function declaration found on line %d\n", lines);
        }

        // check for printf statement
        if (code[i] == 'p' && code[i+1] == 'r' && code[i+2] == 'i' && code[i+3] == 'n' && code[i+4] == 't' && code[i+5] == 'f' && code[i+6] == '(') {
            printf("Printf statement found on line %d\n", lines);
        }

    }
}