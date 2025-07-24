//FormAI DATASET v1.0 Category: Text Summarizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_CHARS 1000

// Function to calculate the frequency of each word
void calculate_frequency(char *document, int *frequency) {
    char *word = strtok(document, " ,.-\n");
    while(word) {
        frequency[strlen(word) - 1]++;
        word = strtok(NULL, " ,.-\n");
    }
}

// Function to calculate the score of each sentence
void calculate_sentence_score(char *document, int *score, int *frequency) {
    char *sentence = strtok(document, ".\n");
    while(sentence) {
        char *word = strtok(sentence, " ,.-");
        while(word) {
            score[atoi(sentence) - 1] += frequency[strlen(word) - 1];
            word = strtok(NULL, " ,.-");
        }
        sentence = strtok(NULL, ".\n");
    }
}

// Function to print the summary
void print_summary(char *document, int *score, int num_sentences) {
    int i, j;
    char *sentence[MAX_SENTENCES];
    for(i = 0; i < num_sentences; i++)
        sentence[i] = strtok(document, ".\n");
    printf("Summary:\n");
    for(i = 0; i < 5; i++) {
        int max_score = 0, index = 0;
        for(j = 0; j < num_sentences; j++) {
            if(score[j] > max_score) {
                max_score = score[j];
                index = j;
            }
        }
        printf("%d. %s.\n", i+1, sentence[index]);
        score[index] = 0;
    }
}

int main() {
    char document[MAX_CHARS];
    int frequency[20] = {0};
    int score[MAX_SENTENCES] = {0};
    int num_sentences = 0;

    printf("Enter the document:\n");
    fgets(document, MAX_CHARS, stdin);

    // Count the number of sentences
    for(int i = 0; i < strlen(document); i++)
        num_sentences += (document[i] == '.' || document[i] == '\n');

    calculate_frequency(document, frequency);
    calculate_sentence_score(document, score, frequency);
    print_summary(document, score, num_sentences);

    return 0;
}