//FormAI DATASET v1.0 Category: Syntax parsing ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_TOKEN_LENGTH 100

char* keywords[] = {"break", "continue", "else", "if", "int", "return", "void", "while"};
char* symbols[] = {"+", "-", "*", "/", "<", "<=", ">", ">=", "==", "!=", "=", ";", ",", "(", ")", "{", "}", "[", "]"};

int isKeyword(char* token){

    int num_keywords = sizeof(keywords) / sizeof(char*);
    int i;
    for(i = 0; i < num_keywords; i++){
        if(strcmp(keywords[i], token) == 0){
            return 1;
        }
    }
    return 0;
}

int isSymbol(char* token){

    int num_symbols = sizeof(symbols) / sizeof(char*);
    int i;
    for(i = 0; i < num_symbols; i++){
        if(strcmp(symbols[i], token) == 0){
            return 1;
        }
    }
    return 0;
}

int isIdentifier(char* token){
 
    if(!isalpha(token[0])){
        return 0;
    }

    int num_chars = strlen(token);
    int i;
    for(i = 1; i < num_chars; i++){
        if(!isalnum(token[i]) && token[i] != '_'){
            return 0;
        }
    }
    return 1;
}

int isNumber(char* token){

    int num_chars = strlen(token);
    int i;
    for(i = 0; i < num_chars; i++){
        if(!isdigit(token[i])){
            return 0;
        }
    }
    return 1;
}

void parse(char* program){

    char* token;
    int len_program = strlen(program);
    int i = 0;

    while(i < len_program){
        token = (char*) malloc(MAX_TOKEN_LENGTH * sizeof(char));
        int j = 0;
        while(program[i] == ' ' || program[i] == '\n' || program[i] == '\t'){
            i++;
        }
        if(isalpha(program[i])){
            while(isalnum(program[i]) || program[i] == '_'){
                token[j] = program[i];
                i++; j++;
            }
            token[j] = '\0';
            if(isKeyword(token)){
                printf("%s is a keyword\n", token);
            }
            else{
                printf("%s is an identifier\n", token);
            }
        }
        else if(isSymbol(&program[i])){
            strncpy(token, &program[i], 1);
            token[1] = '\0';
            printf("%s is a symbol\n", token);
            i++;
        }
        else if(isdigit(program[i])){
            while(isdigit(program[i])){
                token[j] = program[i];
                i++; j++;
            }
            token[j] = '\0';
            printf("%s is a number\n", token);
        }
        else{
            printf("Invalid Token\n");
            i++;
        }
        free(token);
    }
}

int main(){
    char program[500] = "int main(){\n    int a = 1, b = 2;\n    if(a > b){\n        printf(\"a is greater than b\");\n    }\n    else{\n        printf(\"b is greater than a\");\n    }\n    return 0;\n}";
    printf("The program is: \n%s\n\n", program);
    printf("The tokens are: \n");
    parse(program);
    return 0;
}