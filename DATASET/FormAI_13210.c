//FormAI DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 10
#define START_PRICE 100.0
#define DELTA_PRICE 10.0
#define BUY_THRESHOLD 90.0
#define SELL_THRESHOLD 110.0

int main()
{
    srand(time(NULL)); // initialize random seed
    
    double stocks[MAX_STOCKS]; // array to hold stock prices
    int i;
    char choice;

    // init stocks with random prices between 100.0 and 110.0
    for (i = 0; i < MAX_STOCKS; i++)
    {
        stocks[i] = START_PRICE + DELTA_PRICE * (double)(rand() % 11);
    }

    do
    {
        printf("\nCurrent Stock Prices:\n");
        printf("--------------------\n");
        // print current stock prices
        for (i = 0; i < MAX_STOCKS; i++)
        {
            printf("Stock %d: %.2f\n", i+1, stocks[i]);
        }

        printf("\nWhat would you like to do?\n");
        printf("a. Buy Stocks\n");
        printf("b. Sell Stocks\n");
        printf("c. Do Nothing\n");

        scanf(" %c", &choice);

        switch (choice)
        {
            case 'a': // buy stocks
                printf("\nWhich stock would you like to buy? (enter index 1-%d)\n", MAX_STOCKS);
                scanf("%d", &i);
                if (i > 0 && i <= MAX_STOCKS)
                {
                    if (stocks[i-1] <= BUY_THRESHOLD)
                    {
                        printf("You bought a stock at %.2f!\n", stocks[i-1]);
                    }
                    else
                    {
                        printf("Sorry, the stock price is too high to buy at the moment.\n");
                    }
                }
                else
                {
                    printf("Invalid index.\n");
                }
                break;

            case 'b': // sell stocks
                printf("\nWhich stock would you like to sell? (enter index 1-%d)\n", MAX_STOCKS);
                scanf("%d", &i);
                if (i > 0 && i <= MAX_STOCKS)
                {
                    if (stocks[i-1] >= SELL_THRESHOLD)
                    {
                        printf("You sold a stock at %.2f!\n", stocks[i-1]);
                        stocks[i-1] -= DELTA_PRICE; // decrease stock price by 10
                    }
                    else
                    {
                        printf("Sorry, the stock price is too low to sell at the moment.\n");
                    }
                }
                else
                {
                    printf("Invalid index.\n");
                }
                break;

            case 'c': // do nothing
                printf("You decided to do nothing. Good call!\n");
                break;

            default: // invalid input
                printf("Invalid input.\n");
                break;
        }

        // randomly increase or decrease a stock price
        i = rand() % MAX_STOCKS;
        if (rand() % 2 == 0)
        {
            printf("\nStock %d increased by 10 points!\n", i+1);
            stocks[i] += DELTA_PRICE;
        }
        else
        {
            printf("\nStock %d decreased by 10 points!\n", i+1);
            stocks[i] -= DELTA_PRICE;
        }

    } while (choice != 'c');

    return 0;
}