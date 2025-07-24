//FormAI DATASET v1.0 Category: Syntax parsing ; Style: light-weight
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *keywords[] = {"if", "else", "for", "while", "int", "float", "double", "char", "void",
                    "return", "break", "continue", "do", "switch", "case", "default"};

char *operators[] = {">", "<", ">=", "<=", "==", "!="};

int isKeyword(char *word) {
    for(int i = 0; i < 16; i++) {
        if(strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char *word) {
    for(int i = 0; i < 6; i++) {
        if(strcmp(operators[i], word) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[100];
    printf("Enter the code to parse:\n");
    fgets(input, 100, stdin);

    char *token = strtok(input, " \n\r\t"); 
    // above line breaks the input string in tokens separated by ' ', '\n', '\r', '\t'
    // strtok function modifies the input string

    while(token != NULL) {
        if(isKeyword(token) == 1) {
            printf("%s is a keyword\n", token);
        }
        else if(isOperator(token) == 1) {
            printf("%s is an operator\n", token);
        }
        else if(*token >= '0' && *token <= '9') {
            printf("%s is a number\n", token);
        }
        else if(*token == '\'' || *token == '\"') {
            printf("%s is a string\n", token);
        }
        else {
            printf("%s is a variable or function name\n", token);
        }
        token = strtok(NULL, " \n\r\t");
    }
    return 0;
}