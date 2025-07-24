//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// alien words
char *alienWords[5] = {"zorp", "glarb", "frax", "blorg", "snikt"};

// translations
char *translations[5] = {"hello", "goodbye", "thank you", "sorry", "yes"};

// function to translate alien words to human words
void translate(char *word){
    int i;
    for(i = 0; i < 5; i++){
        if(strcmp(word, alienWords[i]) == 0){
            printf("%s\n", translations[i]);
            return;
        }
    }
    printf("I don't understand.\n");
}

// main program
int main(){
    char input[10];
    
    printf("Welcome to the C Alien Language Translator.\n\n");
    printf("Enter an alien word to translate to human language: ");
    scanf("%s", &input);
    translate(input);
    
    printf("\nThank you for using the C Alien Language Translator.\n");
    
    return 0;
}