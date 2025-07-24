//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include<stdio.h>
#include<string.h>

// function to calculate the sentiment score of a sentence
int calculateSentimentScore(char sentence[]) {
    
    // list of positive and negative words
    char positiveWords[10][20] = {"good", "happy", "love", "excellent", "great", "amazing", "fantastic", "nice", "beautiful", "wonderful"};
    char negativeWords[10][20] = {"bad", "sad", "hate", "terrible", "awful", "dislike", "horrible", "ugly", "annoying", "disgusting"};
    
    int sentimentScore = 0; // initializing sentiment score to 0
    
    // splitting sentence into individual words
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        
        // checking if the word is present in positive words list
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, positiveWords[i]) == 0) {
                sentimentScore += 1; // incrementing score by 1
                break;
            }
        }
        
        // checking if the word is present in negative words list
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, negativeWords[i]) == 0) {
                sentimentScore -= 1; // decrementing score by 1
                break;
            }
        }
        
        word = strtok(NULL, " "); // getting the next word
    }
    
    return sentimentScore; // returning the sentiment score
}

int main() {
    
    char sentence[100]; // maximum length of the sentence is 100 characters
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin); // getting input from user
    
    int sentimentScore = calculateSentimentScore(sentence);
    if (sentimentScore > 0) {
        printf("Sentiment Score: %d. Positive sentiment detected!\n", sentimentScore);
    }
    else if (sentimentScore < 0) {
        printf("Sentiment Score: %d. Negative sentiment detected!\n", sentimentScore);
    }
    else {
        printf("Sentiment Score: %d. Neutral sentiment detected!\n", sentimentScore);
    }
    
    return 0;
}