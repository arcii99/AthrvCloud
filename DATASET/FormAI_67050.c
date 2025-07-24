//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: invasive
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int positive = 0, negative = 0, neutral = 0;
    char keywords_pos[10][100] = {"good", "great", "excellent", "happy", "love", "amazing", "fantastic", "super", "delightful", "wonderful"};
    char keywords_neg[10][100] = {"bad", "poor", "terrible", "sad", "hate", "disgusting", "awful", "pathetic", "disappointing", "horrible"};
    
    printf("Enter the sentence to perform sentiment analysis: ");
    fgets(sentence, 1000, stdin);
    
    char *word = strtok(sentence, " ");
    
    while (word != NULL) {
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, keywords_pos[i]) == 0) {
                positive++;
            } else if (strcmp(word, keywords_neg[i]) == 0) {
                negative++;
            }
        }
        word = strtok(NULL, " ");
    }
    
    neutral = strlen(sentence) - positive - negative;
    
    printf("\nSentiment Analysis Results:\n");
    printf("Positive words: %d\n", positive);
    printf("Negative words: %d\n", negative);
    printf("Neutral words: %d\n", neutral);
    
    if (positive > negative) {
        printf("\nThe sentence is positive.\n");
    } else if (negative > positive) {
        printf("\nThe sentence is negative.\n");
    } else {
        printf("\nThe sentence is neutral.\n");
    }
    
    return 0;
}