//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <string.h>

// Function to calculate sentiment score for given sentence
int calculateSentiment(char sentence[]) {
    int sentimentScore = 0; // Initialize sentiment score to 0
    
    // List of positive and negative words
    char positiveWords[10][20] = {"good", "awesome", "great", "excellent", "fantastic", "nice", "Amazing", "Outstanding", "Incredible", "Unbelievable"};
    char negativeWords[10][20] = {"bad", "terrible", "poor", "awful", "horrible", "disappointing", "disaster", "disgusting", "ugly", "unsatisfactory"};
    
    // Tokenize sentence into words
    char *token;
    token = strtok(sentence, " ");
    
    // Loop through each word and check if it is positive or negative
    while(token != NULL) {
        for(int i=0; i<10; i++) {
            if(strcmp(token, positiveWords[i]) == 0) {
                sentimentScore++;
            }
            if(strcmp(token, negativeWords[i]) == 0) {
                sentimentScore--;
            }
        }
        token = strtok(NULL, " ");
    }
    
    return sentimentScore;
}

// Main function
int main() {
    char sentence[1000];
    int sentimentScore;
    
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin); // read sentence from user input
    
    sentimentScore = calculateSentiment(sentence);
    
    // Check sentiment score and print appropriate message
    if(sentimentScore > 0) {
        printf("The sentiment of this sentence is positive.\n");
    }
    else if(sentimentScore < 0) {
        printf("The sentiment of this sentence is negative.\n");
    }
    else {
        printf("The sentiment of this sentence is neutral.\n");
    }
    
    return 0;
}