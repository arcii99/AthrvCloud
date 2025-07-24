//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <string.h>

int main() {
    // Arrays to store the Alien Language characters and their corresponding English translations
    char alienAlphabet[] = {'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};
    char englishAlphabet[] = {'a', 'e', 'i', 'o', 'u', 'y', 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'r'};

    // Variables to store user input and translated output
    char alienWord[100];
    char englishWord[100];
    
    // Prompt the user to enter an Alien Language word
    printf("Enter an Alien Language word: ");
    scanf("%s", alienWord);

    // Loop through each character in the Alien Language word
    for (int i = 0; i < strlen(alienWord); i++) {
        // Variable to check if the character has been translated
        int translated = 0;

        // Loop through each character in the Alien Language alphabet
        for (int j = 0; j < strlen(alienAlphabet); j++) {
            // If the current character in the Alien Language word matches the current character in the Alien Language alphabet
            if (alienWord[i] == alienAlphabet[j]) {
                // Translate the character to English
                englishWord[i] = englishAlphabet[j];
                translated = 1;
                break;
            }
        }

        // If the character was not translated, copy it over to the output word
        if (translated == 0) {
            englishWord[i] = alienWord[i];
        }
    }

    // Output the translated word
    printf("The translated word is: %s\n", englishWord);

    return 0;
}