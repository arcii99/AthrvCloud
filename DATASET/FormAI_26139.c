//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char sentence[1000];
    int pos_count = 0, neg_count = 0, neu_count = 0;

    printf("What light through yonder window breaks?\n");
    printf("Enter a sentence for sentiment analysis: ");
    fgets(sentence, 1000, stdin);

    //Converting every word to lowercase
    int length = strlen(sentence);
    for(int i=0; i<length; i++)
    {
        sentence[i] = tolower(sentence[i]);
    }

    //Parsing the sentence to identify positive, negative and neutral words
    char* token = strtok(sentence, " .,\n");

    while(token != NULL)
    {
        if(strcmp(token, "love") == 0 || strcmp(token, "adore") == 0 || strcmp(token, "happy") == 0 || strcmp(token, "pleasure") == 0)
        {
            pos_count++;
        }
        else if(strcmp(token, "hate") == 0 || strcmp(token, "disgust") == 0 || strcmp(token, "anger") == 0 || strcmp(token, "pain") == 0)
        {
            neg_count++;
        }
        else
        {
            neu_count++;
        }
        token = strtok(NULL, " .,\n");
    }

    //Printing the sentiment analysis result
    if(pos_count > neg_count && pos_count > neu_count)
    {
        printf("It is the East, and Juliet is the sun!\n");
        printf("Sentiment of the sentence is Positive\n");
    }
    else if(neg_count > pos_count && neg_count > neu_count)
    {
        printf("O, I am fortune's fool!\n");
        printf("Sentiment of the sentence is Negative\n");
    }
    else
    {
        printf("A plague o' both your houses!\n");
        printf("Sentiment of the sentence is Neutral\n");
    }
    return 0;
}