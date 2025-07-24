//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 1000

struct wordcount {
    char* word;
    int count;
};

int getword(char* input, char* output);
struct wordcount* create_wordcount(char* word, int count);
void add_wordcount(struct wordcount* wc, char* word, int count);
void swap_wordcount(struct wordcount* wc1, struct wordcount* wc2);
void sort_wordcount(struct wordcount** wc_arr, int count);
void print_wordcount(struct wordcount** wc_arr, int count);

int main() {
    char input[MAXWORD];
    char output[MAXWORD];

    struct wordcount** wc_arr = NULL;
    int wc_count = 0;

    while (getword(input, output) != EOF) {
        int i;

        for (i = 0; i < wc_count; i++) {
            if (strcmp(wc_arr[i]->word, output) == 0) {
                wc_arr[i]->count++;
                break;
            }
        }

        if (i == wc_count) {
            wc_arr = (struct wordcount**)realloc(wc_arr, sizeof(struct wordcount*) * (wc_count + 1));
            wc_arr[wc_count] = create_wordcount(output, 1);
            wc_count++;
        }
    }

    sort_wordcount(wc_arr, wc_count);
    print_wordcount(wc_arr, wc_count);

    return 0;
}

int getword(char* input, char* output) {
    int c;
    int i = 0;

    while (isalnum(c = getchar())) {
        input[i++] = c;
    }

    input[i] = '\0';

    if (c == EOF) {
        return EOF;
    }

    strcpy(output, input);

    return 0;
}

struct wordcount* create_wordcount(char* word, int count) {
    struct wordcount* wc = (struct wordcount*)malloc(sizeof(struct wordcount));
    wc->word = (char*)malloc(sizeof(char) * (strlen(word) + 1));
    wc->count = count;
    strcpy(wc->word, word);
    return wc;
}

void add_wordcount(struct wordcount* wc, char* word, int count) {
    wc->word = (char*)realloc(wc->word, sizeof(char) * (strlen(word) + 1));
    strcpy(wc->word, word);
    wc->count = count;
}

void swap_wordcount(struct wordcount* wc1, struct wordcount* wc2) {
    char* tmp_word = wc1->word;
    int tmp_count = wc1->count;
    wc1->word = wc2->word;
    wc1->count = wc2->count;
    wc2->word = tmp_word;
    wc2->count = tmp_count;
}

void sort_wordcount(struct wordcount** wc_arr, int count) {
    int i, j;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - 1 - i; j++) {
            if (wc_arr[j]->count < wc_arr[j + 1]->count) {
                swap_wordcount(wc_arr[j], wc_arr[j + 1]);
            }
        }
    }
}

void print_wordcount(struct wordcount** wc_arr, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%s: %d\n", wc_arr[i]->word, wc_arr[i]->count);
    }
}