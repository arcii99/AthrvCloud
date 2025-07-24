//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

void count_word_frequency(char *text, int freq[][2], int *num_words);
void sort_word_frequency(int freq[][2], int num_words);
void print_word_frequency(int freq[][2], int num_words);

int main(void) {
    char text[] = "Count word frequency in this sample text. Counting word frequency is useful for many applications.";
    int freq[MAX_NUM_WORDS][2], num_words = 0;

    count_word_frequency(text, freq, &num_words);
    sort_word_frequency(freq, num_words);
    print_word_frequency(freq, num_words);

    return 0;
}

void count_word_frequency(char *text, int freq[][2], int *num_words) {
    char *word;
    int i, j, k;
    char delims[] = " ,.!?\n\"\':;(){}[]";
    char *token = strtok(text, delims);

    while (token != NULL && *num_words < MAX_NUM_WORDS) {
        i = -1;
        j = *num_words - 1;

        while (i + 1 < j) {
            k = (i + j) / 2;
            if (strcmp(freq[k][0], token) < 0) {
                i = k;
            } else {
                j = k;
            }
        }

        if (j < *num_words && strcmp(freq[j][0], token) == 0) {
            freq[j][1]++;
        } else {
            for (k = *num_words - 1; k >= j; k--) {
                freq[k + 1][0] = freq[k][0];
                freq[k + 1][1] = freq[k][1];
            }
            freq[j][0] = strdup(token);
            freq[j][1] = 1;
            (*num_words)++;
        }

        token = strtok(NULL, delims);
    }
}

void sort_word_frequency(int freq[][2], int num_words) {
    int i, j, tmp_word_freq[2];
    for (i = 1; i < num_words; i++) {
        memcpy(tmp_word_freq, freq[i], sizeof(tmp_word_freq));
        for (j = i; j > 0 && freq[j - 1][1] < tmp_word_freq[1]; j--) {
            memcpy(&freq[j], &freq[j - 1], sizeof(tmp_word_freq));
        }
        memcpy(&freq[j], tmp_word_freq, sizeof(tmp_word_freq));
    }
}

void print_word_frequency(int freq[][2], int num_words) {
    int i;
    printf("Word Frequency Count\n");
    for (i = 0; i < num_words; i++) {
        printf("%-20s %d\n", freq[i][0], freq[i][1]);
        free(freq[i][0]);
    }
}