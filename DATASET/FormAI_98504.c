//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS 1000000   // Maximum number of characters allowed in input text

int main() {
    char input_text[MAX_CHARS]; // Input text
    char keywords[10][50] = {"good", "bad", "happy", "sad", "love", "hate", "positive", "negative", "like", "dislike"}; // Array of keywords to match against
    int keyword_count[10] = {0}; // Count of keyword occurrences
    
    printf("Enter the text to analyze:\n");
    fgets(input_text, MAX_CHARS, stdin); // Read input text from user
    
    // Convert input text to lowercase
    for(int i=0; input_text[i]!='\0'; i++){
        if(input_text[i]>='A' && input_text[i]<='Z'){
            input_text[i] = input_text[i] + 32;
        }
    }
    
    // Match keywords with input text
    char *ptr = strtok(input_text, " .,!?\n"); // Tokenize input text based on spaces, punctuations and newlines
    while(ptr != NULL) {
        for(int i=0; i<10; i++) {
            if(strcmp(ptr, keywords[i]) == 0) {
                keyword_count[i]++;
            }
        }
        ptr = strtok(NULL, " .,!?\n");
    }
    
    // Calculate sentiment score based on keyword occurrences
    int positive_score = keyword_count[0] + keyword_count[2] + keyword_count[4] + keyword_count[6] + keyword_count[8];
    int negative_score = keyword_count[1] + keyword_count[3] + keyword_count[5] + keyword_count[7] + keyword_count[9];
    int sentiment_score = positive_score - negative_score;
    
    // Output sentiment score
    printf("Sentiment score: %d\n", sentiment_score);
    if(sentiment_score > 0) {
        printf("Sentiment: Positive\n");
    } else if(sentiment_score < 0) {
        printf("Sentiment: Negative\n");
    } else {
        printf("Sentiment: Neutral\n");
    }
    
    return 0;
}