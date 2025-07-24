//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: futuristic
#include<stdio.h>
#include<string.h>

#define PRAISE_LEVEL 10  // maximum praise level allowed

// function to calculate the sentiment score of a given string
int sentiment_analysis(char* str)
{
    // list of positive and negative words
    char positive_words[10][20] = {"great", "excellent", "fantastic", "awesome", "amazing", "superb", "incredible", "terrific", "outstanding", "remarkable"};
    char negative_words[10][20] = {"bad", "terrible", "horrible", "awful", "poor", "disappointing", "pathetic", "dreadful", "lousy", "mediocre"};
   
    int sentiment_score = 0;  // initialize sentiment score to 0
    
    // loop through each word in the given string
    char* word = strtok(str, " ");
    while(word != NULL)
    {
        for(int i=0; i<10; i++)
        {
            // check if current word is in the positive or negative word list
            if(strcmp(word, positive_words[i]) == 0)
            {
                // increment sentiment score if positive word is found
                sentiment_score++;
            }
            else if(strcmp(word, negative_words[i]) == 0)
            {
                // decrement sentiment score if negative word is found
                sentiment_score--;
            }
        }
        // move to next word
        word = strtok(NULL, " ");
    }
    
    // check and limit sentiment score within the range of -10 to 10
    if(sentiment_score > PRAISE_LEVEL)
    {
        sentiment_score = PRAISE_LEVEL;
    }
    else if(sentiment_score < -PRAISE_LEVEL)
    {
        sentiment_score = -PRAISE_LEVEL;
    }
    
    return sentiment_score;
}

int main()
{
    char review[100];  // buffer to hold user review
    int sentiment_score;  // variable to hold sentiment score
    
    printf("Welcome to the sentiment analysis tool!\n");
    printf("Please enter your review: ");
    fgets(review, 100, stdin);  // get user input
    
    // calculate sentiment score and generate output
    sentiment_score = sentiment_analysis(review);
    if(sentiment_score > 0)
    {
        printf("Great review! Sentiment score: %d\n", sentiment_score);
    }
    else if(sentiment_score < 0)
    {
        printf("Sorry to hear that. Sentiment score: %d\n", sentiment_score);
    }
    else
    {
        printf("Neutral review. Sentiment score: %d\n", sentiment_score);
    }
    
    return 0;
}