//FormAI DATASET v1.0 Category: Syntax parsing ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//Function to check if a given string is a keyword
int isKeyword(char* word){
    char keywords[32][10] = { "auto", "break", "case", "char", "const", "continue", "default",
                          "do", "double", "else", "enum", "extern", "float", "for", "goto",
                          "if", "int", "long", "register", "return", "short", "signed",
                          "sizeof", "static", "struct", "switch", "typedef", "union",
                          "unsigned", "void", "volatile", "while"};
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
   int i, j = 0;

   fp = fopen("program.c","r");

   if(fp == NULL){
       printf("Error: Unable to open file \n");
       exit(0);
   }

   printf("\nKeywords:\n");

   while((ch = fgetc(fp)) != EOF){
       for(i = 0; i < 6; ++i){
           if(ch == operators[i]){
                printf("\nOperator: %c\n", ch);
           }
       }

       if(isalnum(ch)){
           buffer[j++] = ch;
       }
       else if((ch == ' ' || ch == '\n') && (j != 0)) {
           buffer[j] = '\0';
           j = 0;
           if(isKeyword(buffer) == 1){
                printf("\nKeyword: %s\n", buffer);
           }
           else {
                printf("\nIdentifier: %s\n", buffer);
           }
       }

   }

   fclose(fp);
   return 0;
}