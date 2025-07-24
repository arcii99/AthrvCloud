//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_UNIQUE_WORDS 10000

typedef struct WordFreq {
    char word[MAX_WORD_LEN + 1];
    int frequency;
} WordFreq;

void add_word(WordFreq *wf, char *word) {
    if (wf->frequency == 0) {
        strcpy(wf->word, word);
    }
    wf->frequency++;
}

int main() {
    char text[1001];
    printf("Enter text to be analyzed:\n");
    fgets(text, sizeof(text), stdin);

    WordFreq words[MAX_UNIQUE_WORDS];
    int unique_words = 0;

    char *word = strtok(text, " ,.!?;\n");
    while (word != NULL) {
        // convert word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        int word_found = 0;
        for (int i = 0; i < unique_words; i++) {
            if (strcmp(words[i].word, word) == 0) {
                add_word(&words[i], word);
                word_found = 1;
                break;
            }
        }

        if (!word_found) {
            WordFreq wf;
            strcpy(wf.word, word);
            wf.frequency = 1;
            words[unique_words] = wf;
            unique_words++;

            if (unique_words == MAX_UNIQUE_WORDS) {
                printf("Max unique words limit reached.\n");
                break;
            }
        }

        word = strtok(NULL, " ,.!?;\n");
    }

    printf("Word frequency analysis:\n");
    for (int i = 0; i < unique_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}