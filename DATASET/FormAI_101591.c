//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_SIZE 50
#define MAX_WORD_COUNT 1000

/* Struct for holding the words and their frequency */
typedef struct {
    char word[MAX_WORD_SIZE];
    int freq;
} WordFrequency;

/* Function prototypes */
void sanitizeWord(char *word);
void addWord(WordFrequency *wf, char *word);
int compare(const void *a, const void *b);
void printWordFrequency(WordFrequency *wf, int len);

int main() {
    char c;
    int i = 0;
    char word[MAX_WORD_SIZE];
    int wordCount = 0;
    WordFrequency wordFrequency[MAX_WORD_COUNT] = {{"", 0}};

    /* Read characters from stdin until EOF */
    while ((c = getchar()) != EOF) {
        /* If character is not a letter or digit, assume word is over */
        if (!isalnum(c)) {
            sanitizeWord(word); // Remove any non alpha-numeric characters
            if (strlen(word) > 0) { // If word is not empty add to frequency counter
                addWord(wordFrequency, word);
                wordCount++;
            }
            /* Reset word for next iteration */
            memset(word, 0, MAX_WORD_SIZE);
            i = 0;
        }
        /* Otherwise add character to word */
        else if (i < MAX_WORD_SIZE - 1) {
            word[i++] = tolower(c); // Convert to lowercase before adding to word
        }
    }

    /* If last word didn't end in non alpha-numeric character, add to frequency counter */
    sanitizeWord(word);
    if (strlen(word) > 0) {
        addWord(wordFrequency, word);
        wordCount++;
    }

    /* Sort the word frequency array */
    qsort(wordFrequency, wordCount, sizeof(WordFrequency), compare);

    /* Print the word frequency */
    printWordFrequency(wordFrequency, wordCount);

    return 0;
}

/**
 * Removes any non alpha-numeric characters from a word.
 **/
void sanitizeWord(char *word) {
    int i = 0, j = 0;
    while (word[i]) {
        if (isalnum(word[i])) {
            word[j++] = word[i];
        }
        i++;
    }
    word[j] = '\0';
}

/**
 * Adds a word to the WordFrequency array. If the word already exists, then increment its frequency count.
 **/
void addWord(WordFrequency *wf, char *word) {
    int i;
    for (i = 0; i < MAX_WORD_COUNT; i++) {
        if (strcmp(wf[i].word, word) == 0) {
            wf[i].freq++;
            return;
        }
        else if (strlen(wf[i].word) == 0) {
            strcpy(wf[i].word, word);
            wf[i].freq = 1;
            return;
        }
    }
}

/**
 * Compares two WordFrequency structs, first by frequency count and then by alphabetical order.
 **/
int compare(const void *a, const void *b) {
    WordFrequency *wf1 = (WordFrequency *) a;
    WordFrequency *wf2 = (WordFrequency *) b;

    if (wf1->freq == wf2->freq) {
        return strcmp(wf1->word, wf2->word);
    }
    else {
        return wf2->freq - wf1->freq;
    }
}

/**
 * Prints the word frequency to stdout, one word and its frequency per line.
 **/
void printWordFrequency(WordFrequency *wf, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%s %d\n", wf[i].word, wf[i].freq);
    }
}