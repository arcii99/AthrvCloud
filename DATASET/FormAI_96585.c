//FormAI DATASET v1.0 Category: Syntax parsing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseSyntax(char code[], int length);

int main(){
    char code[100];
    printf("Enter your C code here:\n");
    fgets(code, 100, stdin);
    parseSyntax(code, strlen(code));
    return 0;
}

void parseSyntax(char code[], int length){
    char buffer[10];
    int paranCount = 0, braceCount = 0, bracketCount = 0, doubleQuoteCount = 0, singleQuoteCount = 0, commentCount = 0, i, j;

    for(i = 0; i < length; i++){
        if(code[i] == '('){
            paranCount++;
        }
        else if(code[i] == ')'){
            paranCount--;
        }
        else if(code[i] == '{'){
            braceCount++;
        }
        else if(code[i] == '}'){
            braceCount--;
        }
        else if(code[i] == '['){
            bracketCount++;
        }
        else if(code[i] == ']'){
            bracketCount--;
        }
        else if(code[i] == '\"'){
            doubleQuoteCount++;
        }
        else if(code[i] == '\''){
            singleQuoteCount++;
        }
        else if(code[i] == '/'){
            if(code[i + 1] == '/'){
                commentCount++;
            }
        }
        else if(code[i] == '*' && code[i + 1] == '/'){
            commentCount--;
        }
    }

    if(paranCount != 0){
        printf("Syntax Error: Parantheses mismatch\n");
        exit(0);
    }
    else if(braceCount != 0){
        printf("Syntax Error: Braces mismatch\n");
        exit(0);
    }
    else if(bracketCount != 0){
        printf("Syntax Error: Brackets mismatch\n");
        exit(0);
    }
    else if(doubleQuoteCount % 2 != 0){
        printf("Syntax Error: Double Quotes mismatch\n");
        exit(0);
    }
    else if(singleQuoteCount % 2 != 0){
        printf("Syntax Error: Single Quotes mismatch\n");
        exit(0);
    }
    else if(commentCount != 0){
        printf("Syntax Error: Comment mismatch\n");
        exit(0);
    }
    else{
        printf("Syntax has been parsed successfully!\n");
    }
}