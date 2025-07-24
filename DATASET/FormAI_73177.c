//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

int calculateSentimentScore(char sentence[]) {
    int score = 0;
    char delim[] = " .,!?\n";
    char *word = strtok(sentence, delim);
    
    while(word != NULL) {
        if(strcmp(word, "happy") == 0 || strcmp(word, "joyful") == 0) {
            score += 2;
        }
        else if(strcmp(word, "angry") == 0 || strcmp(word, "hate") == 0) {
            score -= 2;
        }
        else if(strcmp(word, "love") == 0 || strcmp(word, "excellent") == 0) {
            score += 3;
        }
        else if(strcmp(word, "sad") == 0 || strcmp(word, "disappointed") == 0) {
            score -= 1;
        }
        else {
            score += 1;
        }
        word = strtok(NULL, delim);
    }
    return score;
}

int main() {
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    int sentimentScore = calculateSentimentScore(input);
    if(sentimentScore > 0) {
        printf("Positive sentiment with a score of %d\n", sentimentScore);
    }
    else if(sentimentScore < 0) {
        printf("Negative sentiment with a score of %d\n", sentimentScore);
    }
    else {
        printf("Neutral sentiment with a score of %d\n", sentimentScore);
    }
    return 0;
}