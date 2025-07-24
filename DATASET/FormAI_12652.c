//FormAI DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int stockPrices[10] = {50, 55, 60, 65, 70, 75, 80, 85, 90, 95};
    int stockPricesYesterday[10] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
    int numDays = 1;

    printf("Welcome to the Stock Market Tracker!\n\n");

    while (1)
    {
        int stockIdx = rand() % 10;
        int change = rand() % 6;

        if (change >= 3)
        {
            stockPrices[stockIdx]++;
        }
        else
        {
            stockPrices[stockIdx]--;
        }

        printf("Day %d\n", numDays);
        printf("************\n\n");

        for (int i = 0; i < 10; i++)
        {
            printf("Stock %d: %d (", i+1, stockPrices[i]);

            if (stockPrices[i] > stockPricesYesterday[i])
            {
                printf("+%d)\n", stockPrices[i] - stockPricesYesterday[i]);
            }
            else if (stockPrices[i] < stockPricesYesterday[i])
            {
                printf("-%d)\n", stockPricesYesterday[i] - stockPrices[i]);
            }
            else
            {
                printf("0)\n");
            }

            stockPricesYesterday[i] = stockPrices[i];
        }

        numDays++;

        if (numDays > 10)
        {
            printf("\nThank you for tracking the stock market!\n");

            break;
        }

        printf("\n\n");

        // Pause the program for 1 second
        for (int i = 0; i < 100000000; i++);
    }

    return 0;
}