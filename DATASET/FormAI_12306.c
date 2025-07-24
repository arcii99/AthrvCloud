//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* This program translates English words to the unique C Alien Language. */

void translateWord(char* word){
    int length = strlen(word);
    bool vowel = false;
    int i;
    for(i = 0; i < length; i++){
        char currentChar = word[i];
        if(currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u'){
            vowel = true;
            printf("CWO");
        }
        else{
            printf("%c", tolower(currentChar));
        }
    }
    if(vowel){
        printf("POTATO");
    }
}

int main(){
    char word[30];
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Enter a word in English to translate to C Alien Language: ");
    scanf("%s", word);
    printf("The word \"%s\" translated to C Alien Language is: ", word);
    translateWord(word);
    return 0;
}