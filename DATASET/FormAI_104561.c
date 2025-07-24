//FormAI DATASET v1.0 Category: Syntax parsing ; Style: rigorous
#include <stdio.h>

//custom function to check for C syntax errors
int checkSyntax(char *code) {
    int parentheses = 0;
    int braces = 0;
    int brackets = 0;
    int quotes = 0;
    int semicolons = 0;

    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '(') {
            parentheses++;
        } else if (code[i] == ')') {
            parentheses--;
        } else if (code[i] == '{') {
            braces++;
        } else if (code[i] == '}') {
            braces--;
        } else if (code[i] == '[') {
            brackets++;
        } else if (code[i] == ']') {
            brackets--;
        } else if (code[i] == '"') {
            quotes++;
        } else if (code[i] == ';') {
            semicolons++;
        }
    }

    if (parentheses != 0 || braces != 0 || brackets != 0 || quotes % 2 != 0 || semicolons == 0) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    //example program
    char code[] = "int main() { printf(\"Hello, world!\"); }";

    //check for syntax errors
    if (checkSyntax(code)) {
        printf("Syntax is correct, program can be compiled.");
    } else {
        printf("Errors detected in syntax, please correct before compiling.");
    }

    return 0;
}