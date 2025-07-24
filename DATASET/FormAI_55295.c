//FormAI DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int stock_price = 1000;
    printf("Starting stock price: $%d\n", stock_price);

    int i;
    for (i = 0; i < 50; i++)
    {
        int change = rand() % 100 - 50;

        if (change >= 0)
        {
            stock_price += change;
            printf("Stock price increased by $%d to $%d\n", change, stock_price);
        }
        else
        {
            stock_price += change;
            printf("Stock price decreased by $%d to $%d\n", abs(change), stock_price);
        }

        if (stock_price <= 0)
        {
            printf("Stock price has reached zero, market crashed!");
            return 0;
        }
    }

    printf("Final stock price: $%d\n", stock_price);
    return 0;
}