//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include<stdio.h>
#include<string.h>

//Function to translate alien language 
void translate(char* word){
    if(strcmp(word,"huk") == 0){
        printf("Hello\n");
    }
    if(strcmp(word,"bux") == 0){
        printf("Bye\n");
    }
    if(strcmp(word,"fluz") == 0){
        printf("Friend\n");
    }
    if(strcmp(word,"viz") == 0){
        printf("Very\n");
    }
    if(strcmp(word,"miz") == 0){
        printf("My\n");
    }
    if(strcmp(word,"liz") == 0){
        printf("Love\n");
    }
}

int main(){
    char word[20];
    printf("Welcome to C Alien Language Translator\n");
    printf("Enter the word to be translated: ");
    scanf("%s",word);
    translate(word);
    return 0;
}