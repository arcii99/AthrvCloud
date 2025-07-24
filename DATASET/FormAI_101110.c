//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int freq;
} Word;

Word freq_table[MAX_WORDS];
int freq_table_size = 0;

int compare_word(const void *a, const void *b) {
    Word *w1 = (Word *)a;
    Word *w2 = (Word *)b;
    return strcmp(w1->word, w2->word);
}

int find_word(char *word) {
    int i;
    for (i = 0; i < freq_table_size; i++) {
        if (strcmp(word, freq_table[i].word) == 0) {
            return i;
        }
    }
    return -1;
}

void add_word(char *word) {
    int idx = find_word(word);
    if (idx < 0) {
        if (freq_table_size >= MAX_WORDS) {
            fprintf(stderr, "Error: word frequency table is full\n");
            exit(1);
        } else {
            strcpy(freq_table[freq_table_size].word, word);
            freq_table[freq_table_size].freq = 1;
            freq_table_size++;
        }
    } else {
        freq_table[idx].freq++;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    int i, j, c, len;
    i = j = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
            word[i++] = c;
        } else {
            if (i > 0) {
                len = i - j;
                strncpy(word, word + j, len);
                word[len] = '\0';
                add_word(word);
                j = i;
            }
            j++;
            i = j;
        }
    }
    if (i > 0) {
        len = i - j;
        strncpy(word, word + j, len);
        word[len] = '\0';
        add_word(word);
    }

    fclose(fp);

    qsort(freq_table, freq_table_size, sizeof(Word), compare_word);

    printf("Word Frequency Count:\n\n");
    for (i = 0; i < freq_table_size; i++) {
        printf("%-20s %d\n", freq_table[i].word, freq_table[i].freq);
    }

    return 0;
}