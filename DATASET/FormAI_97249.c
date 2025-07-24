//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char alienWord[50], translatedWord[50];

    printf("Welcome to the C Alien Language Translator Program!\n");
    printf("Enter the Alien word you want to translate: ");
    scanf("%s", alienWord);

    // check if the first character is a vowel
    if (alienWord[0] == 'a' || alienWord[0] == 'e' || alienWord[0] == 'i' || alienWord[0] == 'o' || alienWord[0] == 'u') {

        // if the first character is a vowel, add "min" to the beginning of the word
        strcpy(translatedWord, "min");
        strcat(translatedWord, alienWord);

    } else {

        // if the first character is a consonant, move it to the end of the word and add "ith" at the end
        int len = strlen(alienWord);
        strcpy(translatedWord, alienWord + 1);
        translatedWord[len - 1] = alienWord[0];
        strcat(translatedWord, "ith");
    }
    
    printf("The translated word is: %s\n", translatedWord);
    printf("Thank you for using the C Alien Language Translator!\n");

    return 0;
}