//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_UNIQUE_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int freq;
} word_freq;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_WORD_LENGTH];
    int num_words = 0;
    word_freq words[MAX_UNIQUE_WORDS];

    while (fgets(line, sizeof(line), input_file)) {
        char *word = strtok(line, " \t\n");
        while (word != NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].freq++;
                    break;
                }
            }

            if (i == num_words) {
                strncpy(words[num_words].word, word, sizeof(words[num_words].word) - 1);
                words[num_words].freq = 1;
                num_words++;

                if (num_words >= MAX_UNIQUE_WORDS) {
                    printf("Too many unique words in input!\n");
                    return 1;
                }
            }

            word = strtok(NULL, " \t\n");
        }
    }

    fclose(input_file);

    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].freq);
    }

    return 0;
}