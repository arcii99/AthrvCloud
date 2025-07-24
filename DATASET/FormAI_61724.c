//FormAI DATASET v1.0 Category: Text Summarizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LEN 30
#define MAX_SUMMARY_LEN 100

// Function to get the input text
char* get_input_text() {
    char* input_text = (char*)malloc(sizeof(char) * 10000);
    printf("Enter the text to be summarized:\n");
    fgets(input_text, 10000, stdin);
    return input_text;
}

// Function to split the text into words
char** split_into_words(char* input_text, int* num_words) {
    char** words = (char**)malloc(sizeof(char*) * 1000);
    char* word;
    int i = 0;
    word = strtok(input_text, " ");

    while (word != NULL) {
        words[i] = (char*)malloc(sizeof(char) * MAX_WORD_LEN);
        strcpy(words[i], word);
        word = strtok(NULL, " ");
        i++;
    }
    *num_words = i;

    return words;
}

// Function to get the word count in the text
int get_word_count(char* input_text) {
    int word_count = 0;
    for (int i = 0; input_text[i] != '\0'; i++) {
        if (input_text[i] == ' ') {
            word_count++;
        }
    }
    return word_count + 1;
}

// Function to calculate the frequency of each word
void calculate_word_frequency(char** words, int num_words, int* frequency) {
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequency[j] = -1;
            }
        }
        if (frequency[i] != -1) {
            frequency[i] = 1;
            for (int k = i + 1; k < num_words; k++) {
                if (strcmp(words[i], words[k]) == 0) {
                    frequency[i]++;
                }
            }
        }
    }
}

// Function to sort the words in descending order of their frequency
void sort_words_by_frequency(char** words, int num_words, int* frequency) {
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (frequency[i] < frequency[j]) {
                int temp_freq = frequency[i];
                frequency[i] = frequency[j];
                frequency[j] = temp_freq;

                char temp_word[MAX_WORD_LEN];
                strcpy(temp_word, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp_word);
            }
        }
    }
}

// Function to generate the summary
char* generate_summary(char** words, int num_words, int* frequency) {
    char* summary = (char*)malloc(sizeof(char) * MAX_SUMMARY_LEN);
    strcpy(summary, words[0]);
    int summary_word_count = 1;

    for (int i = 1; i < num_words; i++) {
        if (frequency[i] != -1) {
            if (summary_word_count <= 10) { 
                strcat(summary, " ");
                strcat(summary, words[i]);
                summary_word_count++;
            }
            else {
                break;
            }
        }
    }

    return summary;
}

int main() {
    char* input_text = get_input_text();
    int num_words = get_word_count(input_text);
    char** words = split_into_words(input_text, &num_words);
    int frequency[num_words];
    memset(frequency, 0, sizeof(frequency));
    calculate_word_frequency(words, num_words, frequency);
    sort_words_by_frequency(words, num_words, frequency);
    char* summary = generate_summary(words, num_words, frequency);
    printf("Summary:\n%s", summary);
    return 0;
}