//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to perform sentiment analysis and return its score
int sentiment_analysis(char *text) {
    int score = 0;
    char *tok;
    const char delimeters[] = " ,-!?.";

    // define words and their corresponding sentiment score
    struct sentiment {
        char *word;
        int score;
    } sentiment_words[] = {
        {"happy", 10},
        {"joy", 8},
        {"good", 7},
        {"sad", -10},
        {"hate", -8},
        {"bad", -7},
        {NULL, 0}
    };
    
    // tokenize input text and compare each word with sentiment_words list
    tok = strtok(text, delimeters);
    while (tok != NULL) {
        for (int i = 0; sentiment_words[i].word != NULL; i++) {
            if (strcmp(tok, sentiment_words[i].word) == 0) {
                score += sentiment_words[i].score;
            }
        }
        tok = strtok(NULL, delimeters);
    }
    
    return score;
}

int main() {
    char text[100];
    int score;
    
    // get user input
    printf("Enter some text to analyze sentiment: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // remove newline character
    
    // perform sentiment analysis and print result
    score = sentiment_analysis(text);
    printf("Sentiment analysis score: %d\n", score);
    
    return 0;
}