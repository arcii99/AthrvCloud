//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// define the maximum word length and maximum words allowed in text
#define MAX_WORD_LEN 50
#define MAX_WORDS 5000

void countWords(char *text, int wordCount[]);
void printFrequency(int wordCount[]);

int main() {
    char text[MAX_WORDS];
    int wordCount[MAX_WORD_LEN] = {0};

    // read in text from the user
    printf("Enter text (max 5000 words):\n");
    fgets(text, MAX_WORDS, stdin);

    // count the frequency of words
    countWords(text, wordCount);

    // print the word frequency
    printFrequency(wordCount);

    return 0;
}

void countWords(char *text, int wordCount[]) {
    char *word;
    word = strtok(text, " \n");

    while (word != NULL) {
        int len = strlen(word);
        if (len <= MAX_WORD_LEN) {
            // convert word to lowercase
            for (int i = 0; i < len; i++) {
                word[i] = tolower(word[i]);
            }
            // increment frequency count
            wordCount[len - 1] += 1;
        }
        word = strtok(NULL, " \n");
    }
}

void printFrequency(int wordCount[]) {
    printf("Word Frequency Count:\n");

    // print header row
    printf("%-10s%-10s\n", "Word", "Count");

    // print word frequencies
    for (int i = 0; i < MAX_WORD_LEN; i++) {
        if (wordCount[i] > 0) {
            printf("%-10d%-10d\n", i + 1, wordCount[i]);
        }
    }
}