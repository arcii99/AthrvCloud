//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: protected
#include <stdio.h>
#include <string.h>

//Function to calculate positivity of a sentence
float positivity(char *s)
{
    int i, numWords=0, posWords=0;
    char *words[100]; //maximum number of words in a sentence
    
    //Divide sentence into words
    char *token = strtok(s, " ");
    while(token != NULL)
    {
        words[numWords++] = token;
        token = strtok(NULL, " ");
    }
    
    //Count number of positive words
    char *positive[] = {"happy", "great", "fantastic", "excellent", "amazing", "love", "wonderful", "nice", "awesome"};
    for(i=0;i<numWords;i++)
    {
        for(int j=0;j<sizeof(positive)/sizeof(positive[0]);j++)
        {
            if(strcmp(words[i], positive[j])==0)
            {
                posWords++;
                break;
            }
        }
    }
    
    //Calculate positivity score and return
    return (float)posWords/numWords;
}

//Function to calculate negativity of a sentence
float negativity(char *s)
{
    int i, numWords=0, negWords=0;
    char *words[100]; //maximum number of words in a sentence
    
    //Divide sentence into words
    char *token = strtok(s, " ");
    while(token != NULL)
    {
        words[numWords++] = token;
        token = strtok(NULL, " ");
    }
    
    //Count number of negative words
    char *negative[] = {"sad", "hate", "bad", "terrible", "awful", "dislike", "worst", "unhappy", "angry"};
    for(i=0;i<numWords;i++)
    {
        for(int j=0;j<sizeof(negative)/sizeof(negative[0]);j++)
        {
            if(strcmp(words[i], negative[j])==0)
            {
                negWords++;
               	break;
            }
        }
    }
    
    //Calculate negativity score and return
    return (float)negWords/numWords;
}

int main()
{
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    
    float posScore = positivity(sentence);
    float negScore = negativity(sentence);
    
    printf("Positivity score: %f\n", posScore);
    printf("Negativity score: %f\n", negScore);
    
    if(posScore > negScore)
        printf("Overall, the sentence is positive.\n");
    else if(negScore > posScore)
        printf("Overall, the sentence is negative.\n");
    else
        printf("Overall, the sentence is neutral.\n");
    
    return 0;
}