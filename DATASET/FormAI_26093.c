//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include <stdio.h>
#include <string.h>

// A function that takes a sentence as input and returns the sentiment score
int sentiment_analysis(char sentence[]) {
    int score = 0;
    char *token;
    
    // Creating a list of positive words
    char positive_words[5][10] = {"great", "good", "excellent", "awesome", "fantastic"};
    
    // Creating a list of negative words
    char negative_words[5][10] = {"bad", "awful", "terrible", "horrible", "disappointing"};
    
    // Tokenizing the sentence using strtok function
    token = strtok(sentence, " ");
    while (token != NULL) {
        // Checking if the word is in the positive_words list
        for (int i=0; i<5; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                score++;
                break;
            }
        }
        
        // Checking if the word is in the negative_words list
        for (int i=0; i<5; i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                score--;
                break;
            }
        }
        
        // Getting the next word token
        token = strtok(NULL, " ");
    }
    
    return score;
}

int main() {
    // Testing the sentiment_analysis function
    char sentence[100] = "The movie was great and the food was terrible.";
    int score = sentiment_analysis(sentence);
    
    printf("The sentiment score of the sentence '%s' is: %d\n", sentence, score);
    
    return 0;
}