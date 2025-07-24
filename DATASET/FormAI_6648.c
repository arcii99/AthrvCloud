//FormAI DATASET v1.0 Category: Text Summarizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000 // Maximum size of input text
#define MAX_SUMMARY_SIZE 100 // Maximum size of summary text
#define MAX_SENTENCE_COUNT 10 // Maximum number of sentences in the summary

// Function to split the input text into an array of sentences
int split_sentences(char input_text[], char sentences[][MAX_INPUT_SIZE]) {
    char *ptr = strtok(input_text, ".");
    int sentence_count = 0;
    while (ptr != NULL) {
        strcpy(sentences[sentence_count], ptr);
        sentence_count++;
        ptr = strtok(NULL, ".");
    }
    return sentence_count;
}

// Function to calculate the score of a sentence based on the frequency of its words in the input text
int calculate_score(char sentence[], char input_text[]) {
    int score = 0;
    char *ptr = strtok(input_text, " ");
    while (ptr != NULL) {
        if (strstr(sentence, ptr) != NULL) {
            score++;
        }
        ptr = strtok(NULL, " ");
    }
    return score;
}

// Function to find the highest scoring sentences and copy them into the summary
void construct_summary(char input_text[], char summary[][MAX_SUMMARY_SIZE], int max_sentences) {
    char sentences[MAX_SENTENCE_COUNT][MAX_INPUT_SIZE];
    int sentence_count = split_sentences(input_text, sentences);
    
    int sentence_scores[sentence_count];
    for (int i = 0; i < sentence_count; i++) {
        sentence_scores[i] = calculate_score(sentences[i], input_text);
    }
    
    for (int i = 0; i < max_sentences; i++) {
        // Find the highest scoring sentence
        int max_score_index = 0;
        for (int j = 0; j < sentence_count; j++) {
            if (sentence_scores[j] > sentence_scores[max_score_index]) {
                max_score_index = j;
            }
        }
        
        // Add the sentence to the summary and remove it from the list of available sentences
        strcpy(summary[i], sentences[max_score_index]);
        sentence_scores[max_score_index] = -1;
    }
}

int main() {
    char input_text[MAX_INPUT_SIZE];
    printf("Enter the text to be summarized:\n");
    fgets(input_text, MAX_INPUT_SIZE, stdin);
    
    char summary[MAX_SENTENCE_COUNT][MAX_SUMMARY_SIZE];
    construct_summary(input_text, summary, MAX_SENTENCE_COUNT);
    
    printf("\nSummary:\n");
    for (int i = 0; i < MAX_SENTENCE_COUNT; i++) {
        printf("%s ", summary[i]);
    }
    
    return 0;
}