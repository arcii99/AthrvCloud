//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Sentiment Analyzer!\n");
    printf("Please enter your message:\n");
    
    char message[10000];
    fgets(message, 10000, stdin);
    
    int sentiment_score = 0;
    int num_words = 0;
    char* delimiter = " ,.?!;:\n\t\r\f\v";
    char* token = strtok(message, delimiter);
    
    while (token != NULL) {
        num_words++;
        int word_score = 0;
        for (int i=0; i<strlen(token); i++) {
            word_score += token[i];
        }
        sentiment_score += word_score * num_words;
        token = strtok(NULL, delimiter);
    }
    
    if (sentiment_score > 10000) {
        printf("Wow, your message is incredibly positive!\n");
    } else if (sentiment_score > 0) {
        printf("Your message is positive!\n");
    } else if (sentiment_score == 0) {
        printf("Your message is neutral.\n");
    } else if (sentiment_score < -10000) {
        printf("Oh no, your message is incredibly negative!\n");
    } else {
        printf("Your message is negative.\n");
    }
    
    printf("Thank you for using the Sentiment Analyzer!\n");
    return 0;
}