//FormAI DATASET v1.0 Category: Stock market tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed for random number generator
    int stockPrice = 100; // starting stock price
    int numOfDays = 0; // initialize the number of days to 0
    int fluctuation = 0; // initialize the daily fluctuation to 0
    int maxFluctuation = 10; // the max fluctuation in a day
    
    printf("Welcome to the most unreliable stock market tracker! \n");
    printf("Today's stock price is $%d \n", stockPrice);
    
    while(numOfDays < 30) // track for 30 days
    {
        fluctuation = rand() % (maxFluctuation*2) - maxFluctuation; // calculate daily fluctuation
        stockPrice += fluctuation; // calculate stock price
        if(stockPrice < 0) // stock price can't be negative
        {
            stockPrice = 0;
        }
        
        printf("Day %d: The stock price is $%d \n", numOfDays+1, stockPrice);
        if(fluctuation < 0) // change in the stock price
        {
            printf("Uh oh! The market is crashing! \n");
        }
        else if (fluctuation > 0)
        {
            printf("Congratulations! You're rich! \n");
        }
        else
        {
            printf("Nothing exciting happened today. \n");
        }
        printf("\n");
        numOfDays++; // count the number of days
    }
    
    printf("Thanks for using our unreliable stock market tracker! \n");
    printf("Remember: our predictions are always wrong, so invest at your own risk! \n");
    
    return 0;
}