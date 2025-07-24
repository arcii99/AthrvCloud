//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LEN 100  // Maximum length of the text to be analyzed

int main()
{
    char text[MAX_TEXT_LEN];
    int sentiment_score = 0;

    // Prompt user for input text to be analyzed
    printf("Enter text to be analyzed (max %d characters): ", MAX_TEXT_LEN);
    fgets(text, MAX_TEXT_LEN, stdin);

    // Loop through each character in the text and compute sentiment score
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == 'g' && text[i+1] == 'o' && text[i+2] == 'o' && text[i+3] == 'd') {
            sentiment_score += 1;
        } else if (text[i] == 'b' && text[i+1] == 'a' && text[i+2] == 'd') {
            sentiment_score -= 1;
        }
    }

    // Print sentiment score to user
    printf("Sentiment Score: %d\n", sentiment_score);

    // Determine overall sentiment based on sentiment score
    if (sentiment_score > 0) {
        printf("Overall Sentiment: Positive\n");
    } else if (sentiment_score < 0) {
        printf("Overall Sentiment: Negative\n");
    } else {
        printf("Overall Sentiment: Neutral\n");
    }

    return 0;
}