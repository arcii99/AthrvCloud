//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[100];
    int positive = 0, negative = 0;

    printf("Enter a message to analyze sentiment:\n");
    fgets(message, sizeof(message), stdin); // read input from user

    // split message into words
    char *word = strtok(message, " ");
    while (word != NULL)
    {
        // count positive words
        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 
            || strcmp(word, "excellent") == 0 || strcmp(word, "fantastic") == 0)
        {
            positive++;
        }

        // count negative words
        if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 
            || strcmp(word, "poor") == 0 || strcmp(word, "awful") == 0)
        {
            negative++;
        }

        word = strtok(NULL, " "); // get next word
    }

    // calculate sentiment score
    int sentiment = positive - negative;

    // determine sentiment rating based on score
    char *rating;
    if (sentiment > 0)
    {
        rating = "positive";
    }
    else if (sentiment < 0)
    {
        rating = "negative";
    }
    else
    {
        rating = "neutral";
    }

    // display results
    printf("Sentiment analysis results:\n");
    printf("Positive words: %d\n", positive);
    printf("Negative words: %d\n", negative);
    printf("Sentiment score: %d\n", sentiment);
    printf("Sentiment rating: %s\n", rating);

    return 0;
}