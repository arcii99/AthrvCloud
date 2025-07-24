//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int stockPrice = 100;
    int randomNumber;

    printf("The game is afoot! We shall track the fluctuation of a stock price.\n");

    while(stockPrice > 0)
    {
        randomNumber = rand() % 10 + (-5);
        stockPrice += randomNumber;

        printf("The stock price currently stands at %d.\n", stockPrice);

        if (stockPrice < 50)
        {
            printf("Elementary, my dear Watson. The stock has taken a nosedive. Sell all your shares!\n");
            break;
        }
        else if (stockPrice > 150)
        {
            printf("It would appear that the stock is doing quite well! Purchase more shares, my dear Watson.\n");
        }
    }

    printf("The game is afoot no more!\n");

    return 0;
}