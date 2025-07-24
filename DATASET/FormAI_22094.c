//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Declaration of sentimentScore function
int sentimentScore(char paragraph[]);

int main()
{
    char review[500];    // To input the user review
    int score;           // To store the score
    
    // Taking user input
    printf("Enter your review: ");
    fgets(review, 500, stdin);
    
    // Calling sentimentScore function to get score
    score = sentimentScore(review);
    
    // Checking the score and printing the sentiment
    if(score > 0)
        printf("\nPositive Sentiment");
    else if(score < 0)
        printf("\nNegative Sentiment");
    else
        printf("\nNeutral Sentiment");
    
    return 0;
}

int sentimentScore(char paragraph[])
{
    int score = 0;
    char *token = strtok(paragraph, " ");  // Breaking the paragraph into words using strtok function
    
    while(token != NULL)
    {
        if(strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "excellent") == 0)
            score++;
        else if(strcmp(token, "bad") == 0 || strcmp(token, "poor") == 0 || strcmp(token, "worst") == 0)
            score--;
            
        token = strtok(NULL, " ");
    }
    
    return score;
}