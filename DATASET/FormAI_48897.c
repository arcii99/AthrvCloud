//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <string.h>

/* define the possible letters in the alien language */
char alienLetters[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

/* define the corresponding translated letters in English */
char englishLetters[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j'};

int isInAlienLanguage(char letter) {
    for (int i = 0; i < strlen(alienLetters); i++) {
        if (alienLetters[i] == letter) {
            return 1; /* letter found in alien language */
        }
    }
    return 0; /* letter not found in alien language */
}

void translateWord(char* alienWord) {
    int wordLength = strlen(alienWord);
    for (int i = 0; i < wordLength; i++) {
        if (isInAlienLanguage(alienWord[i])) {
            for (int j = 0; j < strlen(alienLetters); j++) {
                if (alienLetters[j] == alienWord[i]) {
                    printf("%c", englishLetters[j]); /* print the corresponding English letter */
                    break; /* don't continue looping once the corresponding letter is found */
                }
            }
        } else {
            printf("%c", alienWord[i]); /* print the letter as is if not found in alien language */
        }
    }
    printf("\n"); /* print a newline character after each translated word */
}

int main() {
    char* exampleWords[] = {"QWER", "TYUIO", "ASDFGH", "JKLZXCVBNM", "Hello", "World"};
    int numWords = sizeof(exampleWords) / sizeof(char*); /* calculate the number of example words */
    for (int i = 0; i < numWords; i++) {
        translateWord(exampleWords[i]); /* translate each example word */
    }
    return 0;
}