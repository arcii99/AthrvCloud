//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define the maximum string length
#define MAX_LENGTH 100

// function to calculate the sentiment score
int calculateSentimentScore(char *sentence)
{
    // define the positive and negative words
    char *positive_words[] = {"love", "good", "happy", "great", "excellent"};
    char *negative_words[] = {"hate", "bad", "sad", "terrible", "awful"};

    // calculate the number of positive and negative words in the sentence
    int positive_count = 0;
    int negative_count = 0;

    // tokenize the sentence
    char *token = strtok(sentence, " ");

    while(token != NULL)
    {
        // check for positive words
        for(int i=0; i<sizeof(positive_words)/sizeof(char *); i++)
        {
            if(strcmp(token, positive_words[i]) == 0)
            {
                positive_count++;
            }
        }

        // check for negative words
        for(int i=0; i<sizeof(negative_words)/sizeof(char *); i++)
        {
            if(strcmp(token, negative_words[i]) == 0)
            {
                negative_count++;
            }
        }

        // move to the next token
        token = strtok(NULL, " ");
    }

    // calculate the sentiment score
    int sentiment_score = positive_count - negative_count;

    return sentiment_score;
}

// main function
int main()
{
    // define a string to store the input
    char input[MAX_LENGTH];

    // get the input from the user
    printf("Enter a sentence: ");
    fgets(input, MAX_LENGTH, stdin);

    // replace the newline character with null character
    input[strcspn(input, "\n")] = '\0';

    // calculate the sentiment score
    int sentiment_score = calculateSentimentScore(input);

    // display the sentiment score
    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}