//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to analyze sentiment of a sentence
void analyzeSentiment(char sentence[]) {
    int posWords = 0; // Number of positive words in a sentence
    int negWords = 0; // Number of negative words in a sentence
    
    // Array of positive words
    char *posList[] = {"good", "great", "excellent", "amazing", "awesome", "fantastic", "joy", "happy", "love", "like", "impressive", "better", "best"};
    
    // Array of negative words
    char *negList[] = {"bad", "terrible", "poor", "awful", "disappointing", "dissatisfied", "hate", "dislike", "problem", "difficult", "worst", "worse"};
    
    // Tokenizing the sentence
    char *word = strtok(sentence, " ");
    
    while (word != NULL) {
        // Comparing the word with positive words array
        for (int i = 0; i < 13; i++) {
            if (strcmp(word, posList[i]) == 0) {
                posWords++;
            }
        }
        
        // Comparing the word with negative words array
        for (int i = 0; i < 12; i++) {
            if (strcmp(word, negList[i]) == 0) {
                negWords++;
            }
        }
        
        // Fetching the next token
        word = strtok(NULL, " ");
    }
    
    // Decision based on the analysis of the sentence
    if (posWords > negWords) {
        printf("The sentence has a positive sentiment!\n");
    } else if (posWords < negWords) {
        printf("The sentence has a negative sentiment!\n");
    } else {
        printf("The sentence has a neutral sentiment!\n");
    }
}

// Test program
int main() {
    char testSentence[100];
    
    printf("Enter a sentence to analyze: ");
    fgets(testSentence, 100, stdin);
    
    analyzeSentiment(testSentence);
    
    return 0;
}