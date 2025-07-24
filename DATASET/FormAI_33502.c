//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of string input and maximum number of words to output
#define MAX_INPUT 1000
#define MAX_OUTPUT 10

// Define a struct to store words and their frequency count
struct word_freq {
    char word[20];
    int freq;
};

// Function to split a string into words
void split_string(char str[], char words[][20], int *length) {
    char delim[] = " ,.!?:;\n";
    char *token = strtok(str, delim);
    while (token != NULL) {
        strcpy(words[*length], token);
        (*length)++;
        token = strtok(NULL, delim);
    }
}

// Function to find the frequency count of each word
void count_words(char words[][20], int length, struct word_freq freqs[], int *num_freqs) {
    int i, j;
    for (i = 0; i < length; i++) {
        // Check if current word already exists in frequency list
        int found = 0;
        for (j = 0; j < *num_freqs; j++) {
            if (strcmp(words[i], freqs[j].word) == 0) {
                found = 1;
                freqs[j].freq++;
                break;
            }
        }
        // If word not found, add it to frequency list
        if (!found) {
            strcpy(freqs[*num_freqs].word, words[i]);
            freqs[*num_freqs].freq = 1;
            (*num_freqs)++;
        }
    }
}

// Function to compare two frequency count structs for sorting
int compare_freqs(const void *a, const void *b) {
    const struct word_freq *fa = (const struct word_freq *) a;
    const struct word_freq *fb = (const struct word_freq *) b;
    return (fb->freq - fa->freq);
}

int main() {
    // Initialize variables
    char input[MAX_INPUT];
    int length = 0;
    char words[MAX_INPUT][20];
    struct word_freq freqs[100];
    int num_freqs = 0;
    int i;

    // Print instructions and get user input
    printf("Welcome to the C Text Summarizer!\nPlease enter the text you would like to summarize:\n");
    fgets(input, MAX_INPUT, stdin);

    // Split input into individual words
    split_string(input, words, &length);

    // Count frequency of each word
    count_words(words, length, freqs, &num_freqs);

    // Sort frequency list in descending order
    qsort(freqs, num_freqs, sizeof(struct word_freq), compare_freqs);

    // Print top 10 most frequent words
    printf("Top %d most frequent words:\n", MAX_OUTPUT);
    for (i = 0; i < MAX_OUTPUT; i++) {
        printf("%d. %s (%d occurrences)\n", i+1, freqs[i].word, freqs[i].freq);
    }

    return 0;
}