//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: creative
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 1024

//Function to check if a given string is a positive word
int isPositive(char *word) {
    char positiveWords[10][20] = {"happy", "joyful", "great", "fantastic", "excellent", "wonderful", "amazing", "love", "pleasure", "satisfaction"};
    for(int i = 0; i < 10; i++) {
        if(strcmp(word, positiveWords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

//Function to check if a given string is a negative word
int isNegative(char *word) {
    char negativeWords[10][20] = {"sad", "angry", "frustrated", "terrible", "awful", "horrible", "disgusting", "hate", "pain", "displeasure"};
    for(int i = 0; i < 10; i++) {
        if(strcmp(word, negativeWords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

//Function to calculate sentiment score of a given sentence
float calculateSentimentScore(char *sentence) {
    char *token = strtok(sentence, " ");
    int numPositiveWords = 0, numNegativeWords = 0;
    while(token != NULL) {
        if(isPositive(token)) {
            numPositiveWords++;
        }
        else if(isNegative(token)) {
            numNegativeWords++;
        }
        token = strtok(NULL, " ");
    }
    return (float)(numPositiveWords - numNegativeWords)/(numPositiveWords + numNegativeWords);
}

//Main Function
int main() {
    char sentence[MAX_SIZE];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SIZE, stdin);
    printf("Sentiment Score: %f\n", calculateSentimentScore(sentence));
    return 0;
}