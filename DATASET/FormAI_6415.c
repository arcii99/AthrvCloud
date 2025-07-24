//FormAI DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing variables
    int stock_prices[5];
    float total_gain_loss = 0;

    // Generating random stock prices
    srand(time(NULL));
    for(int i = 0; i < 5; i++) {
        stock_prices[i] = rand() % 100 + 1;
    }

    // Printing the stock prices for the day
    printf("Today's stock prices are: ");
    for(int i = 0; i < 5; i++) {
        printf("$%d ", stock_prices[i]);
    }

    // Calculating the total gain or loss for each stock
    for(int i = 0; i < 5; i++) {
        float percent_change = rand() % 50 - 25;
        float gain_loss = stock_prices[i] * percent_change / 100;
        total_gain_loss += gain_loss;
    }

    // Printing the total gain or loss for the day
    if(total_gain_loss > 0) {
        printf("\nCongratulations! You have gained $%.2f today!\n", total_gain_loss);
    } else if(total_gain_loss < 0) {
        printf("\nOops! You have lost $%.2f today.\n", -total_gain_loss);
    } else {
        printf("\nNo gain or loss today.\n");
    }

    return 0;
}