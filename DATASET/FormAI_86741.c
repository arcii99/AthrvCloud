//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    // Variables for input
    char text[1000],ch;
    int i, j, n, length, positive = 0, negative = 0, neutral = 0;

    // Input text from user
    printf("Enter text: ");
    scanf("%[^\n]%*c", text);

    // Define the length of the text
    length = strlen(text);

    // Convert to lowercase
    for(i=0; i<length; i++)
        text[i] = tolower(text[i]);

    // Define positive and negative words
    char positive_words[20][20] = {"good", "great", "excellent", "awesome", "amazing", "happy", "love", "admire", "perfect", "nice", "fantastic", "incredible", "exquisite", "delightful", "pleased", "best", "satisfy", "commendable", "faithful", "advocate"};
    char negative_words[20][20] = {"bad", "ugly", "hate", "dislike", "terrible", "awful", "horrible", "unhappy", "displeased", "poor", "inferior", "disappoint", "ruin", "offend", "unacceptable", "faulty", "imperfect", "wrong", "unworthy", "unsatisfactory"};

    // Separate the text into words
    char words[20][20];
    n = 0;
    for(i=0; i<length; i++)
    {
        j=0;
        while((text[i] != ' ') && (text[i] != '\0'))
        {
            words[n][j] = text[i];
            i++;
            j++;
        }
        words[n][j] = '\0';
        n++;
    }

    // Calculate number of positive, negative and neutral words
    for(i=0; i<n; i++)
    {
        for(j=0; j<20; j++)
        {
            if(strcmp(words[i], positive_words[j]) == 0)
            {
                positive++;
                break;
            }
            else if(strcmp(words[i], negative_words[j]) == 0)
            {
                negative++;
                break;
            }
        }
        if(j == 20)
            neutral++;
    }

    // Calculate sentiment score
    float sentiment_score = ((float)positive - (float)negative) / (float)n;

    // Print the sentiment score and sentiment analysis
    if(sentiment_score > 0.25)
    {
        printf("\nSentiment score: %f \nSentiment Analysis: Positive", sentiment_score);
    }
    else if(sentiment_score < -0.25)
    {
        printf("\nSentiment score: %f \nSentiment Analysis: Negative", sentiment_score);
    }
    else
    {
        printf("\nSentiment score: %f \nSentiment Analysis: Neutral", sentiment_score);
    }

    return 0;
}