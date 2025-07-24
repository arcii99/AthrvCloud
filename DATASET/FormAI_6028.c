//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to calculate sentiment score of a sentence
int sentiment_score(char sentence[])
{
    int positive = 0;
    int negative = 0;
    int neutral = 0;

    // List of positive and negative words
    char positive_words[10][10] = {"good", "great", "nice", "excellent", "positive", "fortunate", "superior", "superb", "outstanding", "fantastic"};
    char negative_words[10][10] = {"bad", "terrible", "awful", "horrible", "negative", "unfortunate", "inferior", "poor", "worst", "disgusting"};

    // Tokenizing the sentence into words
    char *word = strtok(sentence, " ");
    while(word != NULL)
    {
        // Checking if the word is positive or negative
        for(int i=0; i<10; i++)
        {
            if(strcmp(word, positive_words[i]) == 0)
            {
                positive++;
            }
            if(strcmp(word, negative_words[i]) == 0)
            {
                negative++;
            }
        }
        word = strtok(NULL, " ");
    }

    // Classifying the sentiment of the sentence based on positive and negative words count
    if(positive > negative)
    {
        return 1;
    }
    else if(positive < negative)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char sentence[100];

    // Reading input sentence
    printf("Enter the sentence: ");
    fgets(sentence, 100, stdin);

    // Calculating the sentiment score of the sentence
    int sentiment = sentiment_score(sentence);

    // Displaying the sentiment of the sentence
    if(sentiment == 1)
    {
        printf("\nThis sentence is positive.");
    }
    else if(sentiment == -1)
    {
        printf("\nThis sentence is negative.");
    }
    else
    {
        printf("\nThis sentence is neutral.");
    }

    return 0;
}