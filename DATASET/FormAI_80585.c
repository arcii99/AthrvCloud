//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define sentiment categories
enum Sentiment {
    POSITIVE,
    NEGATIVE,
    NEUTRAL
};

// Define helper function to determine sentiment category based on score
enum Sentiment get_sentiment(int score) {
    if (score > 0) {
        return POSITIVE;
    } else if (score < 0) {
        return NEGATIVE;
    } else {
        return NEUTRAL;
    }
}

int main() {
    // Define sample input
    char input[] = "I really enjoyed that movie. It was so good and made me happy.";
    
    // Define sentiment word lists
    char positive_words[][20] = {
        "good",
        "enjoyed",
        "happy"
    };
    
    char negative_words[][20] = {
        "terrible",
        "hated",
        "bad"
    };
    
    // Define variables to keep track of scores
    int positive_score = 0;
    int negative_score = 0;
    
    // Tokenize input based on whitespace
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Check if token matches a positive word
        for (int i = 0; i < sizeof(positive_words)/sizeof(positive_words[0]); i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                positive_score++;
            }
        }
        
        // Check if token matches a negative word
        for (int i = 0; i < sizeof(negative_words)/sizeof(negative_words[0]); i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                negative_score--;
            }
        }
        
        token = strtok(NULL, " ");
    }
    
    // Calculate total score and determine sentiment category
    int total_score = positive_score + negative_score;
    enum Sentiment sentiment = get_sentiment(total_score);
    
    // Output sentiment analysis result
    switch(sentiment) {
        case POSITIVE:
            printf("Sentiment: Positive\n");
            break;
        case NEGATIVE:
            printf("Sentiment: Negative\n");
            break;
        case NEUTRAL:
            printf("Sentiment: Neutral\n");
            break;
    }
    
    return 0;
}