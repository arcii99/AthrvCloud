//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: realistic
#include<stdio.h>
#include<string.h>

int main()
{
    char speak[1000];
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Please enter the alien message you wish to translate: ");
    fgets(speak, 1000, stdin); // Takes input from user and stores in 'speak' character array
 
    if(strstr(speak, "lorem") != NULL){
        printf("Translation: Hello\n");
    }
    else if(strstr(speak, "ipsum") != NULL){
        printf("Translation: Goodbye\n");
    }
    else if(strstr(speak, "dolor") != NULL){
        printf("Translation: Thank you\n");
    }
    else if(strstr(speak, "sit") != NULL){
        printf("Translation: Please\n");
    }
    else if(strstr(speak, "amet") != NULL){
        printf("Translation: Sorry\n");
    }
    else {
        printf("Translation: Unable to Translate\n");
    }
    
    return 0;
}