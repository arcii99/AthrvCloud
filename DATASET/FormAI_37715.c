//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} word_frequency_t;

word_frequency_t word_frequency[MAX_NUM_WORDS];
int num_words = 0;

void *count_words(void *arg) {
    char *filename = (char *)arg;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening %s\n", filename);
        pthread_exit(NULL);
    }

    while (!feof(fp)) {
        char word[MAX_WORD_LENGTH] = {0};
        fscanf(fp, "%s", word);
        if (strlen(word) > 0) {
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            bool word_found = false;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word, word_frequency[i].word) == 0) {
                    word_frequency[i].frequency++;
                    word_found = true;
                    break;
                }
            }

            if (!word_found) {
                strcpy(word_frequency[num_words].word, word);
                word_frequency[num_words].frequency = 1;
                num_words++;
            }
        }
    }

    fclose(fp);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./word_frequency <filename> [<filename> ...]\n");
        return 1;
    }

    pthread_t threads[argc - 1];

    for (int i = 1; i < argc; i++) {
        pthread_create(&threads[i - 1], NULL, count_words, argv[i]);
    }

    for (int i = 0; i < argc - 1; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequency[i].word, word_frequency[i].frequency);
    }

    return 0;
}