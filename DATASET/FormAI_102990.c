//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <string.h>

// function to translate input string to Alien language
void translateAlienLanguage(char inputString[]) {
    int i, j, k;
    char currentChar, currentWord[20];
    int currentWordIndex = 0;

    for(i=0; i<strlen(inputString); i++) {
        currentChar = inputString[i];
        
        // check for new word
        if(currentChar == ' ') {
            // process current word and reset variables
            for(j=0; j<currentWordIndex; j++) {
                for(k=0; k<j+1; k++) {
                    printf("*");
                }
                printf("%c", currentWord[j]);
                printf(" ");
            }

            // reset variables for new word
            currentWordIndex = 0;
            memset(currentWord, 0, sizeof(currentWord));
        } else {
            // add current character to current word
            currentWord[currentWordIndex] = currentChar;
            currentWordIndex++;
        }
    }

    // process last word
    for(j=0; j<currentWordIndex; j++) {
        for(k=0; k<j+1; k++) {
            printf("*");
        }
        printf("%c", currentWord[j]);
        printf(" ");
    }
}

int main() {
    char inputString[100];

    printf("Enter string in Alien language: ");
    fgets(inputString, sizeof(inputString), stdin);

    printf("Translated to English: ");
    translateAlienLanguage(inputString);

    return 0;
}