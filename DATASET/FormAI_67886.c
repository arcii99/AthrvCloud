//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: modular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function to calculate sentiment score
int calc_sentiment_score(char* sentence, char** pos_words, char** neg_words, int num_pos_words, int num_neg_words)
{
    int sentiment_score = 0;
    char* token = strtok(sentence, " "); // tokenize input sentence
    while(token != NULL)
    {
        // Check if token is positive or negative word
        for(int i = 0; i < num_pos_words; i++)
        {
            if(strcmp(token, pos_words[i]) == 0)
            {
                sentiment_score++;
                break;
            }
        }
        for(int i = 0; i < num_neg_words; i++)
        {
            if(strcmp(token, neg_words[i]) == 0)
            {
                sentiment_score--;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return sentiment_score;
}

int main()
{
    // Positive and negative word lists
    char* pos_words[] = {"good", "happy", "love", "great", "excellent"};
    int num_pos_words = 5;
    char* neg_words[] = {"bad", "sad", "hate", "terrible", "awful"};
    int num_neg_words = 5;

    // User input sentence
    char sentence[100];
    printf("Enter a sentence to get its sentiment score: ");
    fgets(sentence, 100, stdin);

    // Calculate sentiment score
    int sentiment_score = calc_sentiment_score(sentence, pos_words, neg_words, num_pos_words, num_neg_words);

    // Output sentiment score
    printf("The sentiment score of the input sentence is: %d\n", sentiment_score);

    return 0;
}