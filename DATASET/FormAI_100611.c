//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define positive and negative keywords
char positiveWords[10][20] = {"amazing", "awesome", "great", "good", "fantastic", "excellent", "love", "like", "super", "happy"};
char negativeWords[10][20] = {"awful", "bad", "terrible", "poor", "sad", "hate", "dislike", "worst", "horrible", "disgusting"};

// Define function to count number of occurrences of a word in a string
int countWord(char *sentence, char *word) {
    int count = 0;
    char *ptr = sentence;
    while (ptr = strstr(ptr, word)) {
        count++;
        ptr++;
    }
    return count;
}

// Define function to calculate sentiment score of a string
int calculateSentimentScore(char *sentence) {
    int positiveScore = 0, negativeScore = 0;
    for (int i = 0; i < 10; i++) {
        positiveScore += countWord(sentence, positiveWords[i]);
        negativeScore += countWord(sentence, negativeWords[i]);
    }
    return positiveScore - negativeScore;
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; // Remove newline character
    int score = calculateSentimentScore(sentence);
    if (score > 0) {
        printf("Sentiment score of \"%s\" is %d, which is positive.\n", sentence, score);
    } else if (score < 0) {
        printf("Sentiment score of \"%s\" is %d, which is negative.\n", sentence, score);
    } else {
        printf("Sentiment score of \"%s\" is %d, which is neutral.\n", sentence, score);
    }
    return 0;
}