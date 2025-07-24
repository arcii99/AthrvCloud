//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_SENTENCE_LEN 1000
#define MAX_SUMMARY_LEN 500

typedef struct sentence {
    char text[MAX_SENTENCE_LEN];
    double score;
} sentence_t;

double find_max_score(double arr[], int n) {
    double max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int num_sentences = 0;
    char buffer[MAX_SENTENCE_LEN];
    sentence_t sentences[MAX_SENTENCES];
    double sentence_scores[MAX_SENTENCES] = {0};

    printf("Welcome to the Cryptic Text Summarizer!\n");
    printf("Please enter the text to summarize:\n");

    // Read input text
    while(fgets(buffer, MAX_SENTENCE_LEN, stdin)) {
        if(buffer[0] == '\n') {
            break;
        }
        strncpy(sentences[num_sentences].text, buffer, MAX_SENTENCE_LEN);
        num_sentences++;
    }

    printf("Processing summary...\n");

    // Find sentence scores based on occurrence of certain words
    char* keywords[] = {"cryptic", "mystery", "enigma", "puzzle", "esoteric", "obscure", "arcane"};
    for(int i = 0; i < num_sentences; i++) {
        for(int j = 0; j < sizeof(keywords)/sizeof(keywords[0]); j++) {
            if(strstr(sentences[i].text, keywords[j]) != NULL) {
                sentence_scores[i]++;
            }
        }
    }

    // Normalize sentence scores
    double max_score = find_max_score(sentence_scores, num_sentences);
    for(int i = 0; i < num_sentences; i++) {
        sentence_scores[i] = sentence_scores[i]/max_score;
    }

    // Select sentences for summary
    char* summary[MAX_SUMMARY_LEN];
    int summary_len = 0;
    while(summary_len < MAX_SUMMARY_LEN) {
        double max_score = find_max_score(sentence_scores, num_sentences);
        if(max_score == 0) {
            break;
        }
        for(int i = 0; i < num_sentences; i++) {
            if(sentence_scores[i] == max_score) {
                if(summary_len + strlen(sentences[i].text) < MAX_SUMMARY_LEN) {
                    strcat(summary, sentences[i].text);
                    summary_len += strlen(sentences[i].text);
                } else {
                    break;
                }
            }
        }
        for(int i = 0; i < num_sentences; i++) {
            if(sentence_scores[i] == max_score) {
                sentence_scores[i] = 0;
            }
        }
    }

    printf("Summary:\n%s", summary);

    return 0;
}