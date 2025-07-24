//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

void translate(char *word){
    if(strcmp(word, "hello") == 0){
        strcpy(word, "meowlo");
    }
    else if(strcmp(word, "friend") == 0){
        strcpy(word, "furrriend");
    }
    // Add more translations here
}

int main(){
    char input[100];
    printf("Enter a sentence to translate to cat language: ");
    fgets(input, 100, stdin);
    
    char *word = strtok(input, " \n");
    while(word != NULL){
        translate(word);
        printf("%s ", word);
        word = strtok(NULL, " \n");
    }
    
    return 0;
}