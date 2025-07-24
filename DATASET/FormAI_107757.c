//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: brave
#include<stdio.h>
#include<string.h>

// Function to calculate sentiment score
float sentimentScore(char tweet[200])
{
    char positiveWords[10][20] = {"good", "great", "awesome", "excellent", "fantastic", "wonderful", "nice", "love", "like", "happy"};
    char negativeWords[10][20] = {"bad", "terrible", "horrible", "awful", "disgusting", "hate", "dislike", "sad", "angry", "unhappy"};
    int positiveCount = 0, negativeCount = 0;
    float sentimentScore = 0;
    
    // Splitting the tweet into words
    char *word = strtok(tweet, " ");
    while(word != NULL)
    {
        for(int i=0; i<10; i++)
        {
            // Checking if word is positive or negative
            if(strcmp(word, positiveWords[i]) == 0)
            {
                positiveCount++;
                break;
            }
            else if(strcmp(word, negativeWords[i]) == 0)
            {
                negativeCount++;
                break;
            }    
        }
        word = strtok(NULL, " ");
    }
    
    // Calculating sentiment score
    if(positiveCount > negativeCount)
    {
        sentimentScore = ((positiveCount - negativeCount) * 100.0) / (positiveCount + negativeCount);
    }
    else if(positiveCount < negativeCount)
    {
        sentimentScore = -((negativeCount - positiveCount) * 100.0) / (positiveCount + negativeCount);
    }
    
    return sentimentScore;
}

int main()
{
    char tweet[200];

    printf("Enter your tweet: ");
    fgets(tweet, sizeof(tweet), stdin);
    
    float score = sentimentScore(tweet);

    if (score > 0)
        printf("The sentiment score of your tweet is %f%%. It's a positive tweet!", score);
    else if (score < 0)
        printf("The sentiment score of your tweet is %f%%. It's a negative tweet!", score);
    else
        printf("The sentiment score of your tweet is %f%%. It's a neutral tweet!", score);

    return 0;
}