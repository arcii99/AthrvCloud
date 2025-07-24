//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_str[1000];
    int pos_words = 0, neg_words = 0;
    char *positive[] = {"happy", "excited", "love", "good", "great"};
    char *negative[] = {"sad", "depressed", "hate", "bad", "terrible"};

    printf("Enter your sentence: ");
    fgets(input_str, 1000, stdin);

    char *token;
    token = strtok(input_str, " ");

    while (token != NULL) 
    {
        for (int i = 0; i < 5; i++) 
        {
            if (strcmp(token, positive[i]) == 0) 
            {
                pos_words++;
            }
            else if (strcmp(token, negative[i]) == 0) 
            {
                neg_words++;
            }
        }
        token = strtok(NULL, " ");
    }

    if (pos_words > neg_words) 
    {
        printf("Positive sentiment detected!\n");
    }
    else if (neg_words > pos_words) 
    {
        printf("Negative sentiment detected.\n");
    } 
    else 
    {
        printf("Neutral sentiment detected.\n");
    }

    return 0;
}