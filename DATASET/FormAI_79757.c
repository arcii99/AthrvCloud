//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_keyword(char *word){
    char *keywords[32] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    int i, flag = 0;
    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], word) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){
    char ch, buffer[15], operators[] = "+-*/%=";
    FILE *fp;
    int buffer_count = 0, i, j;

    fp = fopen("program.txt", "r");
    if(fp == NULL){
        printf("Error opening file.");
        exit(1);
    }

    printf("Keywords:\n");
    while((ch = fgetc(fp)) != EOF){
        for(i = 0; i < 6; ++i){
            if(ch == operators[i]){
                printf("%c is operator\n", ch);
            }
        }
        if(isalnum(ch)){
            buffer[buffer_count++] = ch;
        }
        else if((ch == ' ' || ch == '\n') && (buffer_count != 0)){
            buffer[buffer_count] = '\0';
            buffer_count = 0;
            if(is_keyword(buffer) == 1){
                printf("%s is a keyword\n", buffer);
            }
            else{
                printf("%s is an identifier\n", buffer);
            }
        }
    }

    fclose(fp);
    return 0;
}