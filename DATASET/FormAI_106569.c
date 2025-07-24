//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_VOCAB_SIZE 100

typedef struct {
    char alien[MAX_WORD_LENGTH+1];
    char english[MAX_WORD_LENGTH+1];
} Translation;

typedef struct {
    Translation words[MAX_VOCAB_SIZE];
    int size;
} Vocabulary;

/**
 * A function to translate an alien word to English using the given vocabulary
 */
void translate(char* alienWord, Vocabulary* vocab) {
    int i;
    for (i = 0; i < vocab->size; i++) {
        if (strcmp(alienWord, vocab->words[i].alien) == 0) {
            printf("%s", vocab->words[i].english);
            return;
        }
    }
    printf("Translation not found!");
}

/** 
 * A function to add a new translation to the vocabulary
 */
void addTranslation(char* alienWord, char* englishWord, Vocabulary* vocab) {
    Translation t;
    strncpy(t.alien, alienWord, MAX_WORD_LENGTH);
    strncpy(t.english, englishWord, MAX_WORD_LENGTH);
    vocab->words[vocab->size++] = t;
}

int main() {
    Vocabulary vocab;
    char input[MAX_WORD_LENGTH+1];
    char option;
    int i;

    // initialize the vocabulary with some sample translations
    addTranslation("blorx", "hello", &vocab);
    addTranslation("xzytz", "goodbye", &vocab);
    addTranslation("glip", "world", &vocab);

    // interactive loop to get user input and handle translation requests
    while (1) {
        printf("\nEnter 't' to translate, 'a' to add a new translation, or 'q' to quit: ");
        scanf(" %c", &option);

        switch (option) {
            case 't':
                printf("Enter the alien word to translate: ");
                scanf("%s", input);

                translate(input, &vocab);
                break;

            case 'a':
                printf("Enter the alien word: ");
                scanf("%s", input);
                printf("Enter the English translation: ");
                scanf("%s", input+MAX_WORD_LENGTH+1);

                addTranslation(input, input+MAX_WORD_LENGTH+1, &vocab);
                break;

            case 'q':
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Try again.\n");
        }
    }
}