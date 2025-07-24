//FormAI DATASET v1.0 Category: Word Count Tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

void print_word_count(char *text, int *word_count, int num_words);
int compare(const void *p, const void *q);

int main(void) {
    char text[500];
    char word_list[MAX_WORDS][MAX_WORD_LEN];
    int word_count[MAX_WORDS] = {0};
    int num_words = 0;

    printf("Enter text (max 500 characters): ");
    fgets(text, 500, stdin);

    char *token = strtok(text, " \n");
    while (token != NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, word_list[i]) == 0) {
                word_count[i]++;
                break;
            }
        }
        if (i == num_words) {
            if (num_words == MAX_WORDS) {
                printf("Max words exceeded. Truncating at %d words.\n", num_words);
                break;
            }
            strcpy(word_list[num_words], token);
            word_count[num_words] = 1;
            num_words++;
        }
        token = strtok(NULL, " \n");
    }

    qsort(word_list, num_words, sizeof(word_list[0]), compare);

    print_word_count(text, word_count, num_words);

    return 0;
}

void print_word_count(char *text, int *word_count, int num_words) {
    printf("Word count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", text, word_count[i]);
    }
}

int compare(const void *p, const void *q) {
    return strcmp(p, q);
}