//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to calculate the sentiment score of the given text
int sentiment_score(char text[])
{
    int score = 0;
    char word[50];

    //List of positive and negative words
    char positive_words[10][20] = {"happy", "fun", "exciting", "love", "good", "great", "fantastic", "amazing", "joyful", "excellent"};
    char negative_words[10][20] = {"sad", "angry", "hate", "bad", "worst", "terrible", "frustrating", "disappointing", "annoying", "stressful"};

    //Tokenize the text based on spaces
    char *token = strtok(text, " ");

    while(token != NULL)
    {
        //Convert token to lowercase for comparison purposes
        for(int i = 0; i < strlen(token); i++)
        {
            word[i] = tolower(token[i]);
        }
        word[strlen(token)] = '\0';
        
        //Compare the word with the lists of positive and negative words and adjust sentiment score accordingly
        for(int i = 0; i < 10; i++)
        {
            if(strcmp(word, positive_words[i]) == 0)
            {
                score++;
                break;
            }
            else if(strcmp(word, negative_words[i]) == 0)
            {
                score--;
                break;
            }
        }

        //Get next token
        token = strtok(NULL, " ");
    }

    return score;
}

int main()
{
    char text[500];

    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Please enter the text you would like to analyze:\n");
    fgets(text, 500, stdin);

    //Remove new line character from input
    text[strcspn(text, "\n")] = 0;

    //Calculate sentiment score and display result
    int score = sentiment_score(text);
    if(score > 0)
    {
        printf("The sentiment score of the text is %d, indicating a positive sentiment.\n", score);
    }
    else if(score < 0)
    {
        printf("The sentiment score of the text is %d, indicating a negative sentiment.\n", score);
    }
    else
    {
        printf("The sentiment score of the text is %d, indicating a neutral sentiment.\n", score);
    }

    return 0;
}