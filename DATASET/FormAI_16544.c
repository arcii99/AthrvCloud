//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multivariable
#include<stdio.h>
#include<string.h>
#include<math.h>

float pos=0, neg=0, neu=0;

void sentimentAnalysis(char *s)
{
    char *token=strtok(s," ");
    while(token!=NULL)
    {
        if(strstr(token, "good") || strstr(token,"great") || strstr(token,"excellent") || strstr(token,"amazing"))
        {
            pos++;
        }
        else if(strstr(token,"bad") || strstr(token,"terrible") || strstr(token,"worst") || strstr(token,"awful"))
        {
            neg++;
        }
        else
        {
            neu++;
        }
        token=strtok(NULL," ");
    }
}

int main()
{
    char text[1000];
    printf("Enter the text: ");
    fgets(text, 1000, stdin);
    sentimentAnalysis(text);

    printf("\nAnalysis Result:\n");
    printf("Positive words: %f\n", pos);
    printf("Negative words: %f\n", neg);
    printf("Neutral words: %f\n", neu);

    float total = pos+neg+neu;
    float pos_percent = (pos/total)*100;
    float neg_percent = (neg/total)*100;
    float neu_percent = (neu/total)*100;

    printf("\nPercentage of sentiment:\n");
    printf("Positive: %.2f%%\n", pos_percent);
    printf("Negative: %.2f%%\n", neg_percent);
    printf("Neutral: %.2f%%\n", neu_percent);

    if(pos_percent>neg_percent && pos_percent>neu_percent)
    {
        printf("\nThe given text has a Positive Sentiment");
    }
    else if(neg_percent>pos_percent && neg_percent>neu_percent)
    {
        printf("\nThe given text has a Negative Sentiment");
    }
    else if(neu_percent>pos_percent && neu_percent>neg_percent)
    {
        printf("\nThe given text has a Neutral Sentiment");
    }

    return 0;
}