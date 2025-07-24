//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LEN 20 // Maximum length of a word
#define ARRAY_SIZE 100000 // Maximum number of words in input file
#define MAX_UNIQUE_WORDS 5000 // Maximum number of unique words to track

// Define a struct to hold word and frequency information
typedef struct {
    char word[WORD_LEN + 1];
    int frequency;
} WordFrequency;

// Function to normalize a string (remove punctuation and convert to lowercase)
char* normalize(char* str) {
    int len = strlen(str);
    char* normalized = malloc(sizeof(char) * (len + 1));
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            normalized[j++] = tolower(str[i]);
        }
    }
    normalized[j] = '\0';
    return normalized;
}

// Function to compare two word frequency structs by frequency (used for sorting)
int compare_word_frequency(const void* a, const void* b) {
    const WordFrequency* wf1 = (const WordFrequency*) a;
    const WordFrequency* wf2 = (const WordFrequency*) b;
    return wf2->frequency - wf1->frequency;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s input_file\n", argv[0]);
        exit(1);
    }

    // Open the input file for reading
    FILE* infile = fopen(argv[1], "r");
    if (!infile) {
        printf("Error: could not open input file\n");
        exit(1);
    }

    // Initialize an array to hold all words in the input file
    char** words = malloc(sizeof(char*) * ARRAY_SIZE);
    int num_words = 0;

    // Read in each line of the input file and tokenize it into words
    char line[1000];
    while (fgets(line, 1000, infile)) {
        char* token = strtok(line, " \t\n");
        while (token) {
            words[num_words++] = normalize(token);
            token = strtok(NULL, " \t\n");
        }
    }

    // Close the input file
    fclose(infile);

    // Count the frequency of each word and store it in a WordFrequency struct
    WordFrequency* word_freqs = malloc(sizeof(WordFrequency) * MAX_UNIQUE_WORDS);
    int num_unique_words = 0;
    for (int i = 0; i < num_words; i++) {
        char* word = words[i];

        // Check if this word is already in the array
        int existing_index = -1;
        for (int j = 0; j < num_unique_words; j++) {
            if (strcmp(word_freqs[j].word, word) == 0) {
                existing_index = j;
                break;
            }
        }

        // If the word is already in the array, increment its frequency; otherwise add it to the array with a frequency of 1
        if (existing_index >= 0) {
            word_freqs[existing_index].frequency++;
        } else {
            if (num_unique_words >= MAX_UNIQUE_WORDS) {
                printf("Error: too many unique words in input file\n");
                exit(1);
            }
            strcpy(word_freqs[num_unique_words].word, word);
            word_freqs[num_unique_words].frequency = 1;
            num_unique_words++;
        }
    }

    // Sort the word frequency array by frequency
    qsort(word_freqs, num_unique_words, sizeof(WordFrequency), compare_word_frequency);

    // Print the top 20 most frequent words and their frequencies
    for (int i = 0; i < 20 && i < num_unique_words; i++) {
        printf("%s: %d\n", word_freqs[i].word, word_freqs[i].frequency);
    }

    // Free memory allocated for input file, words array, and word frequency array
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    free(word_freqs);

    return 0;
}