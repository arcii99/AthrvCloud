//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: statistical
#include<stdio.h>
#include<string.h>

//Function to calculate sentiment score
int sentiment_score(char str[])
{
    int i, score=0, len=strlen(str);
 
    for(i=0; i<len; i++)
    {
        score += str[i];
    }

    return score;
}

//Main function
int main()
{
    char str[100];
    int score;

    printf("Enter the string: ");
    gets(str);

    score = sentiment_score(str);

    if(score > 100)
    {
        printf("Positive Sentiment");
    }
    else if(score < 100)
    {
        printf("Negative Sentiment");
    }
    else
    {
        printf("Neutral Sentiment");
    }

    return 0;
}