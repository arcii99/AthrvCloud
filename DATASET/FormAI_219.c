//FormAI DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of an input text
#define MAX_TEXT_LENGTH 1000

// Define maximum length of a summary
#define MAX_SUMMARY_LENGTH 100

// Define the frequency table structure
typedef struct {
    char word[MAX_TEXT_LENGTH];
    int frequency;
} frequency_t;

// This function adds a word to the frequency table or increments its frequency
void add_word(frequency_t freq_table[], char *word) {
    // Convert the word to lowercase
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    // Check if the word exists in the frequency table
    for (int i = 0; freq_table[i].frequency != 0; i++) {
        if (strcmp(word, freq_table[i].word) == 0) {
            // If yes, increment its frequency
            freq_table[i].frequency++;
            return;
        }
    }
    // If the word does not exist, add it to the frequency table with frequency 1
    strcpy(freq_table[strlen(word)].word, word);
    freq_table[strlen(word)].frequency = 1;
}

// This function sorts the frequency table in descending order by frequency
void sort_table(frequency_t freq_table[]) {
    int i, j;
    frequency_t temp;
    for (i = 0; freq_table[i + 1].frequency != 0; i++) {
        for (j = i + 1; freq_table[j].frequency != 0; j++) {
            if (freq_table[j].frequency > freq_table[i].frequency) {
                temp = freq_table[i];
                freq_table[i] = freq_table[j];
                freq_table[j] = temp;
            }
        }
    }
}

int main() {
    char input_text[MAX_TEXT_LENGTH];
    frequency_t freq_table[MAX_TEXT_LENGTH] = {0};
    char summary[MAX_SUMMARY_LENGTH] = {0};
    int summary_length = 0;
    int i, j;

    // Get input text from user
    printf("Enter the text you want to summarize:\n");
    fgets(input_text, MAX_TEXT_LENGTH, stdin);

    // Tokenize input text and add words to frequency table
    char *word = strtok(input_text, " ,.\n\t\r");
    while (word != NULL) {
        add_word(freq_table, word);
        word = strtok(NULL, " ,.\n\t\r");
    }

    // Sort frequency table in descending order by frequency
    sort_table(freq_table);

    // Build summary from most frequent words until maximum length is reached
    for (i = 0; i < MAX_TEXT_LENGTH && freq_table[i].frequency != 0 && summary_length < MAX_SUMMARY_LENGTH; i++) {
        // Check if the word is longer than 1 character and is not a stop word
        if (strlen(freq_table[i].word) > 1 && strcmp(freq_table[i].word, "the") != 0 && strcmp(freq_table[i].word, "and") != 0 && strcmp(freq_table[i].word, "to") != 0 && strcmp(freq_table[i].word, "a") != 0) {
            // Add the word to the summary
            for (j = 0; freq_table[i].word[j]; j++) {
                summary[summary_length++] = freq_table[i].word[j];
            }
            summary[summary_length++] = ' ';
        }
    }
    // Print the summary
    printf("Summary:\n%s\n", summary);

    return 0;
}