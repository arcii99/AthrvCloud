//FormAI DATASET v1.0 Category: Syntax parsing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Enter a C syntax code snippet: ");
    fgets(input, 100, stdin);  // read input from user
    int length = strlen(input);
    char *tokens[length/2]; // array of tokens
    int index = 0;

    char delimiter[] = " ,;(){}[]"; // delimiters
    char *token = strtok(input, delimiter);
    while (token != NULL) {
        tokens[index++] = token;
        token = strtok(NULL, delimiter); // get the next token
    }

    printf("Tokens: ");
    for (int i = 0; i < index; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");

    // Syntax validation
    for (int i = 0; i < index; i++) {
        if (!strcmp(tokens[i], "int") || !strcmp(tokens[i], "float") || !strcmp(tokens[i], "double") ||
           !strcmp(tokens[i], "char") || !strcmp(tokens[i], "void")) {
            if (isalpha(tokens[i+1][0])) {
                printf("%s is a valid data type.\n", tokens[i]);
            } else {
                printf("Error: invalid variable name after %s\n", tokens[i]);
            }
        } else if (!strcmp(tokens[i], "(")) {
            if (!strcmp(tokens[i+1], "int") || !strcmp(tokens[i+1], "float") || !strcmp(tokens[i+1], "double") || 
                !strcmp(tokens[i+1], "char") || !strcmp(tokens[i+1], "void") || isalpha(tokens[i+1][0])) {
                printf("Function declaration is valid.\n");
            } else {
                printf("Error: invalid function declaration.\n");
            }
        } else if (!strcmp(tokens[i], "if") || !strcmp(tokens[i], "else") || !strcmp(tokens[i], "while") || 
                   !strcmp(tokens[i], "for")) {
            if (!strcmp(tokens[i+1], "(")) {
                printf("Syntax is valid.\n");
            } else {
                printf("Error: invalid syntax after %s.\n", tokens[i]);
            }
        } else if (isdigit(tokens[i][0])) {
            printf("%s is a valid integer or float.\n", tokens[i]);
        }
    }

    return 0;
}