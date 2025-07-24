//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Alan Touring
#include<stdio.h>
#include<string.h>

//Defining the sentiment scores for different words
int posScore(char word[])
{
    if(strcmp(word,"happy")==0 || strcmp(word,"excited")==0 || strcmp(word,"joyful")==0)
        return 1;
    else if(strcmp(word,"love")==0 || strcmp(word,"amazing")==0)
        return 2;
    else
        return 0;
}

int negScore(char word[])
{
    if(strcmp(word,"sad")==0 || strcmp(word,"unhappy")==0 || strcmp(word,"depressed")==0)
        return -1;
    else if(strcmp(word,"hate")==0 || strcmp(word,"terrible")==0)
        return -2;
    else
        return 0;
}

int main()
{
    char input[1000];
    int posCount=0, negCount=0, score=0;

    printf("Welcome to Sentiment Analyzer\n");
    printf("Enter your sentence: ");

    //Reading the input sentence and tokenizing it for individual word analysis
    fgets(input,1000,stdin);
    char *token = strtok(input, " ");

    while (token != NULL)
    {
        //Calculating positive and negative scores for each word in the sentence
        int posRes = posScore(token);
        int negRes = negScore(token);

        //Checking if any positive or negative score found
        if(posRes!=0)
            posCount++;
        if(negRes!=0)
            negCount++;

        //Calculating total score for the sentence
        score += posRes + negRes;

        token = strtok(NULL, " ");
    }

    //Checking the sentiment of the input sentence
    if(score>0)
        printf("The input sentence is a Positive Sentiment\n");
    else if(score<0)
        printf("The input sentence is a Negative Sentiment\n");
    else
        printf("The input sentence has a Neutral Sentiment\n");

    //Displaying the detailed sentiment analysis report
    printf("\nSentiment Analysis Report\n");
    printf("Positive Words Found: %d\n",posCount);
    printf("Negative Words Found: %d\n",negCount);
    printf("Total Sentiment Score: %d\n",score);

    return 0;
}