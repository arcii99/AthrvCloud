//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to perform sentiment analysis
void analyzeSentiment(char sentence[]) {
    int positiveWords = 0, negativeWords = 0;
    char positiveWordList[][20] = {"great", "awesome", "fantastic", "excellent", "amazing", "wonderful", "terrific", "perfect"};
    char negativeWordList[][20] = {"bad", "terrible", "awful", "poor", "disappointing", "frustrating", "horrible", "unpleasant"};
    
    // count positive and negative words in sentence
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            char word[20];
            int j = 0;
            
            // extract word from sentence
            for (int k = i+1; k < strlen(sentence); k++) {
                if (sentence[k] == ' ' || sentence[k] == '\0') {
                    word[j] = '\0';
                    break;
                }
                word[j] = sentence[k];
                j++;
            }
            
            // check if word is positive or negative
            for (int l = 0; l < 8; l++) {
                if (strcmp(word, positiveWordList[l]) == 0) {
                    positiveWords++;
                    break;
                }
            }
            for (int m = 0; m < 8; m++) {
                if (strcmp(word, negativeWordList[m]) == 0) {
                    negativeWords++;
                    break;
                }
            }
        }
    }
    
    // print sentiment analysis result
    if (positiveWords > negativeWords) {
        printf("The sentence is Positive.\n");
    } else if (negativeWords > positiveWords) {
        printf("The sentence is Negative.\n");
    } else {
        printf("The sentence is Neutral.\n");
    }
}

int main() {
    char sentence[200];
    printf("Enter a sentence to analyze its sentiment: ");
    fgets(sentence, 200, stdin);
    analyzeSentiment(sentence);
    return 0;
}