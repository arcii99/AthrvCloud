//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
const char *ALIEN_DICTIONARY[] = {"zoop", "blorg", "glip", "florp", "twip", "snax", "plarp", "shloop", "zorg", "klak"};

// Define the English language dictionary
const char *ENGLISH_DICTIONARY[] = {"hello", "world", "how", "are", "you", "today", "goodbye", "thanks", "yes", "no"};

// Define the function to translate the alien language
char *alien_to_english(char *alien_word) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(alien_word, ALIEN_DICTIONARY[i]) == 0) {
            return ENGLISH_DICTIONARY[i];
        }
    }
    // Return an error message if the word is not in the dictionary
    return "ERROR: Word not found in dictionary.";
}

// Define the main function
int main() {
    char alien_input[100];
    printf("Enter an alien word: ");
    scanf("%s", alien_input);
    char *english_translation = alien_to_english(alien_input);
    printf("The English translation of '%s' is '%s'.\n", alien_input, english_translation);
    return 0;
}