//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <string.h>

int main()
{
    char input[500]; // string to hold user input
    int pos_sentiment = 0, neg_sentiment = 0; // counters for positive and negative sentiment words
    char pos_words[6][50] = {"good", "great", "excellent", "happy", "love", "like"}; // positive sentiment words
    char neg_words[6][50] = {"bad", "awful", "terrible", "sad", "hate", "dislike"}; // negative sentiment words
    
    printf("Enter a phrase or sentence: ");
    fgets(input, 500, stdin); // read user input
    
    // loop through each positive sentiment word and count occurrences
    for(int i=0; i<6; i++)
    {
        char* found = strstr(input, pos_words[i]); // find the positive sentiment word
        while(found != NULL)
        {
            pos_sentiment++; // increment the counter
            found = strstr(found+1, pos_words[i]); // continue searching for the word after the previous occurrence
        }
    }
    
    // loop through each negative sentiment word and count occurrences
    for(int i=0; i<6; i++)
    {
        char* found = strstr(input, neg_words[i]); // find the negative sentiment word
        while(found != NULL)
        {
            neg_sentiment++; // increment the counter
            found = strstr(found+1, neg_words[i]); // continue searching for the word after the previous occurrence
        }
    }
    
    // print the sentiment analysis
    printf("\nSentiment Analysis:\n");
    if(pos_sentiment > neg_sentiment)
    {
        printf("Overall sentiment is Positive.\n");
        printf("Positive sentiment words found: %d\n", pos_sentiment);
        printf("Negative sentiment words found: %d\n", neg_sentiment);
    }
    else if(neg_sentiment > pos_sentiment)
    {
        printf("Overall sentiment is Negative.\n");
        printf("Negative sentiment words found: %d\n", neg_sentiment);
        printf("Positive sentiment words found: %d\n", pos_sentiment);
    }
    else
    {
        printf("Sentiment is Neutral.\n");
        printf("Positive sentiment words found: %d\n", pos_sentiment);
        printf("Negative sentiment words found: %d\n", neg_sentiment);
    }
    
    return 0;
}