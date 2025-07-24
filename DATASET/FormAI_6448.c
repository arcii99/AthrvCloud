//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char positive_words[MAX_WORDS][MAX_WORD_LENGTH] = {"happy", "excited", "love", "success", "good"};
char negative_words[MAX_WORDS][MAX_WORD_LENGTH] = {"sad", "angry", "hate", "failure", "bad"};

int positive_score = 0;
int negative_score = 0;

void calculate_sentiment_score(char *input_text) {
    char *token = strtok(input_text, " ");
    while(token != NULL) {
        for(int i=0; i<MAX_WORDS; i++) {
            if(strcmp(token, positive_words[i])==0) {
                positive_score++;
            }
            if(strcmp(token, negative_words[i])==0) {
                negative_score++;
            }
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char input_text[1000];
    printf("Enter your text: ");
    gets(input_text);

    calculate_sentiment_score(input_text);
    
    // Checking if the text is positive, negative or neutral
    if(positive_score > negative_score) {
        printf("The text is positive.\n");
    } else if(positive_score < negative_score) {
        printf("The text is negative.\n");
    } else {
        printf("The text is neutral.\n");
    }

    printf("Positive Score: %d\n", positive_score);
    printf("Negative Score: %d\n", negative_score);

    return 0;
}