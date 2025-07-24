//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the alien language dictionary
char alienLang[4][10] = {"blorg", "flarb", "snick", "ploob"};

// Define the English translation dictionary
char english[4][10] = {"hello", "goodbye", "please", "thankyou"};

// Function to check if given string is an alien language word
bool isAlienWord(char *word) {
    int i;
    for(i = 0; i < 4; i++) {
        if(strcmp(word, alienLang[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to translate the given alien language sentence to english
void translateToEnglish(char *alienLangSentence, char *englishSentence) {
    int i, j, startIndex = 0, endIndex;
    char word[10];
    for(i = 0; alienLangSentence[i] != '\0'; i++) {
        if(alienLangSentence[i] == ' ') {
            endIndex = i - 1;
            // Extract the word from startIndex to endIndex
            int k = 0;
            for(j = startIndex; j <= endIndex; j++) {
                word[k++] = alienLangSentence[j];
            }
            word[k] = '\0';
            // Check if word is an alien word and replace with english translation
            if(isAlienWord(word)) {
                int index = 0;
                while(strcmp(word, alienLang[index]) != 0) {
                    index++;
                }
                strcat(englishSentence, english[index]);
                strcat(englishSentence, " ");
            } else {
                // If word is not an alien word, append as it is to the English sentence
                strcat(englishSentence, word);
                strcat(englishSentence, " ");
            }
            startIndex = i + 1;
        }
    }
    endIndex = i - 1;
    // Extract last word
    int k = 0;
    for(j = startIndex; j <= endIndex; j++) {
        word[k++] = alienLangSentence[j];
    }
    word[k] = '\0';
    // Check if word is an alien word and replace with english translation
    if(isAlienWord(word)) {
        int index = 0;
        while(strcmp(word, alienLang[index]) != 0) {
            index++;
        }
        strcat(englishSentence, english[index]);
    } else {
        // If word is not an alien word, append as it is to the English sentence in camelCase
        int len = strlen(word);
        for(i = 0; i < len; i++) {
            if(i % 2 == 0) {
                word[i] = toupper(word[i]);
            } else {
                word[i] = tolower(word[i]);
            }
        }
        strcat(englishSentence, word);
    }
}

int main() {
    // Declare variables
    char alienLangSentence[100], englishSentence[100];
    
    // Get input from user
    printf("Enter a sentence in alien language: ");
    fgets(alienLangSentence, sizeof(alienLangSentence), stdin);
    
    // Translate the given alien language sentence to english
    translateToEnglish(alienLangSentence, englishSentence);
    
    // Print the translated sentence
    printf("\nTranslated sentence: %s\n", englishSentence);
    
    return 0;
}