//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of characters in a tweet
#define MAX_TWEET_LENGTH 280 
#define MAX_SENTIMENT_LENGTH 20

// Define structure for sentiment entity
typedef struct sentiment {
    char word[MAX_SENTIMENT_LENGTH];
    int score;
} sentiment;

// Define structure for tweet entity
typedef struct tweet{
    char content[MAX_TWEET_LENGTH];
    int sentiment_score;
} tweet;

// Define global array of sentiment entities for sentiment analysis
sentiment SENTIMENTS[] = {
    {"happy", 5},
    {"joyful", 5},
    {"excited", 4},
    {"angry", -4},
    {"sad", -5},
    {"depressed", -5}
};

// Define function to perform sentiment analysis on a tweet
tweet analyze_tweet(char content[]) {
    tweet t;
    t.sentiment_score = 0;
    char* token = strtok(content, " ");
    while (token != NULL) {
        for (int i = 0; i < sizeof(SENTIMENTS) / sizeof(sentiment); i++) {
            if (strcmp(token, SENTIMENTS[i].word) == 0) {
                t.sentiment_score += SENTIMENTS[i].score;
            }
        }
        token = strtok(NULL, " ");
    }
    strcpy(t.content, content);
    return t;
}

int main() {
    char tweet_content[MAX_TWEET_LENGTH];
    printf("Enter tweet: ");
    fgets(tweet_content, MAX_TWEET_LENGTH, stdin);
    strtok(tweet_content, "\n"); // Strip newline character from input
    tweet t = analyze_tweet(tweet_content);
    printf("Sentiment score: %d\n", t.sentiment_score);
    return 0;
}