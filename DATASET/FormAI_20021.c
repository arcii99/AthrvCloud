//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000], emo[100];
    int positive_count = 0, negative_count = 0, neutral_count = 0, i;
    float pos_percent, neg_percent, neu_percent;

    printf("Enter text to perform sentiment analysis:\n");
    fgets(input, 1000, stdin);

    char *pos_words[] = {"good", "happy", "joyful", "excellent", "love", "great", "nice", "amazing", "wonderful", "fantastic"};
    char *neg_words[] = {"bad", "sad", "angry", "hate", "terrible", "horrible", "awful", "dislike", "disgusting", "annoying"};

    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            input[i] = input[i] + 32;
        }
    }

    int pos_words_len = sizeof(pos_words) / sizeof(pos_words[0]);
    int neg_words_len = sizeof(neg_words) / sizeof(neg_words[0]);

    char *word = strtok(input, " ");
    while (word != NULL)
    {
        for (i = 0; i < pos_words_len; i++)
        {
            if (strstr(word, pos_words[i]) != NULL)
            {
                positive_count++;
            }
        }

        for (i = 0; i < neg_words_len; i++)
        {
            if (strstr(word, neg_words[i]) != NULL)
            {
                negative_count++;
            }
        }
        
        word = strtok(NULL, " ");
    }

    neutral_count = strlen(input) - positive_count - negative_count;

    if(positive_count > negative_count)
    {
        strcpy(emo, "Positive");
    }
    else if(negative_count > positive_count)
    {
        strcpy(emo, "Negative");
    }
    else
    {
        strcpy(emo, "Neutral");
    }

    pos_percent = ((float) positive_count / (float) strlen(input)) * 100.0;
    neg_percent = ((float) negative_count / (float) strlen(input)) * 100.0;
    neu_percent = ((float) neutral_count / (float) strlen(input)) * 100.0;

    printf("\n\nSentiment Analysis Results:\n");
    printf("----------------------------\n");
    printf("Positive Words Count: %d\n", positive_count);
    printf("Negative Words Count: %d\n", negative_count);
    printf("Neutral Words Count: %d\n", neutral_count);
    printf("Most Common Sentiment in the Text: %s\n", emo);
    printf("Positive Percentage: %.2f%%\n", pos_percent);
    printf("Negative Percentage: %.2f%%\n", neg_percent);
    printf("Neutral Percentage: %.2f%%\n", neu_percent);

    return 0;
}