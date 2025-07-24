//FormAI DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct Word {
    char spelling[MAX_WORD_LENGTH + 1];
    int count;
} Word;

int read_word(FILE *fp, char *word);
int compare_words(const void *a, const void *b);

int main(void) {
    char word[MAX_WORD_LENGTH + 1];
    Word words[MAX_WORDS];
    int num_words = 0;
    FILE *fp;

    fp = fopen("sample_text.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    while (read_word(fp, word) && num_words < MAX_WORDS) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].spelling) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == num_words) {
            strcpy(words[num_words].spelling, word);
            words[num_words++].count = 1;
        }
    }

    qsort(words, num_words, sizeof(Word), compare_words);

    int i;
    for (i = 0; i < num_words; i++) {
        printf("%-20s%2d\n", words[i].spelling, words[i].count);
    }

    fclose(fp);
    return 0;
}

int read_word(FILE *fp, char *word) {
    int ch, i = 0;

    while ((ch = getc(fp)) != EOF && !isalpha(ch))
        ; /* skip non-alphabetic characters */

    if (ch == EOF) {
        return 0;
    }

    word[i++] = tolower(ch);

    while (i < MAX_WORD_LENGTH && (ch = getc(fp)) != EOF && isalpha(ch)) {
        word[i++] = tolower(ch);
    }

    word[i] = '\0';

    return 1;
}

int compare_words(const void *a, const void *b) {
    const Word *w1 = (const Word *)a;
    const Word *w2 = (const Word *)b;
    return w2->count - w1->count;
}