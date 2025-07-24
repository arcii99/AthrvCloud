//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <string.h>

char translate(char* alienWord){ 
    //alien language translator function
    char humanWord[50];

    if(strcmp(alienWord, "I love you") == 0){
         strcpy(humanWord, "You are my everything, my love");
    }
    else if(strcmp(alienWord, "Will you marry me?") == 0){
         strcpy(humanWord, "Yes, I would love to spend my life with you");
    } 
    else if(strcmp(alienWord, "You are beautiful") == 0){
         strcpy(humanWord, "You are the most stunning creature I have ever laid eyes upon");
    }
    //Add more translations as per requirements

    return humanWord;
}

int main(){ 
    char alienWord[50];

    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter the alien word you want to translate: ");
    scanf("%s", alienWord);

    printf("\nThe human word for '%s' is: %s", alienWord, translate(alienWord));

    return 0; 
}