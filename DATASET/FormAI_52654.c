//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: surrealist
#include<stdio.h>
#include<string.h>

int main()
{
    char sentence[1000];    //Holds user inputted sentence
    int positive = 0, negative = 0;     //Counts positive and negative words in sentence
    
    printf("Welcome to the Surrealist Sentiment Analysis Tool!\n");
    printf("Please enter a sentence to analyze its sentiment: ");
    
    fgets(sentence, 1000, stdin); //Gets user input
    
    char *positiveWords[] = {"dreams", "fantasies", "butterflies", "rainbows", "unicorns", "fairies", "glitter"}; //Array of positive words
    char *negativeWords[] = {"nightmares", "dystopias", "locusts", "thunderstorms", "vampires", "demons", "shadows"}; //Array of negative words
    
    char *token = strtok(sentence, " ");
    
    while(token != NULL)    //Iterates through all words in sentence
    {
        for(int i=0; i<7; i++)  //Checks if current word is positive or negative
        {
            if(strcmp(token, positiveWords[i]) == 0)
            {
                positive++;
                break;
            }
            else if(strcmp(token, negativeWords[i]) == 0)
            {
                negative++;
                break;
            }
        }
        
        token = strtok(NULL, " ");  //Gets next word in sentence
    }
    
    printf("\nThank you for using the Surrealist Sentiment Analysis Tool!\n");
    if(positive > negative)
        printf("Your sentence has a positive sentiment.\n");
    else if(negative > positive)
        printf("Your sentence has a negative sentiment.\n");
    else
        printf("Your sentence has a neutral sentiment.\n");
    
    return 0;
}