//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
    char text[1000];
    int positive = 0, negative = 0, neutral = 0;

    printf("Please enter the text: ");
    scanf("%[^\n]%*c", text);

    // Loop through each character in the text
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == 'l')
        {
            positive++;
        }
        else if(text[i] == 'h')
        {
            negative++;
        }
        else
        {
            neutral++;
        }
    }

    // Determine the sentiment based on the number of positive, negative and neutral characters
    if(positive > negative && positive > neutral)
    {
        printf("You make my heart beat faster like a lover's drum\n");
    }
    else if(negative > positive && negative > neutral)
    {
        printf("Your love is like a rose with thorns\n");
    }
    else
    {
        printf("I cannot express my love for you in simple words\n");
    }

    return 0;
}