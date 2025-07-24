//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char alienLanguage[] = {'K', 'D', 'T', 'O', 'E', 'A', 'G', 'S', 'W', '\0'};
char englishLanguage[] = {'R', 'E', 'A', 'L', 'O', 'V', 'E', 'I', 'S', '\0'};

char* alienTranslator(char* phrase) {
    char* lovePhrase = malloc(strlen(phrase) + 1);
    strcpy(lovePhrase, phrase);

    for(int i = 0; i < strlen(lovePhrase); i++) {
        for(int j = 0; j < strlen(alienLanguage); j++) {
            if(toupper(lovePhrase[i]) == alienLanguage[j]) {
                lovePhrase[i] = englishLanguage[j];
                break;
            }
        }
    }

    return lovePhrase;
}

int main() {
    char phrase[MAX];
    printf("Enter a phrase in Alien language: ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = 0;

    char* lovePhrase = alienTranslator(phrase);
    printf("\nYour phrase translated with love is: %s\n", lovePhrase);

    free(lovePhrase);
    return 0;
}