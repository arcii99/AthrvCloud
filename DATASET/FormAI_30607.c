//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_LEN 1000

// Define positive and negative words
char positive_words[5][50] = {"love", "happy", "great", "awesome", "fun"};
char negative_words[5][50] = {"hate", "sad", "terrible", "awful", "boring"};

// Main function
int main()
{
    // Declare variables
    char input[MAX_LEN];
    int positive_count = 0, negative_count = 0;
    float sentiment_score;

    // Get user input
    printf("Enter your statement for sentiment analysis: \n");
    fgets(input, MAX_LEN, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Tokenize input into words
    char *token = strtok(input, " ");

    // Iterate over each word in the input
    while (token != NULL)
    {
        // Check if the word is positive or negative and increment count
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(token, positive_words[i]) == 0)
            {
                positive_count++;
                break;
            }
            else if (strcmp(token, negative_words[i]) == 0)
            {
                negative_count++;
                break;
            }
        }

        // Get the next word in the input
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment score
    sentiment_score = (float) (positive_count - negative_count) / (positive_count + negative_count);

    // Determine sentiment based on sentiment score
    if (sentiment_score > 0)
    {
        printf("Your statement is positive with a sentiment score of %.2f\n", sentiment_score);
    }
    else if (sentiment_score < 0)
    {
        printf("Your statement is negative with a sentiment score of %.2f\n", sentiment_score);
    }
    else
    {
        printf("Your statement is neutral\n");
    }

    return 0;
}