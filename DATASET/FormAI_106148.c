//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* alienTranslator(char* phrase){

    if(phrase == NULL){
        return NULL;
    }

    int len = strlen(phrase);

    if(len < 1){
        return phrase;
    }

    int i;
    char *result = (char*)malloc(sizeof(char) * (len + 1));
    char *c;

    for(i = 0, c = result; i < len; i++, c++){
        if(phrase[i] == 'a'){
            *c = 'e';
        }else if(phrase[i] == 'b'){
            *c = 'f';          
        }else if(phrase[i] == 'c'){
            *c = 'g';
        }else if(phrase[i] == 'd'){
            *c = 'h';
        }else if(phrase[i] == 'e'){
            *c = 'a';
        }else if(phrase[i] == 'f'){
            *c = 'b';
        }else if(phrase[i] == 'g'){
            *c = 'c';
        }else if(phrase[i] == 'h'){
            *c = 'd';
        }else{
            *c = phrase[i];
        }
    }

    *c = '\0';
    return result;
}

int main(){
    char phrase[100];
    printf("Enter a phrase in alien language: ");
    scanf("%s", phrase);
    char *result = alienTranslator(phrase);
    printf("%s\n", result);
    free(result);
    return 0;
}