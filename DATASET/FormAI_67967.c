//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_SIZE 10000
#define MAX_OUTPUT_SIZE 1000
#define MAX_WORD_SIZE 50
#define DAMPING_FACTOR 0.85
#define DELIMITER " "

int main() {
    // Read input text into buffer
    char input[MAX_INPUT_SIZE];
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Tokenize input text into sentences
    char* sentence_tokens[MAX_OUTPUT_SIZE];
    char* sentence_token;
    sentence_token = strtok(input, ".\n");
    int num_sentences = 0;
    while (sentence_token != NULL) {
        sentence_tokens[num_sentences] = sentence_token;
        num_sentences++;
        sentence_token = strtok(NULL, ".\n");
    }

    // Tokenize input text into words
    char* word_tokens[MAX_OUTPUT_SIZE][MAX_OUTPUT_SIZE];
    int num_words[num_sentences];
    char* word_token;
    for (int i = 0; i < num_sentences; i++) {
        char* sentence = sentence_tokens[i];
        int j = 0;
        word_token = strtok(sentence, DELIMITER);
        while (word_token != NULL) {
            word_tokens[i][j] = word_token;
            j++;
            word_token = strtok(NULL, DELIMITER);
        }
        num_words[i] = j;
    }

    // Initialize adjacency matrix and out-degree matrix
    int num_nodes = 0;
    double adjacency_matrix[MAX_OUTPUT_SIZE][MAX_OUTPUT_SIZE];
    double out_degree[MAX_OUTPUT_SIZE];
    for (int i = 0; i < num_sentences; i++) {
        for (int j = 0; j < num_words[i]; j++) {
            for (int k = 0; k < num_sentences; k++) {
                if (k == i) {
                    continue;
                }
                for (int l = 0; l < num_words[k]; l++) {
                    if (strcmp(word_tokens[i][j], word_tokens[k][l]) == 0) {
                        adjacency_matrix[i][k] += 1.0 / num_words[i];
                        num_nodes++;
                        break;
                    }
                }
            }
        }
        out_degree[i] = 0.0;
        for (int j = 0; j < num_sentences; j++) {
            out_degree[i] += adjacency_matrix[i][j];
        }
    }

    // Calculate TextRank score for each node
    double text_rank_scores[MAX_OUTPUT_SIZE];
    double prev_text_rank_scores[MAX_OUTPUT_SIZE];
    for (int i = 0; i < num_sentences; i++) {
        text_rank_scores[i] = 1.0 / num_sentences;
        prev_text_rank_scores[i] = 0.0;
    }
    int num_iterations = 0;
    while (num_iterations == 0 || memcmp(text_rank_scores, prev_text_rank_scores, sizeof(text_rank_scores)) != 0) {
        memcpy(prev_text_rank_scores, text_rank_scores, sizeof(text_rank_scores));
        for (int i = 0; i < num_sentences; i++) {
            double sum = 0.0;
            for (int j = 0; j < num_sentences; j++) {
                if (adjacency_matrix[j][i] != 0.0) {
                    sum += DAMPING_FACTOR * adjacency_matrix[j][i] / out_degree[j] * prev_text_rank_scores[j];
                }
            }
            text_rank_scores[i] = (1 - DAMPING_FACTOR) / num_sentences + sum;
        }
        num_iterations++;
    }

    // Sort nodes by TextRank score and output top N sentences
    int sorted_indices[MAX_OUTPUT_SIZE];
    for (int i = 0; i < num_sentences; i++) {
        sorted_indices[i] = i;
    }
    for (int i = 0; i < num_sentences - 1; i++) {
        for (int j = i + 1; j < num_sentences; j++) {
            if (text_rank_scores[i] < text_rank_scores[j]) {
                double tmp_score = text_rank_scores[i];
                text_rank_scores[i] = text_rank_scores[j];
                text_rank_scores[j] = tmp_score;
                int tmp_index = sorted_indices[i];
                sorted_indices[i] = sorted_indices[j];
                sorted_indices[j] = tmp_index;
            }
        }
    }
    int num_output_sentences = 3;
    char summary[MAX_OUTPUT_SIZE];
    summary[0] = '\0';
    for (int i = 0; i < num_output_sentences; i++) {
        int index = sorted_indices[i];
        strcat(summary, sentence_tokens[index]);
        strcat(summary, ". ");
    }
    printf("%s", summary);

    return 0;
}