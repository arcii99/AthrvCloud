//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sentimentAnalysis(char *text) {

    int sentimentScore = 0;
    
    // list of positive words
    char *posWords[] = {"happy", "joyful", "excited", "love", "hopeful", "great", "awesome", "amazing", "fantastic", "excellent"};
    
    // list of negative words
    char *negWords[] = {"sad", "angry", "hate", "disappointed", "miserable", "awful", "terrible", "horrible", "annoying", "disgusting"};
    
    // loop through each word in the input text
    char *word = strtok(text, " ");
    while (word != NULL) {
        
        // check if the word is in the positive words list
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, posWords[i]) == 0) {
                sentimentScore++;
            }
        }
        
        // check if the word is in the negative words list
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, negWords[i]) == 0) {
                sentimentScore--;
            }
        }
        
        word = strtok(NULL, " ");
    }
    
    return sentimentScore;
}

int main() {

    // take user input as text to be analyzed
    char text[1000];
    printf("Enter text to analyze sentiment: ");
    fgets(text, 1000, stdin);
    
    // analyze sentiment and output score
    int score = sentimentAnalysis(text);
    printf("Sentiment Score: %d", score);
    
    return 0;
}