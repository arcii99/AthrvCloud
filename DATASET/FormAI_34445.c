//FormAI DATASET v1.0 Category: Spell checking ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_WORD_LEN 50
#define NUM_THREADS 5

typedef struct {
    char word[MAX_WORD_LEN];
    int line_number;
} WordNode;

WordNode *words = NULL;
int num_words = 0;
int capacity = 0;

int check_word(char *word) {
    // Pretend this is the spell checking logic
    sleep(1);
    return rand() % 2;
}

void check_words(int line_number, char *text) {
    char *word;
    for (word = strtok(text, " \t\n"); word; word = strtok(NULL, " \t\n")) {
        if (!check_word(word)) {
            WordNode new_word = {0};
            strncpy(new_word.word, word, MAX_WORD_LEN-1);
            new_word.line_number = line_number;
            if (num_words >= capacity) {
                capacity += 10;
                words = realloc(words, capacity * sizeof(WordNode));
            }
            words[num_words++] = new_word;
        }
    }
}

void *check_lines_async(void *arg) {
    int line_number = (long)arg;
    char text[100];
    sprintf(text, "This is line number %d of the text file.", line_number);
    check_words(line_number, text);
    return NULL;
}

int main(void) {
    srand(time(NULL));

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, check_lines_async, (void *)(long)(i+1));
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    if (num_words == 0) {
        printf("No misspelled words found.\n");
    } else {
        printf("Misspelled words found:\n");
        for (int i = 0; i < num_words; i++) {
            printf("%s at line %d\n", words[i].word, words[i].line_number);
        }
    }

    free(words);
    return 0;
}