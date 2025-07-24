//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define ALIEN_ALPHABET
#define ALIEN_ALPHABET "xyzqwertyuikjhfdsapogmnblcv"

// Define ALIEN_WORDS
#define ALIEN_WORDS_COUNT 5
const char *ALIEN_WORDS[ALIEN_WORDS_COUNT] = {
    "klzlopwe",
    "fdsawepqi",
    "cvhrplat",
    "yqoxstnz",
    "mbgkijuh"
};

// Define translator function
void translate_alien_language(char *alien_word) {
    int alien_alphabet_length = strlen(ALIEN_ALPHABET);

    // Translate each alien character to english
    char english_word[strlen(alien_word) + 1];
    for (int i = 0; i < strlen(alien_word); i++) {
        int index = -1;
        for (int j = 0; j < alien_alphabet_length; j++) {
            if (alien_word[i] == ALIEN_ALPHABET[j]) {
                index = j;
                break;
            }
        }
        if (index < 0) {
            printf("Error: Invalid character in alien word.\n");
            return;
        }
        english_word[i] = (char) (index + 'a');
    }
    english_word[strlen(alien_word)] = '\0';

    // Lookup english word in alien dictionary
    bool found_word = false;
    for (int i = 0; i < ALIEN_WORDS_COUNT; i++) {
        if (strcmp(english_word, ALIEN_WORDS[i]) == 0) {
            printf("Alien word '%s' translates to english word '%s'.\n", alien_word, english_word);
            found_word = true;
            break;
        }
    }
    if (!found_word) {
        printf("Alien word '%s' not found in dictionary.\n", alien_word);
    }
}

// Main function
int main() {
    // Test 1 - valid alien word
    char *alien_word_1 = "yzq";
    printf("Translating alien word '%s'...\n", alien_word_1);
    translate_alien_language(alien_word_1);

    // Test 2 - invalid alien word
    char *alien_word_2 = "123";
    printf("Translating alien word '%s'...\n", alien_word_2);
    translate_alien_language(alien_word_2);

    // Test 3 - alien word not in dictionary
    char *alien_word_3 = "plm";
    printf("Translating alien word '%s'...\n", alien_word_3);
    translate_alien_language(alien_word_3);

    return 0;
}