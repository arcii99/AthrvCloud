//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

struct WordFreq {
    char *word;
    int frequency;
};

typedef struct WordFreq WordFreq;

void parse_file(char *filepath, WordFreq *word_freq);

int compare_freq(const void *a, const void *b) {
    WordFreq *word_freq_a = (WordFreq*) a;
    WordFreq *word_freq_b = (WordFreq*) b;

    return word_freq_b->frequency - word_freq_a->frequency;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filepath>\n", argv[0]);
        return 1;
    }

    WordFreq word_freq[MAX_WORDS];
    parse_file(argv[1], word_freq);

    qsort(word_freq, MAX_WORDS, sizeof(WordFreq), compare_freq);

    for (int i = 0; i < MAX_WORDS && word_freq[i].word != NULL; i++) {
        printf("%-20s %d\n", word_freq[i].word, word_freq[i].frequency);
    }

    return 0;
}

void parse_file(char *filepath, WordFreq *word_freq) {
    FILE *file = fopen(filepath, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[1024];

    while (fgets(line, 1024, file)) {
        int len = strlen(line);

        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }

        char *word = strtok(line, " ");

        while (word != NULL && word_freq[MAX_WORDS-1].word == NULL) {
            char *temp_word = strdup(word);

            for (int i = 0; i < MAX_WORDS; i++) {
                if (word_freq[i].word == NULL) {
                    word_freq[i].word = temp_word;
                    word_freq[i].frequency = 1;
                    break;
                } else if (strcmp(word_freq[i].word, temp_word) == 0) {
                    word_freq[i].frequency++;
                    free(temp_word);
                    break;
                }
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(file);
}