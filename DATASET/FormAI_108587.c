//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000

int main()
{
    char text[MAX_TEXT_LENGTH];
    printf("Enter the text to be analyzed:\n");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    int positive_count = 0;
    int negative_count = 0;
    int neutral_count = 0;

    char* token = strtok(text, " ");

    while (token != NULL)
    {
        int sentiment_score = 0;
        char* word = token;

        // Convert the word to lowercase
        for (int i = 0; i < strlen(word); i++)
        {
            word[i] = tolower(word[i]);
        }

        // Check if the word is positive
        if (strcmp(word, "good") == 0 ||
            strcmp(word, "great") == 0 ||
            strcmp(word, "excellent") == 0)
        {
            sentiment_score = 1;
        }
        // Check if the word is negative
        else if (strcmp(word, "bad") == 0 ||
                 strcmp(word, "terrible") == 0 ||
                 strcmp(word, "horrible") == 0)
        {
            sentiment_score = -1;
        }

        // Update the sentiment counts based on the sentiment score
        if (sentiment_score > 0)
        {
            positive_count++;
        }
        else if (sentiment_score < 0)
        {
            negative_count++;
        }
        else
        {
            neutral_count++;
        }

        // Get the next word
        token = strtok(NULL, " ");
    }

    // Output the results
    printf("\nSentiment Analysis Results:\n");
    printf("-------------------------------------------\n");
    printf("Positive Words: %d\n", positive_count);
    printf("Negative Words: %d\n", negative_count);
    printf("Neutral Words: %d\n", neutral_count);
    printf("\nOverall Sentiment: %s\n", (positive_count > negative_count) ? "Positive" : "Negative");

    return 0;
}