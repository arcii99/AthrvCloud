//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: visionary
#include <stdio.h>
#include <string.h>

char* cat_language_translator(char* sentence) {
    char* translated_sentence = "";

    char* words[50];
    int word_count = 0;

    char* word = strtok(sentence, " ");
    while (word != NULL) {
        words[word_count++] = word;
        word = strtok(NULL, " ");
    }

    for (int i = 0; i < word_count; i++) {
        char* current_word = words[i];

        if (strcmp(current_word, "meow") == 0) {
            strcat(translated_sentence, "Hello ");
        }
        else if (strcmp(current_word, "purr") == 0) {
            strcat(translated_sentence, "I am happy ");
        }
        else if (strcmp(current_word, "hiss") == 0) {
            strcat(translated_sentence, "Go away ");
        }
        else if (strcmp(current_word, "scratch") == 0) {
            strcat(translated_sentence, "I am angry ");
        }
        else {
            strcat(translated_sentence, current_word);
            strcat(translated_sentence, " ");
        }
    }

    return translated_sentence;
}

int main() {
    char sentence[100];
    printf("Enter a sentence in cat language: ");
    fgets(sentence, sizeof(sentence), stdin);

    char* translated_sentence = cat_language_translator(sentence);
    printf("Translated sentence: %s\n", translated_sentence);

    return 0;
}