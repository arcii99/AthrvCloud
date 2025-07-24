//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Cryptic
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];
    int positive = 0, negative = 0;

    printf("Enter a sentence to analyze: ");
    scanf("%[^\n]", sentence); // read input until newline is encountered

    for(int i = 0; i < strlen(sentence); i++)
    {
        if(sentence[i] == 'good' || sentence[i] == 'great' || sentence[i] == 'excellent')
            positive++;
        else if(sentence[i] == 'bad' || sentence[i] == 'poor' || sentence[i] == 'terrible')
            negative++;
    }

    if(positive > negative)
        printf("This sentence has a positive sentiment.");
    else if(positive < negative)
        printf("This sentence has a negative sentiment.");
    else
        printf("This sentence has a neutral sentiment.");

    return 0;
}