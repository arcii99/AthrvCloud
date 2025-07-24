//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 1000

int main() {
    char input_text[MAX_WORDS];
    char words[MAX_WORDS][MAX_WORD_LENGTH + 1] = {{0}};
    int frequencies[MAX_WORDS] = {0};

    printf("Enter the text to be analyzed (max %d words): ", MAX_WORDS);
    fgets(input_text, sizeof(input_text), stdin);

    // Tokenize the input text into individual words
    char *word_ptr = strtok(input_text, " ,.!?"); // Words are separated by spaces and common punctuation marks
    int word_count = 0;
    while (word_ptr != NULL && word_count < MAX_WORDS) {
        strncpy(words[word_count], word_ptr, MAX_WORD_LENGTH);
        word_count++;
        word_ptr = strtok(NULL, " ,.!?");
    }

    // Calculate the frequencies of each word
    for (int i = 0; i < word_count; i++) {
        char *word = words[i];
        int length = strlen(word);
        int count = 1; // Count of the current word in the input text
        int j;

        // Convert the word to lowercase for case-insensitive comparison
        for (j = 0; j < length; j++) {
            word[j] = tolower(word[j]);
        }

        // Check if the word has already been counted
        for (j = 0; j < i; j++) {
            char *previous_word = words[j];
            if (strcmp(word, previous_word) == 0) {
                count += frequencies[j];
                break;
            }
        }

        // Update the frequency count for the current word
        frequencies[i] = count;
    }

    // Print the frequencies of each word
    printf("Word Frequency\n");
    printf("--------------\n");
    for (int i = 0; i < word_count; i++) {
        printf("%-10s %d\n", words[i], frequencies[i]);
    }

    return 0;
}