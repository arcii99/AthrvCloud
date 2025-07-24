//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: relaxed
#include<stdio.h>
#include<string.h>

int main()
{
    char sentence[100];
    int i, positive=0, negative=0;
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    int len = strlen(sentence);
    
    for(i=0; i<len; i++)
    {
        if(sentence[i] == ' ')
            continue;
        if(sentence[i] == 'g' || sentence[i] == 'G' || sentence[i] == 'n' || sentence[i] == 'N')
        {
            if(sentence[i+1] == 'o' || sentence[i+1] == 'O')
            {
                if(sentence[i+2] == 'o' || sentence[i+2] == 'O' || sentence[i+2] == 'd' || sentence[i+2] == 'D')
                {
                    positive++;
                }
                else if(sentence[i+2] == 't' || sentence[i+2] == 'T')
                {
                    negative++;
                }
            }
        }
    }
    
    if(positive > negative)
        printf("\nSentiment analysis tool says that the sentence entered is POSITIVE.");
        
    else if(negative > positive)
        printf("\nSentiment analysis tool says that the sentence entered is NEGATIVE.");
    
    else
        printf("\nSentiment analysis tool says that the sentence entered is NEUTRAL.");
        
    return 0;
}