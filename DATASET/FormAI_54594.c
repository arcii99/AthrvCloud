//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: genious
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define WORD_LENGTH 30 // Maximum length of a word
#define MAX_WORDS 1000 // Maximum number of unique words in the input

typedef struct {
    char word[WORD_LENGTH];
    int count;
} WordFrequency;

void printHeader() {
    printf("%-20s%s\n", "Word", "Frequency");
    printf("--------------------------------");
    printf("\n");
}

void printWordFrequencyTable(WordFrequency* words, int numWords) {
    printHeader();

    for (int i = 0; i < numWords; i++) {
        printf("%-20s%d\n", words[i].word, words[i].count);
    }
}

bool isDelimiter(char ch) {
    return !isalnum(ch) && ch != '_';
}

bool isNewWord(char* word, WordFrequency* words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(word, words[i].word) == 0) {
            return false;
        }
    }

    return true;
}

void addWord(char* word, WordFrequency* words, int* numWords) {
    if (*numWords < MAX_WORDS) {
        strcpy(words[*numWords].word, word);
        words[*numWords].count = 1;
        (*numWords)++;
    }
}

void incrementCount(char* word, WordFrequency* words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].count++;
            break;
        }
    }
}

void addWordFrequency(char* word, WordFrequency* words, int* numWords) {
    if (isNewWord(word, words, *numWords)) {
        addWord(word, words, numWords);
    }
    else {
        incrementCount(word, words, *numWords);
    }
}

void parseInput(char* input, WordFrequency* words, int* numWords) {
    char word[WORD_LENGTH];
    int i = 0;

    while (*input != '\0') {
        if (isDelimiter(*input)) {
            word[i] = '\0';
            addWordFrequency(word, words, numWords);
            i = 0;
        }
        else {
            word[i++] = tolower(*input);
        }

        input++;
    }

    word[i] = '\0';
    addWordFrequency(word, words, numWords);
}

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() {
    printf("Enter your input:\n");
    char input[1000];
    fgets(input, 1000, stdin);

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    parseInput(input, words, &numWords);

    printf("\nWord frequency in your input:\n");
    printWordFrequencyTable(words, numWords);

    // wait for user input to close the program
    printf("\nPress ENTER to close...");
    cleanBuffer();
    getchar();

    return 0;
}