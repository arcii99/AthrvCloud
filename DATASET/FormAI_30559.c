//FormAI DATASET v1.0 Category: Stock market tracker ; Style: grateful
#include <stdio.h>

/* A Grateful C Stock Market Tracker */

int main()
{
    float aapl_price = 134.23; // AAPL price
    float msft_price = 252.46; // MSFT price

    printf("Welcome to the Grateful C Stock Market Tracker!\n");
    printf("Today's AAPL price: $%.2f\n", aapl_price);
    printf("Today's MSFT price: $%.2f\n", msft_price);

    // Updating prices
    aapl_price += 2.37;
    msft_price -= 1.14;

    printf("\nThanks to the Market, AAPL price increased by $%.2f\n", 2.37);
    printf("Thanks to the Market, MSFT price decreased by $%.2f\n\n", 1.14);

    printf("Updated AAPL price: $%.2f\n", aapl_price);
    printf("Updated MSFT price: $%.2f\n\n", msft_price);

    // Calculating price difference
    float price_diff = aapl_price - msft_price;

    if (price_diff > 0)
    {
        printf("AAPL stock is doing better than MSFT stock with a difference of $%.2f\n", price_diff);
    }
    else if (price_diff < 0)
    {
        printf("MSFT stock is doing better than AAPL stock with a difference of $%.2f\n", -price_diff);
    }
    else
    {
        printf("AAPL and MSFT stocks are doing equally well!\n");
    }

    return 0;
}