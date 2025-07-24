//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int analyze_sentiment(char* input_text);

int main()
{
    char input_text[1000];
    printf("Please enter the input text: ");
    fgets(input_text, 1000, stdin);

    int sentiment_score = analyze_sentiment(input_text);

    if (sentiment_score > 0)
    {
        printf("Positive Sentiment\n");
    }
    else if (sentiment_score < 0)
    {
        printf("Negative Sentiment\n");
    }
    else
    {
        printf("Neutral Sentiment\n");
    }

    return 0;
}

int analyze_sentiment(char* input_text)
{
    int positive_words_count = 0;
    int negative_words_count = 0;

    char positive_words[6][20] = {"good", "great", "nice", "excellent", "best", "wonderful"};
    char negative_words[6][20] = {"bad", "terrible", "worst", "awful", "poor", "disappointing"};

    char* token = strtok(input_text, " ");

    while(token != NULL)
    {
        for (int i = 0; i < 6; i++)
        {
            if (strcmp(token, positive_words[i]) == 0)
            {
                positive_words_count++;
            }

            if (strcmp(token, negative_words[i]) == 0)
            {
                negative_words_count++;
            }
        }

        token = strtok(NULL, " ");
    }

    return positive_words_count - negative_words_count;
}