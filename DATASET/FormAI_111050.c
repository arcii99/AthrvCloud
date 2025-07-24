//FormAI DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

int compareWord(const void *w1, const void *w2) {
    const char *word1 = ((const Word *) w1)->word;
    const char *word2 = ((const Word *) w2)->word;
    return strcmp(word1, word2);
}

int compareFrequency(const void *w1, const void *w2) {
    const int freq1 = ((const Word *) w1)->frequency;
    const int freq2 = ((const Word *) w2)->frequency;
    if (freq1 == freq2) return compareWord(w1, w2);
    else return freq2 - freq1;
}

int isWordChar(char c) {
    return isalpha(c) || c == '\'';
}

void processWord(char *word, Word *words, int *wordCount) {
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].frequency++;
            return;
        }
    }
    strcpy(words[*wordCount].word, word);
    words[*wordCount].frequency = 1;
    (*wordCount)++;
}

void parseText(FILE *file, Word *words, int *wordCount) {
    char word[MAX_WORD_LENGTH];
    int c, i = 0;
    while ((c = fgetc(file)) != EOF) {
        if (isWordChar(c)) {
            word[i++] = tolower(c);
        } else if (i > 0) {
            word[i] = '\0';
            processWord(word, words, wordCount);
            i = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }

    Word words[1000];
    int wordCount = 0;
    parseText(file, words, &wordCount);
    fclose(file);

    qsort(words, wordCount, sizeof(Word), compareFrequency);

    printf("Word count: %d\n", wordCount);
    printf("The most common words are:\n");
    for (int i = 0; i < 10 && i < wordCount; i++) {
        printf("%-15s %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}