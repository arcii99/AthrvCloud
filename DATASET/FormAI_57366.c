//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <string.h>

// Define constants
#define MAX_ALIEN_WORDS 10
#define MAX_ALIEN_WORD_LENGTH 20
#define MAX_TRANSLATION_LENGTH 200

// Define global variables
char alien_words[MAX_ALIEN_WORDS][MAX_ALIEN_WORD_LENGTH] = {"rozo", "spora", "lonto"};
char alien_translation[MAX_ALIEN_WORDS][MAX_TRANSLATION_LENGTH] = {"greetings", "farewell", "thanks"};

// Define functions
int get_alien_word_index(char *word);
char *translate_alien_word(char *word);

int main() {
    char input[MAX_ALIEN_WORD_LENGTH];
    printf("Enter an alien word: ");
    scanf("%s", input);
    char *translation = translate_alien_word(input);
    if (translation != NULL) {
        printf("Translation: %s\n", translation);
    } else {
        printf("Unknown word.\n");
    }
    return 0;
}

// Returns the index of the alien word in the array, or -1 if it is not found
int get_alien_word_index(char *word) {
    for (int i = 0; i < MAX_ALIEN_WORDS; i++) {
        if (strcmp(word, alien_words[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Returns the translation of the alien word, or NULL if it is unknown
char *translate_alien_word(char *word) {
    int index = get_alien_word_index(word);
    if (index != -1) {
        return alien_translation[index];
    } else {
        return NULL;
    }
}