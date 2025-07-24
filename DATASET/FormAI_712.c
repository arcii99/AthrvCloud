//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to perform sentiment analysis
void performSentimentAnalysis(char str[]) {
    //Positive words list
    char *posWords[] = {"good", "great", "excellent", "awesome", "fantastic", "wonderful", "amazing", "happy", "satisfied", "love"};
    //Negative words list
    char *negWords[] = {"bad", "horrible", "terrible", "awful", "disappointed", "hate", "angry", "annoyed", "frustrated", "unhappy"};
    //Score variables to keep track of positive and negative count
    int posScore = 0, negScore = 0;
    //Tokenize the string to get individual words
    char *token = strtok(str, " ");
    while (token != NULL) {
        //Compare each word with positive and negative word lists
        for (int i = 0; i < 10; i++) {
            if (strcmp(token, posWords[i]) == 0) {
                posScore++;
            }
            if (strcmp(token, negWords[i]) == 0) {
                negScore++;
            }
        }
        token = strtok(NULL, " ");
    }
    //Determine the sentiment based on score
    if (posScore > negScore) {
        printf("Sentiment: Positive\n");
    } else if (negScore > posScore) {
        printf("Sentiment: Negative\n");
    } else {
        printf("Sentiment: Neutral\n");
    }
}

int main() {
    //Input string to perform sentiment analysis
    char inputStr[100];
    printf("Enter a sentence to analyze sentiment: ");
    fgets(inputStr, 100, stdin);
    //Perform sentiment analysis
    performSentimentAnalysis(inputStr);
    return 0;
}