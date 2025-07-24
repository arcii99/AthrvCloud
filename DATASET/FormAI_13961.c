//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[500];
    int happy = 0, sad = 0;

    printf("Welcome to the Happy Sentiment Analysis Tool!\n");
    printf("Please enter the sentence you would like to analyze:\n");
    fgets(sentence, sizeof(sentence), stdin);

    char *happy_words[] = {"happy", "joy", "pleasure", "great", "delight", "wonderful",
                           "fantastic", "amazing", "exciting", "excellent"};
    char *sad_words[] = {"sad", "unhappy", "depressed", "miserable", "terrible", "disappointed",
                         "worst", "sadness", "crying", "heartbroken"};

    for (int i = 0; i < strlen(sentence); i++) 
    {
        if (sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == '\n')
        {
            sentence[i] = '\0';

            for (int j = 0; j < 10; j++) 
            {
                if (strcmp(sentence, happy_words[j]) == 0) 
                {
                    happy++;
                }
                if (strcmp(sentence, sad_words[j]) == 0) 
                {
                    sad++;
                }
            }
        }
    }
    printf("\nResults\n");
    printf("The sentence contains %d happy words and %d sad words.\n\n", happy, sad);
    if (happy > sad) 
    {
        printf("This sentence has a happy sentiment! Yay! 😁\n");
    } 
    else if (happy < sad)
    {
        printf("This sentence has a sad sentiment. 😔\n");
    } 
    else
    {
        printf("This sentence is neutral. 😐\n");
    }

    return 0;
}