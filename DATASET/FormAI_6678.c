//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate overall sentiment score
float calculateSentiment(char* string) {
    
    // Convert string to lowercase
    for (int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }

    // List of positive and negative words
    char posWords[5][10] = {"love", "great", "amazing", "excellent", "fantastic"};
    char negWords[5][10] = {"hate", "terrible", "horrible", "awful", "disgusting"};

    // Initial sentiment score
    float sentimentScore = 0;

    // Tokenize the string into words
    char* token = strtok(string, " ");

    while(token != NULL) {
        // Check if the word is in the positive list
        for (int i = 0; i < 5; i++) {
            if (strcmp(token, posWords[i]) == 0) {
                sentimentScore += 0.5;
            }
        }

        // Check if the word is in the negative list
        for (int i = 0; i < 5; i++) {
            if (strcmp(token, negWords[i]) == 0) {
                sentimentScore -= 0.5;
            }
        }

        token = strtok(NULL, " ");
    }

    return sentimentScore;
}

int main() {
    
    char string[100];

    // Get input string from user
    printf("Enter a sentence: ");
    fgets(string, 100, stdin);
    
    // Remove newline character that comes with fgets
    string[strcspn(string, "\n")] = 0;

    // Calculate sentiment score
    float score = calculateSentiment(string);

    if (score > 0) {
        printf("Positive sentiment!\n");
    } else if (score < 0) {
        printf("Negative sentiment!\n");
    } else {
        printf("Neutral sentiment!\n");
    }

    return 0;
}