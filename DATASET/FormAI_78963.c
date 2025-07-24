//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: mind-bending
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum character count for the input string
#define MAX_CHARS 1000000

// Define the maximum number of unique words to track
#define MAX_WORDS 100000

/**
 * A struct representing a word and its frequency count
 */
struct WordInfo {
    char* word;
    int frequency;
};

/**
 * A helper function to allocate memory for a new string
 */
char* allocate_string(int length) {
    char* string = (char*) malloc((length+1) * sizeof(char));
    if (string == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }
    return string;
}

/**
 * A helper function to convert a string to lower case
 */
void to_lower_case(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

/**
 * A helper function to check if a word is already in the word info array
 */
int find_word(char* word, struct WordInfo words[MAX_WORDS], int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * A function to print the top n most frequent words
 */
void print_top_words(struct WordInfo words[MAX_WORDS], int num_words, int n) {
    // Sort the words by frequency
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[i].frequency < words[j].frequency) {
                struct WordInfo temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
    // Print the top n words
    printf("Top %d most frequent words:\n", n);
    for (int i = 0; i < n && i < num_words; i++) {
        printf("%s - %d occurrences\n", words[i].word, words[i].frequency);
    }
}

int main() {
    // Allocate memory for the input string
    char* input = allocate_string(MAX_CHARS);

    // Read input string from standard input
    fgets(input, MAX_CHARS, stdin);

    // Count the frequency of each word
    struct WordInfo words[MAX_WORDS];
    int num_words = 0;
    char* word = strtok(input, " \n\t\r");
    while (word != NULL && num_words < MAX_WORDS) {
        // Convert word to lower case
        to_lower_case(word);
        // Check if word is already in the word info array
        int index = find_word(word, words, num_words);
        // If word is not in word info array, add it
        if (index == -1) {
            words[num_words].word = allocate_string(strlen(word));
            strcpy(words[num_words].word, word);
            words[num_words].frequency = 1;
            num_words++;
        }
        // If word is already in word info array, increment its frequency count
        else {
            words[index].frequency++;
        }
        // Get next word
        word = strtok(NULL, " \n\t\r");
    }

    // Print the total number of words and the number of unique words
    printf("Total words: %d\n", num_words);
    printf("Unique words: %d\n", num_words);

    // Print the top 10 most frequent words
    print_top_words(words, num_words, 10);

    // Free memory
    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }
    free(input);

    return 0;
}