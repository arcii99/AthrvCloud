//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: introspective
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_TRANLATED_LENGTH 200

// List of cat words and their corresponding translations
char *CAT_WORDS[] = {"meow", "purr", "scratch", "nap", "fish"};

char *ENGLISH_TRANSLATIONS[] = {"hello", "happy", "play", "sleep", "food"};

// Translate function that takes a cat word and returns its English translation
char* translate(char input[MAX_INPUT_LENGTH]) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strcmp(input, CAT_WORDS[i]) == 0) {
            // This is the word we're looking for
            return ENGLISH_TRANSLATIONS[i];
        }
    }
    // Word not found
    return "";
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter a cat word: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove trailing newline character
    input[strlen(input)-1] = '\0';

    char translated[MAX_TRANLATED_LENGTH];
    strcpy(translated, translate(input));

    // Display the translated word
    if (strlen(translated) > 0) {
        printf("Translated word: %s\n", translated);
    } else {
        printf("This word is not in our dictionary.\n");
    }

    return 0;
}