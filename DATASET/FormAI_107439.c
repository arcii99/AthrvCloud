//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARACTERS 200

int main()
{
    char text[MAX_CHARACTERS];
    int sentiment_score = 0;
    char *positive_words[] = {"happy", "love", "excited", "success", "celebrate", "fun"};
    char *negative_words[] = {"sad", "hate", "depressed", "failure", "bad", "pain"};

    printf("Enter text to analyze sentiment: ");
    fgets(text, MAX_CHARACTERS, stdin);

    // Remove newline character from input
    text[strcspn(text, "\n")] = '\0';

    // Tokenize input text into words
    char *word = strtok(text, " ");

    while (word != NULL) 
    {
        // Check if word is positive
        for (int i = 0; i < sizeof(positive_words)/sizeof(positive_words[0]); i++)
        {
            if (strcmp(positive_words[i], word) == 0)
            {
                sentiment_score++;
                break;
            }
        }
        
        // Check if word is negative
        for (int i = 0; i < sizeof(negative_words)/sizeof(negative_words[0]); i++)
        {
            if (strcmp(negative_words[i], word) == 0)
            {
                sentiment_score--;
                break;
            }
        }

        word = strtok(NULL, " ");
    }

    if (sentiment_score > 0)
    {
        printf("Positive sentiment\n");
    }
    else if (sentiment_score < 0)
    {
        printf("Negative sentiment\n");
    }
    else
    {
        printf("Neutral sentiment\n");
    }

    return 0;
}