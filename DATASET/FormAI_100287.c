//FormAI DATASET v1.0 Category: Text Summarizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_LENGTH 1000

// Function to calculate the number of occurrences of a word in a sentence
int countOccurrences(char *sentence, char *word) {
    int count = 0;
    char *temp = sentence;
    while((temp = strstr(temp, word)) != NULL) {
        count++;
        temp += strlen(word);
    }
    return count;
}

int main() {
    char text[MAX_SENTENCES][MAX_LENGTH];
    char *keywords[MAX_SENTENCES];
    int num_sentences = 0;
    int word_count[MAX_SENTENCES];
    int total_words = 0;
    float weights[MAX_SENTENCES];
    float threshold;

    // Read input text
    printf("Enter text (maximum %d sentences):\n", MAX_SENTENCES);
    printf("Press Ctrl+D on a new line when done.\n");
    while(fgets(text[num_sentences], MAX_LENGTH, stdin) != NULL) {
        num_sentences++;
        if(num_sentences == MAX_SENTENCES) {
            break;
        }
    }

    // Read keywords
    printf("Enter keywords separated by spaces:\n");
    char keywords_input[100];
    fgets(keywords_input, 100, stdin);
    int num_keywords = 0;
    char *token = strtok(keywords_input, " ");
    while(token) {
        keywords[num_keywords] = malloc(strlen(token) + 1);
        strcpy(keywords[num_keywords], token);
        num_keywords++;
        token = strtok(NULL, " ");
    }

    // Calculate word counts and total words
    for(int i = 0; i < num_sentences; i++) {
        word_count[i] = 0;
        char *temp = strtok(text[i], " ");
        while(temp != NULL) {
            word_count[i]++;
            total_words++;
            temp = strtok(NULL, " ");
        }
    }

    // Calculate weights
    for(int i = 0; i < num_sentences; i++) {
        weights[i] = 0.0;
        for(int j = 0; j < num_keywords; j++) {
            weights[i] += countOccurrences(text[i], keywords[j]);
        }
        weights[i] /= (float)word_count[i];
    }

    // Determine threshold based on total number of words
    threshold = (float)total_words / (float)num_sentences;

    // Print sentences above threshold
    printf("\nSummary:\n");
    for(int i = 0; i < num_sentences; i++) {
        if(weights[i] > threshold) {
            printf("* %s", text[i]);
        }
    }

    // Free memory for keywords
    for(int i = 0; i < num_keywords; i++) {
        free(keywords[i]);
    }

    return 0;
}