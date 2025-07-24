//FormAI DATASET v1.0 Category: Text Summarizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100 // maximum number of sentences to include in summary
#define MAX_INPUT_LENGTH 1000 // maximum length of input text
#define MAX_OUTPUT_LENGTH 500 // maximum length of output summary

// function to tokenize the input text into sentences
void tokenize(char input[], char sentences[][MAX_INPUT_LENGTH]) {
    int i, j, sentence_count = 0, word_count = 0;
    char current_sentence[MAX_INPUT_LENGTH] = "";
    for (i = 0; i <= strlen(input); i++) {
        if (isspace(input[i]) || input[i] == '\0') {
            current_sentence[word_count++] = input[i];
            current_sentence[word_count] = '\0';
            if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
                strcpy(sentences[sentence_count++], current_sentence);
                word_count = 0;
                current_sentence[0] = '\0';
            }
        } else {
            current_sentence[word_count++] = input[i];
            current_sentence[word_count] = '\0';
        }
    }
}

// function to calculate the score of each sentence
void calculate_scores(char sentences[][MAX_INPUT_LENGTH], double scores[], int sentence_count) {
    int i, j, word_count;
    char current_word[MAX_INPUT_LENGTH];
    for (i = 0; i < sentence_count; i++) {
        scores[i] = 0;
        word_count = 0;
        for (j = 0; j <= strlen(sentences[i]); j++) {
            if (isspace(sentences[i][j]) || sentences[i][j] == '\0') {
                current_word[word_count] = '\0';
                if (strlen(current_word) > 3) {
                    scores[i] += 1;
                }
                word_count = 0;
            } else {
                current_word[word_count++] = sentences[i][j];
            }
        }
    }
}

// function to print the summary
void print_summary(char sentences[][MAX_INPUT_LENGTH], double scores[], int sentence_count) {
    int i, j, max_score_index;
    char output[MAX_OUTPUT_LENGTH] = "";
    for (i = 0; i < sentence_count && i < MAX_SENTENCES; i++) {
        max_score_index = 0;
        for (j = 0; j < sentence_count; j++) {
            if (scores[j] > scores[max_score_index]) {
                max_score_index = j;
            }
        }
        strcat(output, sentences[max_score_index]);
        scores[max_score_index] = -1;
    }
    printf("%s", output);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char sentences[MAX_SENTENCES][MAX_INPUT_LENGTH];
    double scores[MAX_SENTENCES];
    int sentence_count = 0;
    
    printf("Enter the text to summarize:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    printf("\n");
    
    tokenize(input, sentences);
    
    sentence_count = sizeof(sentences) / sizeof(sentences[0]);
    
    calculate_scores(sentences, scores, sentence_count);
    
    print_summary(sentences, scores, sentence_count);
    
    return 0;
}