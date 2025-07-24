//FormAI DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHAR_PER_LINE 1000
#define WORDS_PER_LINE_MAX 20
#define MAX_WORD_SIZE 50

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} Word;

Word wordList[MAX_LINES][WORDS_PER_LINE_MAX];
int totalWords[MAX_LINES];
int uniqueWords[MAX_LINES];
int maxUniqueWordsIndex = -1;

void analyseLetter(char c) {
    //TODO: implement the logic to analyse each character of input text
}

void countWords(char *inputText, int lineNumber) {
    // Splitting the inputText into words
    char *word = strtok(inputText, " ");
    while (word != NULL) {
        int wordFoundIndex = -1;
        // Checking if the word already exists in the wordList
        for (int i = 0; i < totalWords[lineNumber]; i++) {
            if (strcmp(word, wordList[lineNumber][i].word) == 0) {
                wordFoundIndex = i;
                break;
            }
        }
        if (wordFoundIndex == -1) { // Word not found in wordList
            strncpy(wordList[lineNumber][uniqueWords[lineNumber]].word, word, sizeof(wordList[lineNumber][uniqueWords[lineNumber]].word));
            wordList[lineNumber][uniqueWords[lineNumber]].count = 1;
            uniqueWords[lineNumber]++;
        } else {
            wordList[lineNumber][wordFoundIndex].count++;
        }
        word = strtok(NULL, " ");
    }
    if (uniqueWords[lineNumber] > maxUniqueWordsIndex) {
        maxUniqueWordsIndex = lineNumber;
    }
}

void printOutput() {
    printf("Total unique words: %d\n", uniqueWords[maxUniqueWordsIndex]);
    for (int i = 0; i < uniqueWords[maxUniqueWordsIndex]; i++) {
        printf("%s : %d\n", wordList[maxUniqueWordsIndex][i].word, wordList[maxUniqueWordsIndex][i].count);
    }
}

int main() {
    char inputString[MAX_CHAR_PER_LINE];
    int lineCount = 0;
    while (fgets(inputString, MAX_CHAR_PER_LINE, stdin) != NULL) {
        if (lineCount < MAX_LINES) {
            analyseLetter('\n');
            totalWords[lineCount] = 0;
            uniqueWords[lineCount] = 0;
            countWords(inputString, lineCount);
            lineCount++;
        }
    }
    printOutput();
    return 0;
}