//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sentimentAnalyzer(char *inputString) {
    int negativeCount = 0, positiveCount = 0;
    char *negativeWords[] = {"bad", "terrible", "horrible", "awful", "disgusting"};
    char *positiveWords[] = {"good", "excellent", "fantastic", "amazing", "awesome"};

    char *word = strtok(inputString, " "); // Splitting inputString into individual words
    while( word != NULL ) {
        for(int i=0;i<5;i++) {
            if(strcmp(word, negativeWords[i]) == 0) { // If match found with negative words
                negativeCount++;
            }
            else if(strcmp(word, positiveWords[i]) == 0) { // If match found with positive words
                positiveCount++;
            }
        }
        word = strtok(NULL, " ");
    }

    if(negativeCount > positiveCount) {
        printf("Negative Sentiment.\n");
    }
    else if(negativeCount < positiveCount) {
        printf("Positive Sentiment.\n");
    }
    else {
        printf("Neutral Sentiment.\n");
    }
}

int main() {
    char inputString[100];
    printf("Enter the text to be analyzed: ");
    fgets(inputString, 100, stdin); // Take user Input
    sentimentAnalyzer(inputString);
    return 0;
}