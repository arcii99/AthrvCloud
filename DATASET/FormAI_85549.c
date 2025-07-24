//FormAI DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STOCKS 5

int main() {
    int stock_prices[NUM_STOCKS] = {10, 15, 20, 25, 30};
    int total_gains = 0;
    srand(time(NULL));
    
    printf("Welcome to the Stock Market Tracker! Here are today's prices:\n");
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("Stock %d: $%d\n", i+1, stock_prices[i]);
    }

    for (int day = 1; day <= 5; day++) {
        printf("\n-----Day %d-----\n", day);
        for (int i = 0; i < NUM_STOCKS; i++) {
            int change = rand() % 6 - 2; // random change between -2 and 3
            int new_price = stock_prices[i] + change;

            if (new_price < 0) {
                new_price = 0; // stock price can't be negative
            }

            int gain = new_price - stock_prices[i];
            total_gains += gain;
            stock_prices[i] = new_price;
            printf("Stock %d: $%d (%s%d)\n", i+1, new_price, (gain >= 0) ? "+" : "", gain);
        }
    }

    printf("\nTotal gains after 5 days: $%d\n", total_gains);
    return 0;
}