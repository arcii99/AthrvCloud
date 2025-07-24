//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000];
    printf("Enter a sentence for sentiment analysis: ");
    fgets(input, 1000, stdin);
    
    char positive_words[][20] = {"good", "happy", "love", "great", "excellent", "fantastic", "awesome", "amazing", "wonderful", "nice"};
    char negative_words[][20] = {"bad", "sad", "hate", "terrible", "horrible", "awful", "dislike", "worst", "unhappy", "angry"};
    
    int pos_count = 0;
    int neg_count = 0;
    
    char *word = strtok(input, " ,.-");
    while (word != NULL)
    {
        for (int i = 0; i < sizeof(positive_words)/sizeof(positive_words[0]); i++)
        {
            if (strcmp(word, positive_words[i]) == 0)
            {
                pos_count++;
            }
        }
        
        for (int j = 0; j < sizeof(negative_words)/sizeof(negative_words[0]); j++)
        {
            if (strcmp(word, negative_words[j]) == 0)
            {
                neg_count++;
            }
        }
        
        word = strtok(NULL, " ,.-");
    }
    
    if (pos_count > neg_count)
    {
        printf("Sentiment: Positive\n");
    }
    else if (neg_count > pos_count)
    {
        printf("Sentiment: Negative\n");
    }
    else
    {
        printf("Sentiment: Neutral\n");
    }
    
    return 0;
}