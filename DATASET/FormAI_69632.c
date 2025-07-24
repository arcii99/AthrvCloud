//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a given character is a vowel in the alien language
bool isAlienVowel(char c) {
    if (c == 'x' || c == 'y' || c == 'z') {
        return true;
    }
    return false;
}

// Function to convert a word from alien language to English
void translateWord(char *alienWord, char *englishWord) {
    int length = strlen(alienWord);
    for (int i = 0; i < length; i++) {
        if (isAlienVowel(alienWord[i])) {
            englishWord[i] = 'a';
        } else {
            englishWord[i] = 'b';
        }
    }
}

int main() {
    char alienWord[20], englishWord[20];

    // Get input from the user
    printf("Enter a word in Alien Language: ");
    scanf("%s", alienWord);

    // Translate the word and print the result
    translateWord(alienWord, englishWord);
    printf("The English translation is: %s\n", englishWord);

    return 0;
}