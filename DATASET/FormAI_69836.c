//FormAI DATASET v1.0 Category: Syntax parsing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to check if input character is a letter or digit
int isLetterOrDigit(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return 1;
    else
        return 0;
}

//Function to check if input character is a valid whitespace character
int isWhitespace(char c) {
    if(c == ' ' || c == '\t' || c == '\n' || c == '\r')
        return 1;
    else
        return 0;
}

//Function to check if input token is a valid keyword
int isKeyword(char* token) {
    char keywords[32][10] = {"int", "float", "char", "if", "else", "while", "for", "do", "switch", "case", "break", "continue", "void"};
    int i;
    for(i = 0; i < 13; i++) {
        if(strcmp(keywords[i], token) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[1000];
    printf("Enter the C program:\n");
    fgets(input, 1000, stdin);
    int length = strlen(input);
    char token[50];
    int i = 0, j = 0;
    while(i < length) {
        if(isLetterOrDigit(input[i])) {
            while(isLetterOrDigit(input[i])) {
                token[j] = input[i];
                i++;
                j++;
            }
            token[j] = '\0';
            if(isKeyword(token))
                printf("Keyword: %s\n", token);
            else
                printf("Identifier: %s\n", token);
            j = 0;
            memset(token, 0, sizeof(token)); //Clear token array for future use
        }
        else if(isWhitespace(input[i])) {
            i++;
        }
        else {
            token[0] = input[i];
            if(input[i] == '/' && input[i+1] == '/') { //If comment
                while(input[i] != '\n')
                    i++;
                j = 0;
                memset(token, 0, sizeof(token)); //Clear token array for future use
            }
            else if(input[i] == '/' && input[i+1] == '*') { //If comment
                i += 2;
                while(input[i] != '*' || input[i+1] != '/') {
                    i++;
                    if(i == length - 1) {
                        printf("Error: Unterminated Multi-line Comment\n");
                        return 1;
                    }
                }
                i += 2;
                j = 0;
                memset(token, 0, sizeof(token)); //Clear token array for future use
            }
            else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '<' || input[i] == '>' || input[i] == '=' || input[i] == '&' || input[i] == '|' || input[i] == '!' || input[i] == '~' || (input[i] == '^' && input[i+1] != '^')) {
                if(input[i+1] == '=') { //If comparison operator or assignment operator
                    token[1] = '=';
                    token[2] = '\0';
                    printf("Operator: %s\n", token);
                    i += 2;
                }
                else if((input[i] == '<' && input[i+1] == '<') || (input[i] == '>' && input[i+1] == '>') || (input[i] == '&' && input[i+1] == '&') || (input[i] == '|' && input[i+1] == '|')) {
                    token[1] = input[i+1];
                    token[2] = '\0';
                    printf("Operator: %s\n", token);
                    i += 2;
                }
                else { //If single operator or bitwise operator or not operator (in case of !)
                    token[1] = '\0';
                    printf("Operator: %s\n", token);
                    i++;
                }
                j = 0;
                memset(token, 0, sizeof(token)); //Clear token array for future use
            }
            else if(input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}' || input[i] == '[' || input[i] == ']') {
                token[1] = '\0';
                printf("Special Character: %s\n", token);
                i++;
                j = 0;
                memset(token, 0, sizeof(token)); //Clear token array for future use
            }
            else if(input[i] == ',' || input[i] == ';' || input[i] == ':') {
                token[1] = '\0';
                printf("Punctuation: %s\n", token);
                i++;
                j = 0;
                memset(token, 0, sizeof(token)); //Clear token array for future use
            }
            else {
                printf("Error: Invalid Character: %c\n", input[i]);
                return 1;
            }
        }
    }
    return 0;
}