//FormAI DATASET v1.0 Category: Syntax parsing ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// A simple parser for C syntax

int main(){

    char str[100];
    char *token;

    printf("Enter a line of C syntax: ");
    fgets(str, 100, stdin);

    // tokenize the string
    token = strtok(str, " \t\n");

    while(token != NULL){
        // check for keywords
        if(strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0
                || strcmp(token, "double") == 0 || strcmp(token, "void") == 0){
            printf("<keyword> %s </keyword>\n", token);
        }
        // check for identifiers
        else if(*token >= 'a' && *token <= 'z'){
            printf("<identifier> %s </identifier>\n", token);
        }
        // check for constants
        else if(*token >= '0' && *token <= '9'){
            printf("<constant> %s </constant>\n", token);
        }
        // check for operators
        else if(strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0
                || strcmp(token, "/") == 0 || strcmp(token, "=") == 0 || strcmp(token, "==") == 0
                || strcmp(token, ">") == 0 || strcmp(token, "<") == 0){
            printf("<operator> %s </operator>\n", token);
        }
        // check for punctuations
        else if(strcmp(token, ";") == 0 || strcmp(token, ",") == 0 || strcmp(token, "(") == 0
                || strcmp(token, ")") == 0 || strcmp(token, "{") == 0 || strcmp(token, "}") == 0){
            printf("<punctuation> %s </punctuation>\n", token);
        }

        // get next token
        token = strtok(NULL, " \t\n");
    }

    return 0;
}