//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: visionary
#include <stdio.h>
#include <string.h>

char *alien_to_english(char *word) {
    char *alien_alphabet = "xzqdbkgsfnotwleyrucmphvia";
    char *english_alphabet = "abcdefghijklmnopqrstuvwxyz";

    // iterate through each character in the alien word
    for (int i = 0; i < strlen(word); i++) {
        // find the index of the alien character in the alien alphabet
        int index = strchr(alien_alphabet, word[i]) - alien_alphabet;

        // use the index to retrieve the corresponding english character from the english alphabet
        if (index >= 0) {
            word[i] = english_alphabet[index];
        }
    }

    return word;
}

int main() {
    char *alien_word = "kxszq";
    char *english_word = alien_to_english(alien_word);

    printf("Alien word: %s\n", alien_word);
    printf("English translation: %s", english_word);

    return 0;
}