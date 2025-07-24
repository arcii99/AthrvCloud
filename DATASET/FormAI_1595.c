//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAXLEN 100

char *token[MAXLEN];
int tokenIndex = 0;

void tokenize(char *code) {
    char *p = strtok(code, " ");
    while(p!=NULL) {
        token[tokenIndex++] = p;
        p = strtok(NULL, " ");
    }
}

void parse(char *code) {
    int i;
    for(i=0;i<tokenIndex;i++) {
        if(isalpha(token[i][0]))
            printf("Identifier: %s\n",token[i]);
        else if(isdigit(token[i][0]))
            printf("Number: %s\n",token[i]);
        else if(strcmp(token[i],"+")==0 || strcmp(token[i],"-")==0 || strcmp(token[i],"*")==0 || strcmp(token[i],"/")==0)
            printf("Operator: %s\n",token[i]);
        else if(strcmp(token[i],"(")==0)
            printf("Left Parenthesis: %s\n",token[i]);
        else if(strcmp(token[i],")")==0)
            printf("Right Parenthesis: %s\n",token[i]);
        else
            printf("Unknown Token: %s\n",token[i]);
    }
}

int main() {
    char code[MAXLEN];
    printf("Enter C code: \n");
    fgets(code, MAXLEN, stdin);
    tokenize(code);
    parse(code);
    return 0;
}