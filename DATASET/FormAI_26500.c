//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
#include <stdio.h>
#include <string.h>

/* Function to translate a phrase from English to Cat Language */
char* english_to_cat(char* phrase) {
    char* cat_phrase = (char*) malloc(sizeof(char) * strlen(phrase));
    char* word = strtok(phrase, " ");
    while (word != NULL) {
        if (strcmp(word, "I") == 0) {
            strcat(cat_phrase, "Meow ");
        } else if (strcmp(word, "you") == 0) {
            strcat(cat_phrase, "Purr ");
        } else if (strcmp(word, "like") == 0) {
            strcat(cat_phrase, "Chirp ");
        } else if (strcmp(word, "the") == 0) {
            strcat(cat_phrase, "Hiss ");
        } else {
            strcat(cat_phrase, "Meow ");
        }
        word = strtok(NULL, " ");
    }
    return cat_phrase;
}

/* Function to translate a phrase from Cat Language to English */
char* cat_to_english(char* phrase) {
    char* english_phrase = (char*) malloc(sizeof(char) * strlen(phrase));
    char* word = strtok(phrase, " ");
    while (word != NULL) {
        if (strcmp(word, "Meow") == 0) {
            strcat(english_phrase, "I ");
        } else if (strcmp(word, "Purr") == 0) {
            strcat(english_phrase, "you ");
        } else if (strcmp(word, "Chirp") == 0) {
            strcat(english_phrase, "like ");
        } else if (strcmp(word, "Hiss") == 0) {
            strcat(english_phrase, "the ");
        } else {
            strcat(english_phrase, "Meow ");
        }
        word = strtok(NULL, " ");
    }
    return english_phrase;
}

int main() {
    char* cat_phrase = "Meow Purr Chirp Hiss Meow";
    char* english_phrase = cat_to_english(cat_phrase);
    printf("Cat Language: %s\n", cat_phrase);
    printf("English: %s\n", english_phrase);
    free(english_phrase);

    char* english_phrase_two = "I like the cat";
    char* cat_phrase_two = english_to_cat(english_phrase_two);
    printf("English: %s\n", english_phrase_two);
    printf("Cat Language: %s\n", cat_phrase_two);
    free(cat_phrase_two);

    return 0;
}