//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to determine sentiment score
int determineSentimentScore(char *text) {
    // List of positive words
    char positiveWords[10][10] = {"good", "great", "happy", "love", "awesome", "excellent", "amazing", "fantastic", "wonderful", "nice"};

    // List of negative words
    char negativeWords[10][10] = {"bad", "awful", "terrible", "hate", "dislike", "poor", "miserable", "pathetic", "sad", "unpleasant"};

    int score = 0;

    // Tokenize text into words
    char *word = strtok(text, " ");

    // Loop through each word and check if it's in the positive or negative word list
    while (word != NULL) {
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, positiveWords[i]) == 0) {
                score++;
            } else if (strcmp(word, negativeWords[i]) == 0) {
                score--;
            }
        }
        word = strtok(NULL, " ");
    }

    return score;
}

int main() {
    // Prompt user for input text
    printf("Enter text: ");
    char text[100];
    fgets(text, sizeof(text), stdin);

    // Determine sentiment score
    int score = determineSentimentScore(text);

    // Determine sentiment based on score
    char *sentiment;
    if (score > 0) {
        sentiment = "Positive";
    } else if (score < 0) {
        sentiment = "Negative";
    } else {
        sentiment = "Neutral";
    }

    // Print sentiment and score
    printf("%s Sentiment\nScore: %d\n", sentiment, score);

    return 0;
}