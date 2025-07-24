//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: futuristic
#include <stdio.h>
#include <string.h>

// Function to calculate sentiment score
int calculateSentimentScore(char* inputString) {
    int sentimentScore = 0;
    char delimiter[] = " ";
    char* word = strtok(inputString, delimiter);

    while (word != NULL) {
        int wordSentimentScore = 0;
        if (strcmp(word, "happy") == 0 || strcmp(word, "excited") == 0) {
            wordSentimentScore = 2;
        }
        else if (strcmp(word, "sad") == 0 || strcmp(word, "angry") == 0) {
            wordSentimentScore = -2;
        }
        else if (strcmp(word, "love") == 0 || strcmp(word, "like") == 0) {
            wordSentimentScore = 1;
        }
        else if (strcmp(word, "hate") == 0 || strcmp(word, "dislike") == 0) {
            wordSentimentScore = -1;
        }
        sentimentScore += wordSentimentScore;
        word = strtok(NULL, delimiter);
    }
    return sentimentScore;
}

int main() {
    printf("Welcome to the Sentiment Analysis tool!\n");
    printf("Enter a sentence to analyze: ");
    char inputString[100];
    fgets(inputString, sizeof(inputString), stdin);

    int sentimentScore = calculateSentimentScore(inputString);

    printf("Sentiment score: %d\n", sentimentScore);
    if (sentimentScore > 0) {
        printf("The sentence has a positive sentiment.\n");
    }
    else if (sentimentScore < 0) {
        printf("The sentence has a negative sentiment.\n");
    }
    else {
        printf("The sentence has a neutral sentiment.\n");
    }

    return 0;
}