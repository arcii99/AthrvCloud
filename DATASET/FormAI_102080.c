//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    char input[1000];
    int positive_count = 0, negative_count = 0;
    double total_score = 0;
    
    // Get user input
    printf("Enter the text to be analyzed: ");
    fgets(input, 1000, stdin);
    
    // Split the input text into words
    char *word;
    word = strtok(input, " .,!\n");

    // Loop through each word and calculate its score
    while (word != NULL) {
        // Convert the word to lowercase
        int i;
        for (i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        
        // Check if the word is positive or negative
        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
            positive_count++;
            total_score += 0.8;
        } else if (strcmp(word, "bad") == 0 || strcmp(word, "poor") == 0 || strcmp(word, "terrible") == 0) {
            negative_count++;
            total_score -= 0.8;
        } else if (strcmp(word, "love") == 0 || strcmp(word, "like") == 0 || strcmp(word, "enjoy") == 0) {
            positive_count++;
            total_score += 0.5;
        } else if (strcmp(word, "hate") == 0 || strcmp(word, "dislike") == 0 || strcmp(word, "unhappy") == 0) {
            negative_count++;
            total_score -= 0.5;
        }
        
        // Get the next word
        word = strtok(NULL, " .,!\n");
    }
    
    // Determine the overall sentiment
    double sentiment_score = total_score / (positive_count + negative_count);
    if (sentiment_score > 0.5) {
        printf("The sentiment is positive\n");
    } else if (sentiment_score < -0.5) {
        printf("The sentiment is negative\n");
    } else {
        printf("The sentiment is neutral\n");
    }
    
    return 0;
}