//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWordCount(const void* a, const void* b) {
    WordCount* wordCountA = (WordCount*) a;
    WordCount* wordCountB = (WordCount*) b;
    return wordCountB->count - wordCountA->count;
}

void countWords(char* text, WordCount* wordCounts, int* numWords) {
    char word[MAX_WORD_LENGTH] = "";
    int index = 0;
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (isalnum(c) || c == '-') {
            word[index++] = tolower(c);
        } else {
            if (index > 0) {
                word[index] = '\0';
                index = 0;
                int found = 0;
                for (int j = 0; j < *numWords; j++) {
                    if (strcmp(word, wordCounts[j].word) == 0) {
                        wordCounts[j].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcpy(wordCounts[*numWords].word, word);
                    wordCounts[*numWords].count = 1;
                    (*numWords)++;
                }
            } 
        }
    }
}

void printWordCounts(WordCount* wordCounts, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    char text[MAX_WORDS * MAX_WORD_LENGTH] = "";
    printf("Enter text: ");
    fgets(text, MAX_WORDS * MAX_WORD_LENGTH, stdin);
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    countWords(text, wordCounts, &numWords);
    qsort(wordCounts, numWords, sizeof(WordCount), compareWordCount);
    printWordCounts(wordCounts, numWords);
    return 0;
}