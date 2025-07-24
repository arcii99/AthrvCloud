//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: standalone
#include <stdio.h>
#include <string.h>

// Function to translate phrases or sentences from English to C Cat Language
void englishToCCatLanguage(char phrase[]){
    int length = strlen(phrase);
    char ccatPhrase[length + 1];

    for(int i = 0; i < length; i++){
        if(phrase[i] == 'a' || phrase[i] == 'e' || phrase[i] == 'i' || phrase[i] == 'o' || phrase[i] == 'u'){
            ccatPhrase[i] = 'c';
            ccatPhrase[i+1] = phrase[i];
            i++;
        } else{
            ccatPhrase[i] = phrase[i];
        }
    }

    printf("\nC Cat Translation: %s\n", ccatPhrase);
}

// Example program using the English to C Cat Language Translator function
int main(){
    char phrase[100];

    printf("Welcome to the English to C Cat Language Translator!\n");
    printf("Please enter a word or phrase to translate: ");

    fgets(phrase, 100, stdin);
    phrase[strcspn(phrase, "\n")] = 0;

    englishToCCatLanguage(phrase);

    return 0;
}