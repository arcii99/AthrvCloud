//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int stock_price = 100;
    int max_stock_price = 500;
    int min_stock_price = 50;
    int stock_change = 0;
    int cybercash = 1000;
    int days = 0;

    srand(time(NULL)); // seed random number generator

    printf("Welcome to the Cyberpunk Stock Market Tracker!\n\n");

    // Loop for 30 days
    while (days < 30) {

        // Generate random stock price change
        stock_change = rand() % 201 - 100;

        // Add stock price change to current stock price
        stock_price += stock_change;

        // Make sure stock price is within limits
        if (stock_price > max_stock_price) {
            stock_price = max_stock_price;
        } else if (stock_price < min_stock_price) {
            stock_price = min_stock_price;
        }

        // Print current stock price and cybercash balance
        printf("Day %d: Stock price is %d Cyberdollars. You have %d Cyberdollars.\n", days+1, stock_price, cybercash);

        // Buy or Sell Stocks
        if (stock_change > 0) {
            // Stock price increased
            if (cybercash > stock_price) {
                // Buy stocks
                cybercash -= stock_price;
                printf("You bought 1 stock at %d Cyberdollars. You have %d Cyberdollars left.\n", stock_price, cybercash);
            } else {
                printf("You do not have enough Cyberdollars to buy stocks.\n");
            }
        } else if (stock_change < 0) {
            // Stock price decreased
            if (cybercash > 0) {
                // Sell stocks
                cybercash += stock_price;
                printf("You sold 1 stock at %d Cyberdollars. You have %d Cyberdollars now.\n", stock_price, cybercash);
            } else {
                printf("You do not have any stocks to sell.\n");
            }
        } else {
            // Stock price did not change
            printf("The stock price did not change today.\n");
        }

        // Increment day counter
        days++;
    }

    return 0;
}