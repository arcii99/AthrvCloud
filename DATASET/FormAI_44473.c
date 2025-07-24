//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate sentiment score
int calculateSentimentScore(char *sentence) {
    int score = 0;
    char delim[] = " ";
    char *word = strtok(sentence, delim);
    while(word != NULL) {
        if(strncmp(word, "good", 4) == 0) {
            score++;
        } else if(strncmp(word, "bad", 3) == 0){
            score--;
        }
        word = strtok(NULL, delim);
    }
    return score;
}

int main() {
    char sentence[1000];
    printf("Enter a sentence to calculate sentiment score: ");
    fgets(sentence, 1000, stdin);
    // remove trailing newline character
    sentence[strcspn(sentence, "\n")] = 0;
    int score = calculateSentimentScore(sentence);
    
    printf("\nThe sentiment score of \"%s\" is %d\n", sentence, score);
    if(score > 0) {
        printf("Sentiment analysis: Positive");
    } else if(score < 0) {
        printf("Sentiment analysis: Negative");
    } else {
        printf("Sentiment analysis: Neutral");
    }
    return 0;
}