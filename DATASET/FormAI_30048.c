//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    system("clear"); //For UNIX based systems

    printf("\nWelcome to the number guessing game!\n");

    //Initializing random number generator
    srand(time(NULL));
    
    //Generating random number between 1 and 100
    int number = rand() % 100 + 1;
    
    int guess, tries=0;
    
    do
    {
        printf("\nPlease enter your guess (between 1 and 100): ");
        scanf("%d",&guess);
        
        tries++;
        
        if(guess>number)
            printf("\nToo high, try again!");
        
        else if(guess<number)
            printf("\nToo low, try again!");
            
        else
            printf("\nCongratulations, you guessed the number %d in %d tries.\n",number,tries);
        
    }while(guess!=number);
    
    return 0;
}