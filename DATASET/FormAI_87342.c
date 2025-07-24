//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to display gratitude message
void gratitude()
{
    printf("\n\nThank you for using our sentiment analysis tool!\n");
    printf("We hope it has helped you gain insights into the sentiments expressed in your text.\n");
    printf("Your feedback is always welcome and appreciated!\n");
    printf("Have a great day ahead!\n\n");
}

int main()
{
    char text[1000];
    int sentiment = 0, i, neg_count = 0, pos_count = 0;
    const char delim[] = ",.?!;:";

    // get input text
    printf("Welcome to our Sentiment Analysis Tool!\n");
    printf("Please enter the text to be analyzed (maximum 1000 characters):\n");
    fgets(text, sizeof(text), stdin);

    // remove newline from input text
    text[strcspn(text, "\n")] = 0;

    // tokenize text by delimiter to analyze each word
    char *token = strtok(text, delim);
    while(token != NULL)
    {
        // check for positive words
        if(strcmp(token, "happy") == 0 || strcmp(token, "excited") == 0 || strcmp(token, "love") == 0 || strcmp(token, "amazing") == 0)
        {
            sentiment += 1;
            pos_count += 1;
        }
        // check for negative words
        else if(strcmp(token, "sad") == 0 || strcmp(token, "angry") == 0 || strcmp(token, "hate") == 0 || strcmp(token, "terrible") == 0)
        {
            sentiment -= 1;
            neg_count += 1;
        }
        token = strtok(NULL, delim);
    }

    // display sentiment score and message based on sentiment
    printf("\n\nSentiment Analysis Report:\n\n");
    if(sentiment > 0)
    {
        printf("Overall Sentiment Score: %d (Positive)\n", sentiment);
        printf("Positive Words Count: %d\n", pos_count);
        printf("Negative Words Count: %d\n", neg_count);
        printf("Congratulations! Your text expresses positive sentiments. Keep up the good work!\n");
    }
    else if(sentiment < 0)
    {
        printf("Overall Sentiment Score: %d (Negative)\n", sentiment);
        printf("Positive Words Count: %d\n", pos_count);
        printf("Negative Words Count: %d\n", neg_count);
        printf("Oops! Your text expresses negative sentiments. Let's try to be more positive.\n");
    }
    else
    {
        printf("Overall Sentiment Score: %d (Neutral)\n", sentiment);
        printf("Positive Words Count: %d\n", pos_count);
        printf("Negative Words Count: %d\n", neg_count);
        printf("Your text is neutral. Keep expressing yourself.\n");
    }

    // display gratitude message
    gratitude();

    return 0;
}