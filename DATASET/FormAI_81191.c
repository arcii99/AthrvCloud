//FormAI DATASET v1.0 Category: Syntax parsing ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* keywords[] = {"int", "float", "char", "double", "long", "if", "else", "for", "while", "do", "switch", "case", "break", "continue", "return"};

int keywordCount = 15;

int isKeyword(char*word){
    for(int i=0; i<keywordCount; i++){
        if(strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}

int main(){
    char program[1000];
    char word[50];

    printf("Enter your C program:\n");
    fgets(program, 1000, stdin);

    printf("\n\n---TOKENS---\n");

    int programLength = strlen(program);
    int index = 0;

    while(index < programLength){
        int wordIndex = 0;
        char currentChar = program[index];

        while(currentChar != ' ' && currentChar != '\n' && currentChar != ';' && currentChar != '{' && currentChar != '}'){
            word[wordIndex++] = currentChar;
            currentChar = program[++index];
        }

        word[wordIndex] = '\0';

        if(strlen(word) > 0){
            if(isKeyword(word))
                printf("Keyword: %s\n", word);
            else
                printf("Identifier: %s\n", word);
        }

        index++;
    }

    return 0;
}