//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 20
#define MAX_CHARS 100

int main() {
    // Initialize variables for sentences and their scores
    char input[MAX_CHARS];
    char sentences[MAX_SENTENCES][MAX_CHARS];
    int scores[MAX_SENTENCES];
    int count = 0;
    
    printf("Welcome to the Sentiment Analysis Tool\n");
    printf("Please enter up to 20 sentences to analyze (type 'done' to finish):\n");
    
    // Collect user input and store in array
    do {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "done\n") == 0) {
            break;
        }
        strcpy(sentences[count], input);
        count++;
    } while (count < MAX_SENTENCES);

    // Analyze sentiment of each sentence and assign score
    for (int i = 0; i < count; i++) {
        char* token = strtok(sentences[i], " ");
        int score = 0;
        while (token != NULL) {
            if (strcmp(token, "peaceful") == 0 || strcmp(token, "calm") == 0) {
                score += 2;
            } else if (strcmp(token, "happy") == 0) {
                score += 1;
            } else if (strcmp(token, "sad") == 0) {
                score -= 1;
            } else if (strcmp(token, "angry") == 0 || strcmp(token, "aggressive") == 0) {
                score -= 2;
            }
            token = strtok(NULL, " ");
        }
        scores[i] = score;
    }

    // Display sentiment analysis results
    printf("\nSentiment Analysis Results:\n");
    for (int i = 0; i < count; i++) {
        printf("\nSentence %d: %s", i+1, sentences[i]);
        printf("Calculated Score: %d\n", scores[i]);
        if (scores[i] > 0) {
            printf("Sentiment: Positive\n");
        } else if (scores[i] < 0) {
            printf("Sentiment: Negative\n");
        } else {
            printf("Sentiment: Neutral\n");
        }
    }

    return 0;
}