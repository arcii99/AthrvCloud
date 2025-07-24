//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define ALIEN_LANGUAGE_LENGTH 10

char alienLanguage[ALIEN_LANGUAGE_LENGTH] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

/* Function that translates an English word to Alien Language */
void englishToAlienTranslator(char *englishWord) {
    int j, k;
    for (int i = 0; i < strlen(englishWord); i++) {
        j = 0;
        k = 0;
        for (j = 0; j < 26; j++) {
            if (englishWord[i] == ' ') {
                printf(" ");
                k = ALIEN_LANGUAGE_LENGTH;
                break;
            } else if (englishWord[i] == 'z') {
                printf("%c", alienLanguage[9]);
                k = ALIEN_LANGUAGE_LENGTH;
                break;
            } else if (englishWord[i] == 'Z') {
                printf("%c", toupper(alienLanguage[9]));
                k = ALIEN_LANGUAGE_LENGTH;
                break;
            } else if (englishWord[i] == ((char)('a' + j))) {
                printf("%c", alienLanguage[j]);
                k = ALIEN_LANGUAGE_LENGTH;
                break;
            } else if (englishWord[i] == ((char)('A' + j))) {
                printf("%c", toupper(alienLanguage[j]));
                k = ALIEN_LANGUAGE_LENGTH;
                break;
            } else continue;
        }
        if (k < ALIEN_LANGUAGE_LENGTH) {
            printf("%c", englishWord[i]);
        }
    }
}

/* Main function that demonstrates the Alien Translator */
int main() {
    printf("Welcome to the Alien Language Translator!\n");
    char englishWord[50];
    printf("\nEnter an English word to translate: ");
    fgets(englishWord, 50, stdin);
    printf("\nAlien Translation: ");
    englishToAlienTranslator(englishWord);
    printf("\n");
    return 0;
}