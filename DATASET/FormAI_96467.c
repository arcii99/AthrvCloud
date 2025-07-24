//FormAI DATASET v1.0 Category: Syntax parsing ; Style: satisfied
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){

    char code[100];
    int flag=0;

    printf("Enter your C code snippet:\n");
    fgets(code, 100, stdin);

    //Converting all characters to lowercase
    for(int i=0; i<strlen(code); i++){
        code[i] = tolower(code[i]);
    }

    //Parsing the code for syntax errors
    for(int i=0; i<strlen(code)-1; i++){
        //Checking for missing semicolons
        if(code[i] == ';' && code[i+1] == ' '){
            printf("Missing semicolon at position %d\n", i);
            flag = 1;
        }
        //Checking for missing curly braces
        else if(code[i] == '{' && code[i+1] == ' '){
            printf("Missing opening curly brace at position %d\n", i);
            flag = 1;
        }
        else if(code[i] == ' ' && code[i+1] == '}'){
            printf("Missing closing curly brace at position %d\n", i);
            flag = 1;
        }
        //Checking for invalid operators
        else if(code[i] == '&' || code[i] == '|' || code[i] == '<' || code[i] == '>' || code[i] == '='){
            if(code[i+1] != '='){
                printf("Invalid operator at position %d\n", i);
                flag = 1;
            }
        }
    }

    if(flag == 0){
        printf("No syntax errors found!\n");
    }

    return 0;
}