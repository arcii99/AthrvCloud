//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char token[50];
    int i = 0, j = 0;

    printf("Enter a C syntax statement: ");
    fgets(input, 100, stdin);

    while (input[i] != '\0') {
        if (input[i] == '(') {
            printf("Open Parenthesis\n");
        } else if (input[i] == ')') {
            printf("Closing Parenthesis\n");
        } else if (input[i] == '{') {
            printf("Open Brace\n");
        } else if (input[i] == '}') {
            printf("Closing Brace\n");
        } else if (input[i] == ';') {
            printf("Semicolon\n");
        } else if (input[i] == ',') {
            printf("Comma\n");
        } else if (input[i] == '#') {
            printf("Preprocessor Directive\n");
        } else if (input[i] == '\'') {
            printf("Single Quote\n");
        } else if (input[i] == '\"') {
            printf("Double Quote\n");
        } else if (input[i] == '/') {
            if (input[i+1] == '/') {
                printf("Single Line Comment\n");
                while (input[i] != '\n') {
                    i++;
                }
            } else if (input[i+1] == '*') {
                printf("Multi Line Comment\n");
                i += 2;
                while (!(input[i] == '*' && input[i+1] == '/')) {
                    i++;
                }
                i += 2;
            } else {
                printf("Division Operator\n");
            }
        } else if (input[i] == '=') {
            if (input[i+1] == '=') {
                printf("Equality Comparison Operator\n");
                i++;
            } else {
                printf("Assignment Operator\n");
            }
        } else if (input[i] == '!') {
            if (input[i+1] == '=') {
                printf("Inequality Comparison Operator\n");
                i++;
            } else {
                printf("Logical NOT Operator\n");
            }
        } else if (input[i] == '<') {
            if (input[i+1] == '<' && input[i+2] == '=') {
                printf("Left Shift Assignment Operator\n");
                i += 2;
            } else if (input[i+1] == '<') {
                printf("Left Shift Operator\n");
                i++;
            } else if (input[i+1] == '=') {
                printf("Less Than or Equal To Comparison Operator\n");
                i++;
            } else {
                printf("Less Than Comparison Operator\n");
            }
        } else if (input[i] == '>') {
            if (input[i+1] == '>' && input[i+2] == '=') {
                printf("Right Shift Assignment Operator\n");
                i += 2;
            } else if (input[i+1] == '>') {
                printf("Right Shift Operator\n");
                i++;
            } else if (input[i+1] == '=') {
                printf("Greater Than or Equal To Comparison Operator\n");
                i++;
            } else {
                printf("Greater Than Comparison Operator\n");
            }
        } else if (input[i] == '&') {
            if (input[i+1] == '&') {
                printf("Logical AND Operator\n");
                i++;
            } else if (input[i+1] == '=') {
                printf("Bitwise AND Assignment Operator\n");
                i++;
            } else {
                printf("Bitwise AND Operator\n");
            }
        } else if (input[i] == '|') {
            if (input[i+1] == '|') {
                printf("Logical OR Operator\n");
                i++;
            } else if (input[i+1] == '=') {
                printf("Bitwise OR Assignment Operator\n");
                i++;
            } else {
                printf("Bitwise OR Operator\n");
            }
        } else if (input[i] == '^') {
            if (input[i+1] == '=') {
                printf("Bitwise XOR Assignment Operator\n");
                i++;
            } else {
                printf("Bitwise XOR Operator\n");
            }
        } else if (input[i] == '+') {
            if (isdigit(input[i+1])) {
                j = 0;
                token[j++] = input[i++];
                while (isdigit(input[i])) {
                    token[j++] = input[i++];
                }
                token[j] = '\0';
                printf("Integer Constant: %s\n", token);
            } else if (input[i+1] == '=') {
                printf("Addition Assignment Operator\n");
                i++;
            } else if (input[i+1] == '+') {
                printf("Increment Operator\n");
                i++;
            } else {
                printf("Addition Operator\n");
            }
        } else if (input[i] == '-') {
            if (isdigit(input[i+1])) {
                j = 0;
                token[j++] = input[i++];
                while (isdigit(input[i])) {
                    token[j++] = input[i++];
                }
                token[j] = '\0';
                printf("Integer Constant: %s\n", token);
            } else if (input[i+1] == '=') {
                printf("Subtraction Assignment Operator\n");
                i++;
            } else if (input[i+1] == '-') {
                printf("Decrement Operator\n");
                i++;
            } else {
                printf("Subtraction Operator\n");
            }
        } else if (isdigit(input[i])) {
            j = 0;
            token[j++] = input[i++];
            while (isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("Integer Constant: %s\n", token);
        } else if (isalpha(input[i]) || input[i] == '_') {
            j = 0;
            token[j++] = input[i++];
            while (isalpha(input[i]) || isdigit(input[i]) || input[i] == '_') {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            if (strcmp(token, "if") == 0) {
                printf("If Keyword\n");
            } else if (strcmp(token, "else") == 0) {
                printf("Else Keyword\n");
            } else if (strcmp(token, "switch") == 0) {
                printf("Switch Keyword\n");
            } else if (strcmp(token, "case") == 0) {
                printf("Case Keyword\n");
            } else if (strcmp(token, "default") == 0) {
                printf("Default Keyword\n");
            } else if (strcmp(token, "for") == 0) {
                printf("For Keyword\n");
            } else if (strcmp(token, "while") == 0) {
                printf("While Keyword\n");
            } else if (strcmp(token, "do") == 0) {
                printf("Do-While Keyword\n");
            } else if (strcmp(token, "break") == 0) {
                printf("Break Keyword\n");
            } else if (strcmp(token, "continue") == 0) {
                printf("Continue Keyword\n");
            } else if (strcmp(token, "return") == 0) {
                printf("Return Keyword\n");
            } else if (strcmp(token, "int") == 0) {
                printf("Int Type\n");
            } else if (strcmp(token, "char") == 0) {
                printf("Char Type\n");
            } else {
                printf("Identifier: %s\n", token);
            }
        } else {
            printf("Invalid Character\n");
            break;
        }
        i++;
    }

    return 0;
}