//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 500

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare(const void *a, const void *b) {
    const struct WordFrequency *wf_a = (const struct WordFrequency *) a;
    const struct WordFrequency *wf_b = (const struct WordFrequency *) b;
    return -(wf_a->count - wf_b->count);
}

int main() {
    printf("********** C Word Frequency Counter **********\n\n");

    // Get the input text
    char input_text[MAX_WORDS * MAX_WORD_LENGTH];
    printf("Enter the text: ");
    fgets(input_text, sizeof(input_text), stdin);

    // Convert input text to lowercase
    int i;
    for (i = 0; i < strlen(input_text); i++) {
        input_text[i] = tolower(input_text[i]);
    }

    // Parse input text into words
    char *token;
    char delimiters[] = " ,.\"?!\n";
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;

    token = strtok(input_text, delimiters);
    while (token != NULL && word_count < MAX_WORDS) {
        strcpy(words[word_count++], token);
        token = strtok(NULL, delimiters);
    }

    // Count word frequencies
    struct WordFrequency word_frequencies[MAX_WORDS];
    int num_words = 0;

    for (i = 0; i < word_count; i++) {
        int j, found = 0;

        for (j = 0; j < num_words; j++) {
            if (strcmp(words[i], word_frequencies[j].word) == 0) {
                word_frequencies[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(word_frequencies[num_words].word, words[i]);
            word_frequencies[num_words].count = 1;
            num_words++;
        }
    }

    // Sort words by frequency
    qsort(word_frequencies, num_words, sizeof(struct WordFrequency), compare);

    // Print frequencies
    printf("\nWord Frequencies:\n");
    for (i = 0; i < num_words; i++) {
        printf("%-15s %d\n", word_frequencies[i].word, word_frequencies[i].count);
    }

    return 0;
}