//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include<stdio.h>
#include<string.h>

// Size of the alien language is customizable
#define ALIEN_LANG_SIZE 5

// Function to translate the given word into the Alien Language
void translateToAlienLanguage(char *word, char alienLanguage[ALIEN_LANG_SIZE]){
    int len = strlen(word);
    for(int i=0; i<len; i++){
        alienLanguage[i%ALIEN_LANG_SIZE] = word[i];
    }
}

int main(){
    // Alien language can be customized by changing the character array below
    char alienLanguage[ALIEN_LANG_SIZE] = {'x', 'y', 'z', 'a', 'b'};
    char word[20];
    printf("Enter a word to translate: ");
    scanf("%s", word);
    translateToAlienLanguage(word, alienLanguage);
    printf("The translated word in Alien Language is: %s\n", alienLanguage);
    return 0;
}