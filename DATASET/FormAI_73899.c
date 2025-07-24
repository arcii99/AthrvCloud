//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 100 // Maximum length of a line in the input file
#define MAX_WORD_SIZE 20 // Maximum length of a word

typedef struct WordFreq {
    char word[MAX_WORD_SIZE + 1];
    int frequency;
} WordFreq;

int compareWord(const void *a, const void *b) {
    return ((WordFreq*)b)->frequency - ((WordFreq*)a)->frequency;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s input_file\n", argv[0]);
        return 1;
    }

    char* input_file = argv[1];
    FILE* file = fopen(input_file, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", input_file);
        return 1;
    }

    WordFreq* words = malloc(sizeof(WordFreq));
    int capacity = 1;
    int size = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        char* word = strtok(line, " \r\n");

        while (word != NULL) {
            // Convert to lowercase
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            // Check if word is already in the array
            int found = 0;
            for (int i = 0; i < size; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].frequency++;
                    found = 1;
                    break;
                }
            }

            // Add new word to array
            if (!found) {
                if (size == capacity) {
                    capacity *= 2;
                    words = realloc(words, capacity * sizeof(WordFreq));
                }
                strcpy(words[size].word, word);
                words[size].frequency = 1;
                size++;
            }

            word = strtok(NULL, " \r\n");
        }
    }

    fclose(file);

    // Sort words by frequency
    qsort(words, size, sizeof(WordFreq), compareWord);

    // Print word frequency
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    free(words);

    return 0;
}