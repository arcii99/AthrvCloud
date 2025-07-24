//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

void analyzeSentiment(char* sentence)
{
    int positiveCount = 0;
    int negativeCount = 0;

    char* positiveWords[] = {"good", "great", "happy", "love", "awesome", "excellent"};
    char* negativeWords[] = {"bad", "terrible", "sad", "hate", "disappoint", "awful"};

    char* token = strtok(sentence, " "); // Break sentence into tokens

    while (token != NULL)
    {
        for (int i = 0; i < sizeof(positiveWords)/sizeof(positiveWords[0]); i++)
        {
            if (strcmp(token, positiveWords[i]) == 0) // Check if token is positive word
            {
                positiveCount++;
            }
        }

        for (int i = 0; i < sizeof(negativeWords)/sizeof(negativeWords[0]); i++)
        {
            if (strcmp(token, negativeWords[i]) == 0) // Check if token is negative word
            {
                negativeCount++;
            }
        }

        token = strtok(NULL, " ");
    }

    if (positiveCount > negativeCount)
    {
        printf("This sentence has a positive sentiment.\n");
    }
    else if (negativeCount > positiveCount)
    {
        printf("This sentence has a negative sentiment.\n");
    }
    else
    {
        printf("This sentence has a neutral sentiment.\n");
    }
}

int main()
{
    char sentence[100];
    printf("Please enter a sentence: ");
    fgets(sentence, 100, stdin); // Get input sentence from user

    analyzeSentiment(sentence);

    return 0;
}