//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to represent a word and its sentiment score
struct WordScore {
    char word[20];
    float score;
};

// Global array to store all word-sentiment pairs
// NOTE: This is just an example, in a real-world scenario, these pairs should be
// retrieved from a database or other external source
struct WordScore wordSentiment[] = {
    {"happy", 0.7},
    {"sad", -0.5},
    {"excited", 0.8},
    {"angry", -0.6},
    {"love", 0.9},
    {"hate", -0.8}
};

// Function to calculate the overall sentiment score of a given sentence
float getSentimentScore(char sentence[]) {
    int len = strlen(sentence);
    int countWords = 0;
    float totalScore = 0.0;
    char *word;

    // Split the sentence into words using strtok function
    word = strtok(sentence, " ");
    while (word != NULL) {
        // For each word, check if there is a matching sentiment score
        for (int i = 0; i < sizeof(wordSentiment)/sizeof(struct WordScore); i++) {
            if (strcmp(word, wordSentiment[i].word) == 0) {
                countWords++;
                totalScore += wordSentiment[i].score;
                break;
            }
        }
        word = strtok(NULL, " ");
    }

    // Calculate the overall sentiment score of the sentence
    if (countWords > 0) {
        return totalScore/countWords;
    } else {
        return 0.0;
    }
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    strtok(sentence, "\n"); // Remove the newline character at the end of the sentence
    
    float sentimentScore = getSentimentScore(sentence);
    printf("Sentiment score of the sentence is: %.2f\n", sentimentScore);

    return 0;
}