//FormAI DATASET v1.0 Category: Text Summarizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100000
#define MAX_OUTPUT_SIZE 10000
#define MAX_SUMMARIES 5

char* generate_summary(char* input_text, int summary_length);

int main() {
    char input_text[MAX_INPUT_SIZE];
    printf("Enter input text: ");
    fgets(input_text, MAX_INPUT_SIZE, stdin);

    int summary_length = strlen(input_text) / 5;
    char* summary = generate_summary(input_text, summary_length);
    printf("Summary: %s\n", summary);

    free(summary);

    return 0;
}

char* generate_summary(char* input_text, int summary_length) {
    // Split input_text into sentences
    char** sentences = (char**) malloc(sizeof(char*) * MAX_INPUT_SIZE);
    char* sentence = strtok(input_text, ".!?");
    int num_sentences = 0;
    while (sentence != NULL) {
        sentences[num_sentences++] = sentence;
        sentence = strtok(NULL, ".!?");
    }

    // Score each sentence by keyword frequency
    int* scores = (int*) calloc(num_sentences, sizeof(int));
    char* keyword = strtok(input_text, " ");
    while (keyword != NULL) {
        for (int i = 0; i < num_sentences; i++) {
            if (strstr(sentences[i], keyword) != NULL) {
                scores[i]++;
            }
        }
        keyword = strtok(NULL, " ");
    }

    // Find top scoring sentences and generate summary
    char* summary = (char*) malloc(sizeof(char) * MAX_OUTPUT_SIZE);
    int summary_size = 0;
    for (int i = 0; i < MAX_SUMMARIES; i++) {
        int max_score = 0;
        int max_index = -1;
        for (int j = 0; j < num_sentences; j++) {
            if (scores[j] > max_score) {
                max_score = scores[j];
                max_index = j;
            }
        }
        if (max_index >= 0) {
            strcat(summary, sentences[max_index]);
            strcat(summary, ". ");
            summary_size += strlen(sentences[max_index]);
            scores[max_index] = 0;
        }
        if (summary_size > summary_length) {
            break;
        }
    }

    // Clean up memory and return summary
    free(sentences);
    free(scores);
    return summary;
}