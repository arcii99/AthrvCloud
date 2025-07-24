//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: mind-bending
#include<stdio.h>

void main(){
    printf("Welcome to the Alien Language Translator!\n");
    int num_symbols = 0;
    char symbols[50];
    char alien_word[50];
    char translated_word[50];
    
    printf("\n\nHow many symbols does your alien language use? (Maximum 50): ");
    scanf("%d", &num_symbols);
    
    if(num_symbols <= 0){
        printf("\n\nInvalid number of symbols. Exiting program.\n");
        return;
    }
    
    printf("\n\nEnter the symbols of your alien language, separated by spaces: ");
    for(int i=0; i<num_symbols; i++){
        scanf(" %c", &symbols[i]);
    }
    
    printf("\n\nYour alien language uses the following symbols: ");
    for(int i=0; i<num_symbols; i++){
        printf("%c ", symbols[i]);
    }
    
    printf("\n\nEnter the word you want to translate: ");
    scanf("%s", &alien_word);
    
    printf("\n\nTranslating...\n");

    for(int i=0; i<strlen(alien_word); i++){
        for(int j=0; j<num_symbols; j++){
            if(alien_word[i] == symbols[j]){
                translated_word[i] = (char)(j+'A');
                break;
            }
        }
    }
    
    printf("\n\nThe translated word is: %s", translated_word);
    printf("\n\nThank you for using the Alien Language Translator!\n");
}