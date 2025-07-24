//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void parse_expression(char *expr);

int main(){
    char *expr;
    
    printf("Enter an expression: ");
    scanf("%[^\n]", expr);

    parse_expression(expr);
    
    return 0;
}

void parse_expression(char *expr){
    int i, len;
    len = strlen(expr);
    
    printf("Syntax: ");
    for(i=0;i<len;i++){
        if(isdigit(expr[i])){
            while(isdigit(expr[i+1]))
                i++;
            printf("<number>");
        }
        else if(isalpha(expr[i])){
            while(isalpha(expr[i+1]))
                i++;
            printf("<variable>");
        }
        else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '%'){
            printf("<operator>");
        }
        else if(expr[i] == '(' || expr[i] == ')'){
            printf("<parenthesis>");
        }
        else if(expr[i] == ' '){
            continue;
        }
        else {
            printf("<unknown>");
        }
    }
}