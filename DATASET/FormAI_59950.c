//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Function to check whether the given input is a valid sentiment
int checkSentiment(char *input)
{
    // List of positive words
    char *positive[] = { "good", "happy", "love", "excited", "great" };
 
    // List of negative words
    char *negative[] = { "bad", "sad", "hate", "disappointed", "terrible" };
 
    // Loop through all positive words
    for (int i = 0; i < sizeof(positive) / sizeof(positive[0]); i++) {
        if (strcmp(input, positive[i]) == 0)
            return 1; // Input is positive
    }
 
    // Loop through all negative words
    for (int i = 0; i < sizeof(negative) / sizeof(negative[0]); i++) {
        if (strcmp(input, negative[i]) == 0)
            return -1; // Input is negative
    }
 
    return 0; // Input is neutral
}
 
int main()
{
    char input[100];
    printf("Enter a sentiment: ");
    fgets(input, 100, stdin);
 
    // Remove the trailing newline character from input
    input[strcspn(input, "\n")] = 0;
 
    int sentiment = checkSentiment(input);
 
    printf("\nSentiment analysis result: ");
    if (sentiment == 1)
        printf("Positive\n");
    else if (sentiment == -1)
        printf("Negative\n");
    else
        printf("Neutral\n");
 
    return 0;
}