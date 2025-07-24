//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdio.h>
#include <string.h>

int countWords(char* sentence);
int positiveWords(char* sentence);
int negativeWords(char* sentence);
float calculateSentiment(int positiveCount, int negativeCount, int totalWords);

//main function
int main()
{
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin); //using fgets to read input string
    sentence[strcspn(sentence, "\n")] = 0; //removing newline character from the input
    
    int wordCount = countWords(sentence);
    int positiveCount = positiveWords(sentence);
    int negativeCount = negativeWords(sentence);
    float sentimentScore = calculateSentiment(positiveCount, negativeCount, wordCount);
    
    printf("Sentiment Analysis Result: \n\n");
    printf("Total words in the sentence: %d\n", wordCount);
    printf("Positive words in the sentence: %d\n", positiveCount);
    printf("Negative words in the sentence: %d\n", negativeCount);
    printf("Sentiment Score: %.2f\n", sentimentScore);
    
    return 0;
}

//function to count the total number of words in a sentence
int countWords(char* sentence)
{
    int count = 0;
    char* token = strtok(sentence, " ");
    while(token != NULL)
    {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

//function to count the number of positive words in a sentence
int positiveWords(char* sentence)
{
    int count = 0;
    char* positiveWords[10] = {"happy", "good", "love", "great", "excellent", "awesome", "best", "wonderful", "fantastic", "amazing"};
    char* token = strtok(sentence, " ");
    while(token != NULL)
    {
        for(int i=0; i<10; i++)
        {
            if(strcmp(token, positiveWords[i]) == 0)
            {
                count++;
            }
        }
        token = strtok(NULL, " ");
    }
    return count;
}

//function to count the number of negative words in a sentence
int negativeWords(char* sentence)
{
    int count = 0;
    char* negativeWords[10] = {"sad", "bad", "hate", "terrible", "awful", "worst", "horrible", "disappointing", "pathetic", "disgusting"};
    char* token = strtok(sentence, " ");
    while(token != NULL)
    {
        for(int i=0; i<10; i++)
        {
            if(strcmp(token, negativeWords[i]) == 0)
            {
                count++;
            }
        }
        token = strtok(NULL, " ");
    }
    return count;
}

//function to calculate the sentiment score of a sentence
float calculateSentiment(int positiveCount, int negativeCount, int totalWords)
{
    float sentimentScore;
    if(positiveCount > negativeCount)
    {
        sentimentScore = (float)positiveCount/totalWords;
    }
    else if(negativeCount > positiveCount)
    {
        sentimentScore = -1*(float)negativeCount/totalWords;
    }
    else
    {
        sentimentScore = 0;
    }
    return sentimentScore;
}