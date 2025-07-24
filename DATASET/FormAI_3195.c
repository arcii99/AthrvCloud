//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define MAX_NUM_WORDS 10000

char *words[MAX_NUM_WORDS];
int freqs[MAX_NUM_WORDS];
int num_words = 0;

int compare(const void *a, const void *b) {
    return *(const int *)b - *(const int *)a;
}

void init_arrays() {
    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        words[i] = (char *)malloc(MAX_WORD_SIZE * sizeof(char));
        freqs[i] = 0;
    }
}

void read_words(FILE *f) {
    char buf[MAX_WORD_SIZE];
    while (fscanf(f, "%s", buf) != EOF) {
        char *word = words[num_words];
        int i = 0;
        for (; buf[i] != '\0'; i++) {
            if (isalpha(buf[i])) {
                word[i] = tolower(buf[i]);
            } else {
                break;
            }
        }
        word[i] = '\0';
        if (i > 0) {
            freqs[num_words]++;
            num_words++;
        }
    }
}

void sort_words() {
    qsort(freqs, num_words, sizeof(int), compare);
}

void print_words() {
    for (int i = 0; i < num_words; i++) {
        printf("%s %d\n", words[i], freqs[i]);
    }
}

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }

    init_arrays();
    read_words(f);
    sort_words();
    print_words();

    fclose(f);

    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        free(words[i]);
    }

    return 0;
}