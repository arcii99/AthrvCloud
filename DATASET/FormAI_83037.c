//FormAI DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float stockPrice = 100.0;
    float stockIncreaseProbability = 0.6;
    float stockIncreaseAmount = 10.0;
    float stockDecreaseProbability = 0.4;
    float stockDecreaseAmount = 5.0;
    float stockPriceChange;
    float stockPricePercentChange;
    float stockTotalChanges = 0.0;
    float stockAverageChange = 0.0;
    float stockMaxPrice = 100.0;
    float stockMinPrice = 100.0;
    float stockHighPriceCount = 0.0;
    float stockLowPriceCount = 0.0;
    float randNum;

    srand(time(0));

    for(int i = 0; i < 50; i++)
    {
        randNum = (float)rand() / RAND_MAX; //random number between 0 and 1
        
        if(randNum < stockIncreaseProbability) //stock price increase
        {
            stockPriceChange = stockIncreaseAmount;
            stockPrice += stockPriceChange;
            stockPricePercentChange = (stockPriceChange / stockPrice) * 100;
            printf("Day %d: Stock price increased by $%.2f (%.2f%%)\n", i+1, stockPriceChange, stockPricePercentChange);
            stockTotalChanges += stockPriceChange;
            stockHighPriceCount++;
            if(stockPrice > stockMaxPrice)
            {
                stockMaxPrice = stockPrice;
            }
        }
        else //stock price decrease
        {
            stockPriceChange = -stockDecreaseAmount;
            stockPrice += stockPriceChange;
            stockPricePercentChange = (stockPriceChange / stockPrice) * 100;
            printf("Day %d: Stock price decreased by $%.2f (%.2f%%)\n", i+1, -stockPriceChange, stockPricePercentChange);
            stockTotalChanges += -stockPriceChange;
            stockLowPriceCount++;
            if(stockPrice < stockMinPrice)
            {
                stockMinPrice = stockPrice;
            }
        }
    }

    printf("\nAverage daily price change: $%.2f\n", stockTotalChanges / 50);
    printf("Highest stock price: $%.2f\n", stockMaxPrice);
    printf("Lowest stock price: $%.2f\n", stockMinPrice);
    printf("Number of days with high stock prices: %.0f\n", stockHighPriceCount);
    printf("Number of days with low stock prices: %.0f\n", stockLowPriceCount);

    return 0;
}