//FormAI DATASET v1.0 Category: Syntax parsing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

void parseSyntax(char *input) {
    char *token, *prevToken = "";
    int isVarDeclared = 0, isVarInitialized = 0, isPrevTokenVarType = 0;
    const char *delimiters = " ();={}\n\t";

    //parse tokens
    token = strtok(input, delimiters);
    while(token != NULL) {
        //check for variable declaration
        if(strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0) {
            if(isPrevTokenVarType == 1) {
                printf("Invalid syntax: multiple variable types declared in same line\n");
                return;
            }
            isVarDeclared = 1;
            isPrevTokenVarType = 1;
        }
        //check for variable initialization
        else if(strcmp(prevToken, "=") == 0 && isalpha(token[0])) {
            if(isVarInitialized == 1) {
                printf("Invalid syntax: variable initialized twice\n");
                return;
            }
            isVarInitialized = 1;
        }
        //check for function definition
        else if(strcmp(prevToken, "(") == 0 && strcmp(token, ")") != 0) {
            printf("Function definition: %s\n", prevToken);
            return;
        }
        
        prevToken = token;
        token = strtok(NULL, delimiters);
    }

    //check if variable is declared but not initialized
    if(isVarDeclared == 1 && isVarInitialized == 0) {
        printf("Invalid syntax: variable declared but not initialized\n");
        return;
    }

    printf("Syntax is valid\n");
}

int main() {
    char input[MAX_LEN];

    printf("Enter code line: ");
    fgets(input, MAX_LEN, stdin);

    parseSyntax(input);

    return 0;
}