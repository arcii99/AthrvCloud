//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} word_count;

// function to compare two word_count structs by count
int count_comparison(const void *a, const void *b) {
    const word_count *word_a = a;
    const word_count *word_b = b;
    return word_b->count - word_a->count;
}

int main() {
    // declare variables
    char input_text[10000];
    int input_len;
    word_count word_count_array[1000];
    int num_words = 0;

    // prompt user for input text
    printf("Welcome to the Happy Word Frequency Counter!\n");
    printf("Please enter some text to count the frequency of words: \n");
    fgets(input_text, sizeof(input_text), stdin);
    input_len = strlen(input_text);

    // loop through input text to identify words and count frequency
    char current_word[MAX_WORD_LEN];
    int current_word_len = 0;
    for (int i = 0; i < input_len; i++) {
        if (isalpha(input_text[i])) {
            current_word[current_word_len] = tolower(input_text[i]);
            current_word_len++;
        } else if (current_word_len > 0) {
            current_word[current_word_len] = '\0';
            // look for word in array and increment count if already present
            int word_found = 0;
            for (int j = 0; j < num_words; j++) {
                if (strcmp(word_count_array[j].word, current_word) == 0) {
                    word_count_array[j].count++;
                    word_found = 1;
                    break;
                }
            }
            // if word not found, add to array with count = 1
            if (!word_found) {
                strcpy(word_count_array[num_words].word, current_word);
                word_count_array[num_words].count = 1;
                num_words++;
            }
            current_word_len = 0;
        }
    }

    // sort word_count_array by count in descending order
    qsort(word_count_array, num_words, sizeof(word_count), count_comparison);

    // print top 10 most frequent words
    printf("Here are the top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < num_words; i++) {
        printf("%s: %d\n", word_count_array[i].word, word_count_array[i].count);
    }

    printf("Thanks for using the Happy Word Frequency Counter! Have a great day :)\n");

    return 0;
}