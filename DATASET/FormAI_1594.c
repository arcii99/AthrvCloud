//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: active
// A unique C Sentiment analysis tool example program
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];
    int positiveCount = 0, negativeCount = 0;
    printf("Enter a sentence (less than 100 characters): ");
    fgets(sentence, 100, stdin);
    for(int i = 0; i < strlen(sentence); i++)
    {
        // Check for positive and negative words
        if(sentence[i] == 'h' && sentence[i+1] == 'a' && sentence[i+2] == 'p' && sentence[i+3] == 'p' && sentence[i+4] == 'y')
        {
            positiveCount++;
            i += 4;
        }
        else if(sentence[i] == 'a' && sentence[i+1] == 'w' && sentence[i+2] == 'f' && sentence[i+3] == 'u' && sentence[i+4] == 'l')
        {
            negativeCount++;
            i += 4;
        }
        else if(sentence[i] == 'b' && sentence[i+1] == 'a' && sentence[i+2] == 'd')
        {
            negativeCount++;
            i += 2;
        }
        else if(sentence[i] == 'g' && sentence[i+1] == 'o' && sentence[i+2] == 'o' && sentence[i+3] == 'd')
        {
            positiveCount++;
            i += 3;
        }
    }
    // Calculate the sentiment score
    int sentimentScore = positiveCount - negativeCount;
    // Determine overall sentiment
    if(sentimentScore > 0)
    {
        printf("The sentiment of the sentence is positive!\n");
    }
    else if(sentimentScore == 0)
    {
        printf("The sentiment of the sentence is neutral.\n");
    }
    else
    {
        printf("The sentiment of the sentence is negative.\n");
    }
    return 0;
}