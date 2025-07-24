//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct wordCounter {
    char word[MAX_SIZE];
    int freq;
} WordCounter;

int checkIfWordExists(char *word, WordCounter *counter, int totalWords) {
    int i;
    for (i = 0; i < totalWords; i++) {
        if (strcmp(counter[i].word, word) == 0) {
            return i;
        }
    }

    return -1;
}

void incrementWordCounter(char *word, WordCounter *counter, int *totalWords) {
    int wordIndex = checkIfWordExists(word, counter, *totalWords);
    if (wordIndex != -1) {
        counter[wordIndex].freq++;
    } else {
        WordCounter newWord;
        strcpy(newWord.word, word);
        newWord.freq = 1;
        counter[*totalWords] = newWord;
        (*totalWords)++;
    }
}

int main() {

    WordCounter counter[MAX_SIZE];
    int totalWords = 0;

    char inputStr[MAX_SIZE];
    printf("Enter a string: ");
    fgets(inputStr, MAX_SIZE, stdin);

    char *token = strtok(inputStr, " ");
    while (token != NULL) {
        incrementWordCounter(token, counter, &totalWords);
        token = strtok(NULL, " ");
    }

    printf("\nWord Frequency Counter:\n");
    int i;
    for (i = 0; i < totalWords; i++) {
        printf("%s : %d\n", counter[i].word, counter[i].freq);
    }

    return 0;
}