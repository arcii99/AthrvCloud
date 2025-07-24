//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Claude Shannon
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLEN 1000

int main(){
    char code[MAXLEN];
    char operators[] = "+-*/%=";
    char breakers[]  = "(,)";
    int numops = strlen(operators);
    int numb = strlen(breakers);
    int len = 0;

    printf("Enter a C program code:\n");

    while((len < MAXLEN) && ((code[len++] = getchar()) != EOF));

    if(len >= MAXLEN){
        printf("ERROR: Input exceeds maximum program length.");
        return 1;
    }

    printf("Operators found:\n");

    for(int i = 0; i < len; i++){
        char c = code[i];
        if(strchr(operators, c)) printf("%c\n", c);
    }

    printf("Breakers found:\n");

    for(int i = 0; i < len; i++){
        char c = code[i];
        if(strchr(breakers, c)) printf("%c\n", c);
    }

    printf("Alphabetic identifiers found:\n");

    for(int i = 0; i < len; i++){
        char c = code[i];
        if(isalpha(c)){
            char identifier[MAXLEN];
            int j = 0;
            identifier[j++] = c;

            for(i++; isalnum(code[i]) || (code[i] == '_'); i++){
                identifier[j++] = code[i];
            }

            identifier[j] = '\0';
            printf("%s\n", identifier);
        }
    }

    return 0;
}