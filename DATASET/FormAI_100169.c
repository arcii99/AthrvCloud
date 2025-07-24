//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

//function to calculate sentiment score of a sentence
int calculateSentiment(char sentence[]) {
    int sentimentScore = 0;
    int length = strlen(sentence);
    for(int i=0; i<length; i++) {
        if(sentence[i] == ' ') {
            continue;
        }
        if(sentence[i] == 'g') {
            sentimentScore += 2;
        }
        else if(sentence[i] == 'b') {
            sentimentScore -= 2;
        }
    }
    return sentimentScore;
}

int main() {
    char sentence[100];
    printf("Enter a sentence to determine sentiment score: ");
    fgets(sentence, 100, stdin);
    int sentimentScore = calculateSentiment(sentence);
    printf("Sentiment score of the sentence is: %d", sentimentScore);
    return 0;
}