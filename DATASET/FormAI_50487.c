//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000];
    int positive_count = 0, negative_count = 0, neutral_count = 0, total_count = 0;

    printf("Enter a sentence to perform sentiment analysis: ");
    fgets(sentence, 1000, stdin);

    char *word = strtok(sentence, " ");

    while(word != NULL)
    {
        if(strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0 || strcmp(word, "wonderful") == 0 || strcmp(word, "fantastic") == 0)
        {
            positive_count++;
        }
        else if(strcmp(word, "bad") == 0 || strcmp(word, "poor") == 0 || strcmp(word, "disappointing") == 0 || strcmp(word, "awful") == 0 || strcmp(word, "terrible") == 0)
        {
            negative_count++;
        }
        else
        {
            neutral_count++;
        }
        
        total_count++;
        word = strtok(NULL, " ");
    }

    printf("\nSentiment Analysis Results:\n");
    printf("------------------------------\n");
    printf("Positive Words: %d\n", positive_count);
    printf("Negative Words: %d\n", negative_count);
    printf("Neutral Words: %d\n", neutral_count);
    printf("Total Words: %d\n", total_count);

    if((float)positive_count/total_count > (float)negative_count/total_count)
    {
        printf("Overall Sentiment: Positive\n");
    }
    else if((float)negative_count/total_count > (float)positive_count/total_count)
    {
        printf("Overall Sentiment: Negative\n");
    }
    else
    {
        printf("Overall Sentiment: Neutral\n");
    }

    return 0;
}