//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORD_COUNT 1000

/**
 * Represents a word occurrence.
 */
typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordOccurrence;

/**
 * Reads a word from the given input stream.
 * Returns 1 if a word was successfully read, 0 if the end of the stream was reached.
 */
int read_word(FILE* in, char* buffer, int max_length) {
    int c = fgetc(in);
    int i = 0;
    while (c != EOF && !isalpha(c)) {
        c = fgetc(in);
    }
    if (c == EOF) {
        return 0;
    }
    while (c != EOF && isalpha(c) && i < max_length) {
        buffer[i++] = tolower(c);
        c = fgetc(in);
    }
    buffer[i] = '\0';
    return 1;
}

/**
 * Sorts the given array of word occurrences in descending order by count.
 */
void sort_word_occurrences(WordOccurrence* occurrences, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (occurrences[j].count > occurrences[i].count) {
                WordOccurrence temp = occurrences[i];
                occurrences[i] = occurrences[j];
                occurrences[j] = temp;
            }
        }
    }
}

int main() {
    // Initialize array of word occurrences
    WordOccurrence occurrences[MAX_WORD_COUNT];
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        occurrences[i].word[0] = '\0';
        occurrences[i].count = 0;
    }

    // Read words from standard input and count their occurrences
    char buffer[MAX_WORD_LENGTH + 1];
    int word_count = 0;
    while (read_word(stdin, buffer, MAX_WORD_LENGTH)) {
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(buffer, occurrences[i].word) == 0) {
                occurrences[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(occurrences[word_count].word, buffer);
            occurrences[word_count].count = 1;
            word_count++;
        }
        if (word_count == MAX_WORD_COUNT) {
            break;
        }
    }

    // Sort word occurrences by count
    sort_word_occurrences(occurrences, word_count);

    // Print word occurrences and their counts
    for (int i = 0; i < word_count; i++) {
        printf("%s %d\n", occurrences[i].word, occurrences[i].count);
    }

    return 0;
}