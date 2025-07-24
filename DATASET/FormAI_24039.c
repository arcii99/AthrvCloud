//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of input string
#define THRESHOLD_POS 3 // Threshold value for positive sentiment
#define THRESHOLD_NEG -3 // Threshold value for negative sentiment
#define THRESHOLD_NEU 0 // Threshold value for neutral sentiment

// Function to calculate sentiment score
int calculate_sentiment_score(char *input) {
    int score = 0;
    // Dictionary containing words and their respective sentiment score
    char *dictionary[] = {
        "happy", "joyful", "excited", "pleased", "satisfied", "love", "like", "great", "amazing", "wonderful", "fantastic", "+",
        "sad", "angry", "frustrated", "disappointed", "hate", "dislike", "bad", "terrible", "awful", "horrible", "-"
    };
    int sentiment_scores[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    int num_words = sizeof(dictionary) / sizeof(dictionary[0]);

    char *tok = strtok(input, " ");
    while (tok != NULL) {
        for (int i = 0; i < num_words; i++) {
            if (strcmp(tok, dictionary[i]) == 0) {
                score += sentiment_scores[i];
            }
        }
        tok = strtok(NULL, " ");
    }
    return score;
}

// Function to determine sentiment
char *determine_sentiment(int score) {
    if (score > THRESHOLD_POS) {
        return "Positive";
    } else if (score < THRESHOLD_NEG) {
        return "Negative";
    } else {
        return "Neutral";
    }
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter input: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character from input

    int score = calculate_sentiment_score(input);
    char *sentiment = determine_sentiment(score);

    printf("Input: %s\n", input);
    printf("Sentiment: %s (%d)\n", sentiment, score);

    return 0;
}