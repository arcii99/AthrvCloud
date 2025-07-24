//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    int positive = 0, negative = 0, neutral = 0;
    
    printf("Please enter a sentence to analyze: ");
    fgets(sentence, 100, stdin);
    
    // remove newline character
    sentence[strcspn(sentence, "\n")] = 0;
    
    // tokenize the sentence
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        // check if token is positive
        if (strstr("great amazing excellent awesome good happy love like", token) != NULL) {
            positive++;
        }
        // check if token is negative
        else if (strstr("bad terrible horrible awful hate dislike", token) != NULL) {
            negative++;
        }
        // otherwise, assume token is neutral
        else {
            neutral++;
        }
        token = strtok(NULL, " ");
    }
    
    // determine overall sentiment based on count of positive, negative, and neutral tokens
    if (positive > negative && positive > neutral) {
        printf("The sentence is positive!\n");
    }
    else if (negative > positive && negative > neutral) {
        printf("The sentence is negative.\n");
    }
    else {
        printf("The sentence is neutral.\n");
    }
    
    return 0;
}