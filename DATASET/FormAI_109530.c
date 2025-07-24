//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
// Function to calculate sentiment score
int calculateSentimentScore(char* sentence)
{
    // List of positive words
    const char positiveWords[][15] = {"good", "great", "awesome", "excellent", "fantastic", "terrific", "amazing"};
    int positiveWordsCount = sizeof(positiveWords)/sizeof(positiveWords[0]);
     
    // List of negative words
    const char negativeWords[][15] = {"bad", "poor", "terrible", "horrible", "awful", "worst", "disappointing"};
    int negativeWordsCount = sizeof(negativeWords)/sizeof(negativeWords[0]);
     
    // Split sentence by space and count total words
    char* token = strtok(sentence, " ");
    int totalWords = 0;
    while(token != NULL)
    {
        totalWords++;
        token = strtok(NULL, " ");
    }
     
    // Calculate sentiment score by comparing each word with positive and negative words
    int sentimentScore = 0;
    token = strtok(sentence, " ");
    while(token != NULL)
    {
        for(int i=0; i<positiveWordsCount; i++)
        {
            if(strcmp(token, positiveWords[i]) == 0)
            {
                sentimentScore++;
            }
        }
         
        for(int i=0; i<negativeWordsCount; i++)
        {
            if(strcmp(token, negativeWords[i]) == 0)
            {
                sentimentScore--;
            }
        }
 
        token = strtok(NULL, " ");
    }
 
    // Calculate sentiment score percentage
    float sentimentScorePercentage = ((float)sentimentScore / totalWords) * 100;
     
    printf("\nSentence: %s\n", sentence);
    printf("Total Words: %d\n", totalWords);
    printf("Sentiment Score: %d\n", sentimentScore);
    printf("Sentiment Score Percentage: %.2f%%\n", sentimentScorePercentage);
 
    return sentimentScore;
}
 
int main()
{
    // Sample sentences to test the sentiment analysis tool
    char sentence1[] = "I had a great day today.";
    char sentence2[] = "This movie was awesome, I loved it!";
    char sentence3[] = "The food was bad and the service was poor.";
     
    // Calculate sentiment score for each sentence
    int score1 = calculateSentimentScore(sentence1);
    int score2 = calculateSentimentScore(sentence2);
    int score3 = calculateSentimentScore(sentence3);
 
    // Draw conclusion based on sentiment score
    if(score1 > 0 && score1 > score2 && score1 > score3)
    {
        printf("\nConclusion: The first sentence has the most positive sentiment.\n");
    }
    else if(score2 > 0 && score2 > score1 && score2 > score3)
    {
        printf("\nConclusion: The second sentence has the most positive sentiment.\n");
    }
    else if(score3 < 0)
    {
        printf("\nConclusion: The third sentence has the most negative sentiment.\n");
    }
    else
    {
        printf("\nConclusion: All sentences have similarly neutral sentiment.\n");
    }
 
    return 0;
}