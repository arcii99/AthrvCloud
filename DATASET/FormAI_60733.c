//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: lively
// Welcome to the Sentiment Analyzer Tool!
// This tool takes in a sentence as input and predicts the sentiment of the sentence as either Positive, Negative, or Neutral

#include <stdio.h>
#include <string.h>

int main() {

    char sentence[100]; // Declare the character array for the sentence
    int sentiment = 0; // Declare sentiment integer, 0 represents Neutral, 1 represents Positive, -1 represents Negative

    printf("Enter your sentence:\n");
    scanf("%[^\n]s", sentence); // Get the input sentence and store it in the sentence variable
    
    // Convert the sentence to all lowercase to simplify the analysis
    for(int i = 0; i < strlen(sentence); i++) {
        sentence[i] = tolower(sentence[i]);
    }

    // Detect Positive words in the sentence
    if(strstr(sentence, "love") != NULL || strstr(sentence, "great") != NULL || strstr(sentence, "good") != NULL || strstr(sentence, "fantastic") != NULL || strstr(sentence, "amazing") != NULL || strstr(sentence, "wonderful") != NULL || strstr(sentence, "awesome") != NULL) {
        sentiment = 1;
    }

    // Detect Negative words in the sentence
    if(strstr(sentence, "hate") != NULL || strstr(sentence, "bad") != NULL || strstr(sentence, "terrible") != NULL || strstr(sentence, "awful") != NULL || strstr(sentence, "poor") != NULL || strstr(sentence, "dislike") != NULL || strstr(sentence, "worst") != NULL) {
        sentiment = -1;
    }

    if(sentiment == 0) {
        printf("\nYour sentence has a Neutral sentiment.\n");
    } else if(sentiment == 1) {
        printf("\nYour sentence has a Positive sentiment.\n");
    } else {
        printf("\nYour sentence has a Negative sentiment.\n");
    }

    return 0;
}