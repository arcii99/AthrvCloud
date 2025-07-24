//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Linus Torvalds
#include <stdio.h>

// Define the Alien Language struct
struct AlienLanguage {
    char vowels[5];
};

// Define a function to translate words to Alien Language
void translateToAlienLanguage(const char* word, const struct AlienLanguage* alienLanguage) {
    char translatedWord[100];
    int i = 0;
    while (word[i] != '\0') {
        if (word[i] == alienLanguage->vowels[0]
            || word[i] == alienLanguage->vowels[1]
            || word[i] == alienLanguage->vowels[2]
            || word[i] == alienLanguage->vowels[3]
            || word[i] == alienLanguage->vowels[4]) {
                // Translate the vowel to 'E'
                translatedWord[i] = 'E';
            }
        else {
            // Keep the original consonant
            translatedWord[i] = word[i];
        }
        i++;
    }
    // Make sure to terminate the string correctly
    translatedWord[i] = '\0';
    printf("Translated word: %s\n", translatedWord);
}

int main() {
    // Define the Alien Language object with vowels a, e, i, o, u
    struct AlienLanguage alienLanguage = {"aeiou"};

    // Translate the word "Hello"
    translateToAlienLanguage("Hello", &alienLanguage);

    // Translate the word "Linux Torvalds"
    translateToAlienLanguage("Linux Torvalds", &alienLanguage);

    return 0;
}