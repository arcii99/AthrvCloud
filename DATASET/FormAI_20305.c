//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUMMARY_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_KEYWORD_LENGTH 100

void remove_punctuations(char *text) {
    char *p = text;
    while (*text) {
        if (ispunct((unsigned char)*text)) {
            text++;
            continue;
        }
        *p++ = *text++;
    }
    *p = '\0';
}

int is_keyword(char *word, char keywords[][MAX_KEYWORD_LENGTH], int num_keywords) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char input_text[MAX_SENTENCE_LENGTH];
    char keywords[][MAX_KEYWORD_LENGTH] = {"computer", "programming", "language", "algorithm"};
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    int sentence_count = 0;
    int keyword_count = 0;

    // Get input text from user
    printf("Enter text to summarize:\n");
    fgets(input_text, MAX_SENTENCE_LENGTH, stdin);

    // Remove punctuations from input text
    remove_punctuations(input_text);

    // Tokenize input text into sentences
    char *token = strtok(input_text, ".");
    char sentences[MAX_SUMMARY_LENGTH][MAX_SENTENCE_LENGTH];
    while (token != NULL && sentence_count < MAX_SUMMARY_LENGTH) {
        strcpy(sentences[sentence_count++], token);
        token = strtok(NULL, ".");
    }

    // Count number of keywords in each sentence
    int keyword_counts[MAX_SUMMARY_LENGTH];
    for (int i = 0; i < sentence_count; i++) {
        char sentence_copy[MAX_SENTENCE_LENGTH];
        strcpy(sentence_copy, sentences[i]);
        char *word = strtok(sentence_copy, " ");
        keyword_counts[i] = 0;
        while (word != NULL) {
            if (is_keyword(word, keywords, num_keywords)) {
                keyword_counts[i]++;
            }
            word = strtok(NULL, " ");
        }
    }

    // Select sentences with highest keyword count to be part of summary
    char summary[MAX_SUMMARY_LENGTH][MAX_SENTENCE_LENGTH];
    int summary_count = 0;
    for (int i = 0; i < sentence_count; i++) {
        if (keyword_counts[i] > 0) {
            strcpy(summary[summary_count++], sentences[i]);
            keyword_count += keyword_counts[i];
        }
        if (keyword_count >= num_keywords) {
            break;
        }
    }

    // Print summary
    printf("\nSummary:\n");
    for (int i = 0; i < summary_count; i++) {
        printf("%s.", summary[i]);
    }

    return 0;
}