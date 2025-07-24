//FormAI DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int stock_prices[10];
    srand(time(0));
    
    //populating the stock prices
    for(int i=0;i<10;i++)
    {
        stock_prices[i] = rand()%100;
    }

    //displaying the stock prices
    printf("The stock prices for the day are: ");
    for(int i=0;i<10;i++)
    {
        printf("%d ", stock_prices[i]);
    }
    
    int max_profit = 0;
    int buy_day, sell_day;

    //calculating the maximum profit
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            int profit = stock_prices[j] - stock_prices[i];
            if(profit > max_profit)
            {
                max_profit = profit;
                buy_day = i+1;
                sell_day = j+1;
            }
        }
    }

    printf("\nThe best day to buy is day %d", buy_day);
    printf("\nThe best day to sell is day %d", sell_day);
    printf("\nThe maximum profit that can be made is %d\n", max_profit);

    if(max_profit == 0)
    {
        printf("\nLooks like it's not a good day for trading. Better luck next time!");
    }

    return 0;
}