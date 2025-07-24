//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 1000

void print_frequency(int frequency[], char *words[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%-15s%4d\n", words[i], frequency[i]);
    }
}

int compare_frequency(const void *a, const void *b) {
    int *pa = (int *)a, *pb = (int *)b;
    if (*pb == *pa) return strcmp(*(char **)(pa + 1), *(char **)(pb + 1));
    else return *pb - *pa;
}

void sort_frequency(int frequency[], char *words[], int count) {
    int array[count][2];
    for (int i = 0; i < count; i++) {
        array[i][0] = frequency[i];
        array[i][1] = i;
    }
    qsort(array, count, 2 * sizeof(int), compare_frequency);
    for (int i = 0; i < count; i++) {
        frequency[i] = array[i][0];
        words[i] = words[array[i][1]];
    }
}

void increment_frequency(int frequency[], char *words[], char *word, int *count) {
    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(words[i], word) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) frequency[index]++;
    else {
        frequency[*count] = 1;
        words[*count] = strdup(word);
        (*count)++;
    }
}

void process_file(FILE *fp) {
    char word[MAX_WORD_LEN];
    int frequency[MAX_WORDS];
    char *words[MAX_WORDS];
    int count = 0;
    while (fscanf(fp, "%49s", word) == 1) {
        for (int i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]);
        }
        increment_frequency(frequency, words, word, &count);
    }
    sort_frequency(frequency, words, count);
    print_frequency(frequency, words, count);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s FILENAME\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }
    process_file(fp);
    fclose(fp);
    return 0;
}