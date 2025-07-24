//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of positive words in the sentence
int countPositiveWords(char *sentence) {
    char *word;
    int count = 0;
    word = strtok(sentence, " ");
    while (word != NULL) {
        if (strcmp(word, "good") == 0 || strcmp(word, "happy") == 0 || strcmp(word, "excellent") == 0) {
            count++;
        }
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to count the number of negative words in the sentence
int countNegativeWords(char *sentence) {
    char *word;
    int count = 0;
    word = strtok(sentence, " ");
    while (word != NULL) {
        if (strcmp(word, "bad") == 0 || strcmp(word, "sad") == 0 || strcmp(word, "terrible") == 0) {
            count++;
        }
        word = strtok(NULL, " ");
    }
    return count;
}

int main() {
    char sentence[100];
    int positiveCount, negativeCount, sentimentScore;
    
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    
    positiveCount = countPositiveWords(sentence);
    negativeCount = countNegativeWords(sentence);
    
    sentimentScore = positiveCount - negativeCount;
    
    if (sentimentScore > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if (sentimentScore < 0) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }
    
    return 0;
}