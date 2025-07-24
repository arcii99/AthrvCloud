//FormAI DATASET v1.0 Category: Stock market tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int stockPrice = 100;
    int days = 30;
    int volatility = 5;

    srand(time(NULL)); //seeding the random number generator

    printf("Day\tStock Price\n");

    for(int i = 1; i <= days; i++)
    {
        int fluctuation = (rand() % volatility + 1); //generating a random number between 1 and volatility

        if(rand() % 2 == 0) //50% chance of fluctuation being positive or negative
            stockPrice += fluctuation;
        else
            stockPrice -= fluctuation;

        printf("%d\t%d\n", i, stockPrice); //printing the day and the stock price
    }

    return 0;
}