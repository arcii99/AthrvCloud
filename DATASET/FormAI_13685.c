//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUM_WORDS 1000

char *read_word(FILE *fp);
void count_words(FILE *fp, int *word_count, char words[MAX_NUM_WORDS][MAX_WORD_LENGTH]);

int main(int argc, char *argv[]) {
    FILE *fp;
    int word_count[MAX_NUM_WORDS] = {0};
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];

    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: could not open file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    count_words(fp, word_count, words);

    // Print out word frequency table
    printf("%-20s %s\n", "WORD", "COUNT");
    printf("--------------------\n");
    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        if (word_count[i] > 0) {
            printf("%-20s %d\n", words[i], word_count[i]);
        }
    }

    fclose(fp);
    return 0;
}

// Reads a single word from a file stream and returns a pointer to the word
char *read_word(FILE *fp) {
    static char word[MAX_WORD_LENGTH + 1];
    char c;
    int i = 0;

    while ((c = fgetc(fp)) != EOF && !isalnum(c));
    if (c == EOF) {
        return NULL;
    }

    do {
        word[i++] = c;
    } while ((c = fgetc(fp)) != EOF && isalnum(c) && i < MAX_WORD_LENGTH - 1);

    word[i] = '\0';

    // Discard the rest of the word if it exceeds MAX_WORD_LENGTH
    while (c != EOF && isalnum(c)) {
        c = fgetc(fp);
    }

    return word;
}

// Counts the frequency of each word in a file and stores the results in word_count array
void count_words(FILE *fp, int *word_count, char words[MAX_NUM_WORDS][MAX_WORD_LENGTH]) {
    char *word;

    while ((word = read_word(fp))) {
        // Convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // Search for word in words array
        int i;
        for (i = 0; i < MAX_NUM_WORDS; i++) {
            if (strcmp(words[i], word) == 0) {
                word_count[i]++;
                break;
            } else if (word_count[i] == 0) {
                strcpy(words[i], word);
                word_count[i]++;
                break;
            }
        }
    }
}