//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate_sentiment(char *text); // function declaration

int main()
{
    char text[1000]; // text input
    int sentiment_score; // sentiment score output

    printf("Enter text for sentiment analysis:\n");
    fgets(text, 1000, stdin); // read input

    sentiment_score = calculate_sentiment(text); // calculate sentiment score

    // display sentiment score
    if(sentiment_score > 0)
    {
        printf("Positive sentiment with score of %d\n", sentiment_score);
    }
    else if(sentiment_score == 0)
    {
        printf("Neutral sentiment with score of %d\n", sentiment_score);
    }
    else
    {
        printf("Negative sentiment with score of %d\n", sentiment_score);
    }

    return 0;
}

int calculate_sentiment(char *text)
{
    char *positive_words[] = {"good", "excellent", "happy", "love", "great", "wonderful"};
    char *negative_words[] = {"bad", "terrible", "poor", "hate", "awful", "worst"};
    int positive_score = 0, negative_score = 0;
    char *word = strtok(text, " ,\n");

    while(word != NULL) // loop through each word
    {
        // check if word is in positive words list
        for(int i = 0; i < 6; i++)
        {
            if(strcmp(word, positive_words[i]) == 0)
            {
                positive_score++; // increment positive score
                break;
            }
        }

        // check if word is in negative words list
        for(int i = 0; i < 6; i++)
        {
            if(strcmp(word, negative_words[i]) == 0)
            {
                negative_score++; // increment negative score
                break;
            }
        }

        word = strtok(NULL, " ,\n"); // get next word
    }

    return positive_score - negative_score; // calculate sentiment score
}