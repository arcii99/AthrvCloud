//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <string.h>

// Function to determine sentiment score of a given sentence
int determineSentiment(char* sentence) {
    int sentimentScore = 0;
    char* word;

    // List of positive words
    char positiveWords[][20] = {"happy", "love", "good", "great", "excellent", "nice", "wonderful", "fantastic", "amazing", "best"};

    // List of negative words
    char negativeWords[][20] = {"sad", "hate", "bad", "awful", "terrible", "disgusting", "negative", "ugly", "worst", "horrible"};

    // Tokenize the given sentence into individual words
    word = strtok(sentence, " ");

    while (word != NULL) {
        // Check if current word is in the list of positive words
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, positiveWords[i]) == 0) {
                sentimentScore++;
                break;
            }
        }

        // Check if current word is in the list of negative words
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, negativeWords[i]) == 0) {
                sentimentScore--;
                break;
            }
        }

        // Move to the next word
        word = strtok(NULL, " ");
    }

    return sentimentScore;
}

int main() {
    char sentence[100];

    // Get input sentence from the user
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    // Determine sentiment score of the given sentence
    int sentimentScore = determineSentiment(sentence);

    // Print out the sentiment score
    if (sentimentScore > 0) {
        printf("The sentiment score of the given sentence is positive!\n");
    } else if (sentimentScore < 0) {
        printf("The sentiment score of the given sentence is negative!\n");
    } else {
        printf("The sentiment score of the given sentence is neutral.\n");
    }

    return 0;
}