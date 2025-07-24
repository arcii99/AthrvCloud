//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include<stdio.h>
#include<string.h>

int main()
{
    char sentence[1000];
    int positive_count = 0, negative_count = 0, neutral_count = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Tokenize the input sentence
    char *token = strtok(sentence, " ");

    while(token != NULL)
    {
        // Check if the word is positive
        if(strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "excellent") == 0 || strcmp(token, "happy") == 0)
            positive_count++;
        // Check if the word is negative
        else if(strcmp(token, "bad") == 0 || strcmp(token, "terrible") == 0 || strcmp(token, "awful") == 0 || strcmp(token, "sad") == 0)
            negative_count++;
        // Otherwise, the word is neutral
        else
            neutral_count++;

        token = strtok(NULL, " ");
    }

    // Determine overall sentiment based on counts
    if(positive_count > negative_count)
        printf("\nOverall sentiment is positive.");
    else if(negative_count > positive_count)
        printf("\nOverall sentiment is negative.");
    else
        printf("\nOverall sentiment is neutral.");

    return 0;
}