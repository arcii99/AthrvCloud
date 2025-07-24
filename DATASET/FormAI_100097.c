//FormAI DATASET v1.0 Category: Text Summarizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSUMMARY 100

void text_summarizer(char *text) {
    // Declarations
    int i, j, k, count;
    int len = strlen(text);
    int sentence_count = 0;
    int sentence_start[MAXSUMMARY], sentence_end[MAXSUMMARY];
    int score[MAXSUMMARY];
    char sentence[MAXSUMMARY][MAXSUMMARY];
    char summary[MAXSUMMARY];
    
    // Initialize
    memset(sentence_start, 0, sizeof(sentence_start));
    memset(sentence_end, 0, sizeof(sentence_end));
    memset(score, 0, sizeof(score));
    memset(sentence, 0, sizeof(sentence));
    memset(summary, 0, sizeof(summary));
    
    // Find sentence boundaries
    for (i = 0; i < len; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentence_end[sentence_count] = i;
            sentence_count++;
        }
    }
    
    // Extract sentences
    for (i = 0; i < sentence_count; i++) {
        int start = sentence_start[i];
        int end = sentence_end[i];
        int sentence_len = end - start + 1;
        strncpy(sentence[i], &text[start], sentence_len);
        sentence[i][sentence_len] = '\0';
    }
    
    // Compute sentence scores
    for (i = 0; i < sentence_count; i++) {
        for (j = 0; j < sentence[i][j]; j++) {
            if (sentence[i][j] == ' ') {
                score[i]++;
            }
        }
    }
    
    // Find top-scoring sentences
    for (i = 0; i < MAXSUMMARY; i++) {
        int max_score = 0;
        int max_index = 0;
        for (j = 0; j < sentence_count; j++) {
            if (score[j] > max_score) {
                max_score = score[j];
                max_index = j;
            }
        }
        if (max_score == 0) {
            break;
        }
        score[max_index] = 0;
        strcat(summary, sentence[max_index]);
        strcat(summary, " ");
    }
    
    // Output summary
    printf("Text Summary:\n%s", summary);
}

int main() {
    // Input text
    char text[] = "In the year 2021, computer programming continues to be an essential skill in the workforce. However, with the vast amount of information and resources available online, it can be overwhelming for beginners to know where to start. This C Text Summarizer program is designed to help simplify the process of extracting the most important information from a lengthy text. Users can simply input their desired text and the program will output a summarized version of the text, providing the essential information without the excess fluff. Give it a try and see how it can help enhance your productivity!";
    
    // Call text_summarizer function
    text_summarizer(text);
    
    return 0;
}