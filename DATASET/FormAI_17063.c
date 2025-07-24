//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to check sentiment of the given text
int checkSentiment(char text[]) {
    int sentiment = 0; // 0 indicates neutral, 1 indicates positive, -1 indicates negative
    int positiveWordsCount = 0, negativeWordsCount = 0;
    char* word = strtok(text, " "); // tokenize the text by spaces
    while(word != NULL) {
        if(strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
            positiveWordsCount++;
        }
        else if(strcmp(word, "bad") == 0 || strcmp(word, "poor") == 0 || strcmp(word, "terrible") == 0) {
            negativeWordsCount++;
        }
        word = strtok(NULL, " ");
    }
    if(positiveWordsCount > negativeWordsCount) {
        sentiment = 1;
    }
    else if(positiveWordsCount < negativeWordsCount) {
        sentiment = -1;
    }
    return sentiment;
}

int main() {
    char text[500];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin); // read input text from user
    int sentiment = checkSentiment(text); // check sentiment of input text
    if(sentiment == 1) {
        printf("Positive sentiment detected!\n");
    }
    else if(sentiment == -1) {
        printf("Negative sentiment detected!\n");
    }
    else {
        printf("Neutral sentiment detected!\n");
    }
    return 0;
}