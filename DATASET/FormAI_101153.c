//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char answers[][100] = {"It is certain",
                           "It is decidedly so",
                           "Without a doubt",
                           "Yes – definitely",
                           "You may rely on it",
                           "As I see it, yes",
                           "Most likely",
                           "Outlook good",
                           "Yes",
                           "Signs point to yes",
                           "Reply hazy, try again",
                           "Ask again later",
                           "Better not tell you now",
                           "Cannot predict now",
                           "Concentrate and ask again",
                           "Don't count on it", 
                           "Outlook not so good", 
                           "My sources say no", 
                           "Very doubtful", 
                           "No way"};

    srand(time(NULL));      //Seed the random number generator

    printf("Welcome to the Automated Fortune Teller! Ask me a question:\n");

    char question[100];      //Buffer to store user's question
    scanf("%[^\n]%*c", question);   //Read user's input

    printf("\nThinking...\n\n");

    int index = rand() % 20;   //Generate a random index to choose an answer
    printf("%s\n", answers[index]);

    return 0;
}