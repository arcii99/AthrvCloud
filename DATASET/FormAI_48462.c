//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: sophisticated
#include <stdio.h>
#include <string.h>

// Define the dictionary of C Cat Language words and their translations
const char *CAT_WORDS[] = { "meow", "pur", "purr", "hiss", "scratch", "nap", "play", "hungry", "thirsty", "bored", "pet", "eat", "drink" };
const char *ENGLISH_WORDS[] = { "hello", "happy", "happiness", "no", "problem", "sleep", "fun", "food", "water", "entertainment", "love", "consume", "consume" };
const int NUM_WORDS = 13;

// Function to translate a single word from C Cat Language to English
void cat_to_english(char *word) {
    for (int i = 0; i < NUM_WORDS; i++) {
        if (strcmp(word, CAT_WORDS[i]) == 0) {
            printf("%s ", ENGLISH_WORDS[i]);
            return;
        }
    }
    // If word is unrecognized, print untranslated word
    printf("%s ", word);
}

// Function to translate a full sentence from C Cat Language to English
void translate_sentence(char *sentence) {
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        cat_to_english(word);
        word = strtok(NULL, " ");
    }
}

int main(void) {
    // Take input sentence from user
    printf("Enter a sentence in C Cat Language:\n");
    char sentence[100];
    fgets(sentence, 100, stdin);

    // Remove newline character from input
    sentence[strcspn(sentence, "\n")] = 0;

    // Call function to translate sentence and print result
    printf("Translated sentence: ");
    translate_sentence(sentence);
    printf("\n");

    return 0;
}