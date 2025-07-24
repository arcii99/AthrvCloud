//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char review[1000];
    int pos_count=0, neg_count=0, neutral_count=0;

    printf("Enter your review: ");
    fgets(review, 1000, stdin); // Taking the input review as a string

    // Making the string lower case to make it case-insensitive
    int i=0;
    while(review[i])
    {
        review[i] = tolower(review[i]);
        i++;
    }

    // Positive words database
    char pos_words[20][20] = {"good","great","excellent","wonderful","awesome","superb","fantastic","terrific","nice","fine","amazing","delightful","lovely","outstanding","perfect","pleasure","satisfying","splendid","super","thrilling"};

    // Negative words database
    char neg_words[20][20] = {"bad","awful","terrible","poor","worst","disappointing","horrible","unsatisfactory","rubbish","pathetic","atrocious","ugly","disgusting","distasteful","fail","weak","inferior","lousy","trash","dump"};

    // Counting positive, negative and neutral words
    char *token = strtok(review, " .,!?\n");
    while(token != NULL)
    {
        for(int i=0;i<20;i++)
        {
            if(strcmp(token, pos_words[i]) == 0)
            {
                pos_count++;
                break;
            }
            else if(strcmp(token, neg_words[i]) == 0)
            {
                neg_count++;
                break;
            }
            else
            {
                neutral_count++;
                break;
            }
        }
        token = strtok(NULL, " .,!?\n");
    }

    printf("\nPositive words count: %d", pos_count);
    printf("\nNegative words count: %d", neg_count);
    printf("\nNeutral words count: %d\n", neutral_count);

    // Assigning the sentiment based on the word count
    if(pos_count > neg_count)
    {
        printf("Overall sentiment: Positive");
    }
    else if(neg_count > pos_count)
    {
        printf("Overall sentiment: Negative");
    }
    else
    {
        printf("Overall sentiment: Neutral");
    }

    return 0;
}