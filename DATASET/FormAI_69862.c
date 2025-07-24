//FormAI DATASET v1.0 Category: Word Count Tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000   // Maximum number of words to be processed.
#define MAX_WORD_LENGTH 50   // Maximum length of a word to be processed.

// Structure for holding each unique word and its count.
struct WordCount {
    char *word;
    int count;
};

// Function to compare two words for sorting purposes.
// Sort alphabetically and by count in case of tie.
int compareWords(const void *w1, const void *w2) {
    struct WordCount *wc1 = (struct WordCount *)w1;
    struct WordCount *wc2 = (struct WordCount *)w2;

    int countDiff = wc2->count - wc1->count;
    if (countDiff == 0) {
        return strcmp(wc1->word, wc2->word);
    }
    return countDiff;
}

// Function to convert the entire string to lower case.
void convertToLower(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int main() {
    char inputStr[MAX_WORDS * MAX_WORD_LENGTH];
    char *words[MAX_WORDS];

    // Read the input string from the user.
    printf("Enter a string: ");
    fgets(inputStr, sizeof(inputStr), stdin);

    // Convert each character to lower case to make the word count case-insensitive.
    convertToLower(inputStr);

    // Count the words in the input string and store them in the words array.
    int wordCount = 0;
    char *token = strtok(inputStr, " .,!?");
    while (token != NULL && wordCount < MAX_WORDS) {
        words[wordCount] = token;
        wordCount++;
        token = strtok(NULL, " .,!?");
    }

    // Create an array of WordCount structures for each unique word and its count.
    struct WordCount wordCounts[MAX_WORDS];
    int uniqueWordCount = 0;

    for (int i = 0; i < wordCount; i++) {
        // Check if the current word already exists in the wordCounts array.
        int matchIndex = -1;
        for (int j = 0; j < uniqueWordCount; j++) {
            if (strcmp(words[i], wordCounts[j].word) == 0) {
                matchIndex = j;
                break;
            }
        }

        // If the word is not found, add it to the wordCounts array.
        if (matchIndex == -1) {
            struct WordCount newWordCount;
            newWordCount.word = words[i];
            newWordCount.count = 1;
            wordCounts[uniqueWordCount] = newWordCount;
            uniqueWordCount++;
        }
        // If the word is found, increment its count in the wordCounts array.
        else {
            wordCounts[matchIndex].count++;
        }
    }

    // Sort the wordCounts array alphabetically and by count in case of tie.
    qsort(wordCounts, uniqueWordCount, sizeof(struct WordCount), compareWords);

    // Print the word count results.
    printf("Word Count Results:\n");
    for (int i = 0; i < uniqueWordCount; i++) {
        printf("%d - %s\n", wordCounts[i].count, wordCounts[i].word);
    }
    return 0;
}