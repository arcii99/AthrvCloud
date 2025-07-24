//FormAI DATASET v1.0 Category: Text Summarizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_LENGTH 50    // Maximum length of the summary
#define MAX_TEXT_LENGTH 1000    // Maximum length of the original text

// Function to remove punctuations from text
char* remove_punctuations(char* text) {
    int j = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i]) || isspace(text[i])) {
            text[j++] = text[i];
        }
    }
    text[j] = '\0';
    return text;
}

// Function to tokenize the text into words
char** tokenize_text(char* text) {
    char** words = malloc(sizeof(char*) * MAX_TEXT_LENGTH);
    char* word;
    int i = 0;

    word = strtok(text, " ");
    while (word != NULL) {
        words[i++] = word;
        word = strtok(NULL, " ");
    }
    words[i] = NULL;

    return words;
}

// Function to compute the frequency of each word in the text
int* compute_word_frequency(char** words) {
    int* frequency = calloc(MAX_TEXT_LENGTH, sizeof(int));

    for (int i = 0; words[i] != NULL; i++) {
        frequency[i]++;
        for (int j = i + 1; words[j] != NULL; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequency[i]++;
                words[j] = "";
            }
        }
    }
    return frequency;
}

// Function to find the most frequent words in the text
char** find_frequent_words(char** words, int* frequency, int n) {
    char** frequent_words = malloc(sizeof(char*) * n);
    int max_freq = 0;

    // find max frequency
    for (int i = 0; words[i] != NULL; i++) {
        if (frequency[i] > max_freq) {
            max_freq = frequency[i];
        }
    }

    int j = 0;
    for (int i = 0; words[i] != NULL; i++) {
        if (frequency[i] == max_freq) {
            frequent_words[j++] = words[i];
            if (j == n) {
                break;
            }
        }
    }

    // Ensure null termination
    frequent_words[j] = NULL;

    return frequent_words;
}

// Function to generate the summary
char* generate_summary(char** words, char** frequent_words) {
    char* summary = malloc(sizeof(char) * MAX_SUMMARY_LENGTH);
    int i = 0;
    int summary_size = 0;

    while (words[i] != NULL) {
        if (strcmp(words[i], frequent_words[0]) == 0 ||
            strcmp(words[i], frequent_words[1]) == 0 ||
            strcmp(words[i], frequent_words[2]) == 0 ||
            strcmp(words[i], frequent_words[3]) == 0 ||
            strcmp(words[i], frequent_words[4]) == 0) {

            strcat(summary, words[i]);
            strcat(summary, " ");

            summary_size += strlen(words[i]) + 1;

            if (summary_size > MAX_SUMMARY_LENGTH) {
                break;
            }
        }

        i++;
    }

    // Check if summary is too short
    if (summary_size < MAX_SUMMARY_LENGTH) {
        int j = 0;
        while (summary_size < MAX_SUMMARY_LENGTH) {
            strcat(summary, frequent_words[j++]);
            strcat(summary, " ");
            summary_size += strlen(frequent_words[j-1]) + 1;
        }
    }

    return summary;
}

int main() {
    char* original_text = "This is a sample text with some repeated words. It is a test text to check the functionality of the program.";
    char* text = strdup(original_text);

    text = remove_punctuations(text);
    char** words = tokenize_text(text);
    int* frequency = compute_word_frequency(words);
    char** frequent_words = find_frequent_words(words, frequency, 5);
    char* summary = generate_summary(words, frequent_words);

    printf("Original text:\n%s\n", original_text);
    printf("Summary:\n%s\n", summary);

    free(text);
    free(words);
    free(frequency);
    free(frequent_words);
    free(summary);

    return 0;
}