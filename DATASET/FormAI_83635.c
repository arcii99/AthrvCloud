//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORD_LEN 25
#define MAX_WORDS 10000

typedef struct __word_count_t {
    char word[MAX_WORD_LEN];
    int count;
} word_count_t;

word_count_t words[MAX_WORDS];
int n_words = 0;

pthread_mutex_t lock;

void *read_file(void *filename) {
    FILE *fp = fopen((char *) filename, "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", (char *) filename);
        pthread_exit(NULL);
    }

    char word[MAX_WORD_LEN];
    int count;

    while (fscanf(fp, "%s %d", word, &count) == 2) {
        pthread_mutex_lock(&lock);
        strcpy(words[n_words].word, word);
        words[n_words].count = count;
        n_words++;
        pthread_mutex_unlock(&lock);
    }

    fclose(fp);
    pthread_exit(NULL);
}

void *count_words(void *line) {
    char *str = (char *) line;

    char delim[] = " \n\t\r\f!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    char *word = strtok(str, delim);

    while (word != NULL) {
        pthread_mutex_lock(&lock);

        int found = 0;

        for (int i = 0; i < n_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[n_words].word, word);
            words[n_words].count = 1;
            n_words++;
        }

        pthread_mutex_unlock(&lock);

        word = strtok(NULL, delim);
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename> [filename...]\n", argv[0]);
        exit(1);
    }

    pthread_t thread_ids[argc - 1];
    pthread_mutex_init(&lock, NULL);

    // read input files
    for (int i = 1; i < argc; i++) {
        pthread_create(&thread_ids[i - 1], NULL, read_file, (void *) argv[i]);
    }

    for (int i = 0; i < argc - 1; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    // count words in input files
    char line[1024];

    while (fgets(line, 1024, stdin)) {
        pthread_create(&thread_ids[argc - 2], NULL, count_words, (void *) line);
    }

    for (int i = 0; i < argc - 1; i++) {
        pthread_create(&thread_ids[i], NULL, count_words, (void *) argv[i]);
    }

    for (int i = 0; i < argc - 1; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    // print results
    for (int i = 0; i < n_words; i++) {
        printf("%s - %d\n", words[i].word, words[i].count);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}