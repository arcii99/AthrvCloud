//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: unmistakable
#include <stdio.h>
#include <string.h>

// Define the maximum word size for the C Alien Language
#define MAX_WORD_SIZE 100

// Array of C Alien Language words and their English translations
char alienWords[][MAX_WORD_SIZE] = {"kzuba", "hello",
                                    "fzudur", "goodbye",
                                    "quzar", "please",
                                    "slyndur", "thank you",
                                    "jyjek", "help",
                                    "wyxou", "yes",
                                    "dymoz", "no",
                                    "vynud", "sorry"};

// Total number of C Alien Language words
const int numAlienWords = sizeof(alienWords) / sizeof(alienWords[0]);

// Translate an input word from C Alien Language to English
void translateAlienWord(char word[]) {
    int i;
    for (i = 0; i < numAlienWords; i++) {
        if (strcmp(word, alienWords[i]) == 0) {
            printf("%s", alienWords[i+1]);
            return;
        }
    }
    printf("Translation not found");
}

int main() {
    char inputWord[MAX_WORD_SIZE];

    // Prompt user for input word in C Alien Language
    printf("Enter a word in C Alien Language: ");
    scanf("%s", inputWord);

    // Translate the input word and print the English translation
    translateAlienWord(inputWord);

    return 0;
}