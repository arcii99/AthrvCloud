//FormAI DATASET v1.0 Category: Stock market tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STOCKS 10

int main() {
    int stock_prices[STOCKS] = {5, 7, 3, 8, 6, 11, 2, 16, 4, 9};
    int total_value_of_portfolios = 0, total_value_of_stocks = 0;
    int i, j;

    srand(time(NULL));

    printf("Welcome to the hilarious stock market tracker!\n\n");

    for (i = 0; i < STOCKS; i++) {
        printf("Stock %d is currently valued at $%d per share.\n", i+1, stock_prices[i]);
    }
    printf("\n");

    for (i = 1; i <= 5; i++) {
        printf("Generating random changes...\n\n");
        for (j = 0; j < STOCKS; j++) {
            int change = (rand() % 6) - 3;
            stock_prices[j] += change;
            if (stock_prices[j] < 0) {
                stock_prices[j] = 0;
            }
        }

        printf("Here are the new stock prices after round %d:\n", i);
        for (j = 0; j < STOCKS; j++) {
            printf("Stock %d is now valued at $%d per share.\n", j+1, stock_prices[j]);
            total_value_of_stocks += stock_prices[j];
        }
        printf("Total value of all stocks after round %d: $%d\n\n", i, total_value_of_stocks);

        total_value_of_portfolios += total_value_of_stocks;
        total_value_of_stocks = 0;
        printf("--------------------------------------------------\n\n");
    }

    printf("\nCongratulations! You made it through the day!\n");
    printf("Total value of your portfolio over 5 rounds: $%d\n", total_value_of_portfolios);

    return 0;
}