//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {
    char alienLanguage[] = "Hxhzrpftxjx yjxxffGxxLixx klmnopqrsTuVwxYzfj";
    char englishTranslation[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    char userPhrase[100];
    int translationLength = strlen(alienLanguage);

    printf("Welcome to the Alien Language Translator!\n");
    printf("Type in a phrase in alien language to see the translation:\n");

    fgets(userPhrase, sizeof(userPhrase), stdin); // Get user input

    printf("Translation: ");

    for (int i = 0; i < strlen(userPhrase); i++) {
        char currentChar = userPhrase[i];
        int j;

        for (j = 0; j < translationLength; j++) {
            if (alienLanguage[j] == currentChar) {
                printf("%c", englishTranslation[j]);
                break;
            }
        }

        if (j == translationLength) {
            printf("%c", currentChar);
        }
    }

    printf("\nThank you for using the Alien Language Translator. Have a nice day!");

    return 0;
}