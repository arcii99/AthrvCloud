//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to perform sentiment analysis
void performSentimentAnalysis(char *text)
{
    int positiveWordsCount = 0;
    int negativeWordsCount = 0;
    int neutralWordsCount = 0;
    char *token;

    // Positive words list
    char *positiveWords[] = {"good", "great", "awesome", "excellent", "fantastic"};

    // Negative words list
    char *negativeWords[] = {"bad", "poor", "terrible", "horrible", "disappointing"};

    // Tokenize the text
    token = strtok(text, " ");

    while (token != NULL)
    {
        // Check if token is positive or negative
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(token, positiveWords[i]) == 0)
            {
                positiveWordsCount++;
            }
            else if (strcmp(token, negativeWords[i]) == 0)
            {
                negativeWordsCount++;
            }
            else
            {
                neutralWordsCount++;
            }
        }

        // Move to next token
        token = strtok(NULL, " ");
    }

    // Determine sentiment based on word count
    if (positiveWordsCount > negativeWordsCount)
    {
        printf("Sentiment: Positive\n");
    }
    else if (negativeWordsCount > positiveWordsCount)
    {
        printf("Sentiment: Negative\n");
    }
    else
    {
        printf("Sentiment: Neutral\n");
    }
}

int main()
{
    char text[1000];

    // Take user input
    printf("Enter text for sentiment analysis: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character
    text[strcspn(text, "\n")] = 0;

    // Call the sentiment analysis function
    performSentimentAnalysis(text);

    return 0;
}