//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include<stdio.h>
#include<string.h>

int main()
{
    char input[1000]; //Declaring the input string array
    int positive=0,negative=0,neutral=0; //initializing to 0

    printf("Enter your sentence:\n");
    fgets(input,1000,stdin); //Reading input from user using fgets()

    //using strtok() to split the sentence into multiple words
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        int sum=0;

        //Add ASCII value of all characters in the token
        for (int i = 0; i < strlen(token); i++)
        {
            sum += token[i];
        }

        //check if sum is even/odd and increment count based on the result
        if(sum%2==0)
        {
            positive++;
        }
        else
        {
            negative++;
        }

        token = strtok(NULL, " ");
    }

    //calculate the neutral count
    neutral = strlen(input)-positive-negative-2;
    //subtracting 2 to account for the spaces between words

    //Displaying the sentiment analysis result
    printf("Sentiment Analysis of the provided text:\nPositive count: %d\nNegative count: %d\nNeutral count: %d", positive, negative, neutral);

    return 0;
}