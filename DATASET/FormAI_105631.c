//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Claude Shannon
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void addWord(char* word, WordCount* wordCounts, int* numWords) {
    int i;
    for (i = 0; i < *numWords; i++) {
        if (strcmp(word, wordCounts[i].word) == 0) {
            wordCounts[i].count++;
            return;
        }
    }
    strcpy(wordCounts[*numWords].word, word);
    wordCounts[*numWords].count = 1;
    (*numWords)++;
}

void printCounts(WordCount* wordCounts, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

void sortCounts(WordCount* wordCounts, int numWords) {
    int i, j;
    WordCount temp;
    for (i = 0; i < numWords - 1; i++) {
        for (j = 0; j < numWords - i - 1; j++) {
            if (wordCounts[j].count < wordCounts[j+1].count) {
                temp = wordCounts[j];
                wordCounts[j] = wordCounts[j+1];
                wordCounts[j+1] = temp;
            }
        }
    }
}

void countWords(FILE* file, WordCount* wordCounts, int* numWords) {
    char word[MAX_WORD_LENGTH];
    char c;
    int i = 0;
    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            word[i++] = tolower(c);
            if (i >= MAX_WORD_LENGTH - 1) {
                i = 0;
            }
        } else {
            word[i] = '\0';
            if (i > 0) {
                addWord(word, wordCounts, numWords);
                i = 0;
            }
        }
    }
    word[i] = '\0';
    if (i > 0) {
        addWord(word, wordCounts, numWords);
    }
}

int main(int argc, char **argv) {
    FILE* file;
    char* fileName;
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fileName = argv[1];

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", fileName);
        exit(1);
    }

    countWords(file, wordCounts, &numWords);
    sortCounts(wordCounts, numWords);
    printCounts(wordCounts, numWords);

    fclose(file);
    return 0;
}