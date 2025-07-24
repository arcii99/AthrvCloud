//FormAI DATASET v1.0 Category: Stock market tracker ; Style: creative
#include <stdio.h>

int main() {

    int stock_price[5] = {10, 20, 15, 25, 30}; // initialize some sample stock prices
    int total_stocks = 5;
    int i;
    float average_price = 0;

    printf("Welcome to the C Stock Market Tracker!\n\n");

    // Print out the stock prices and calculate the average
    for (i = 0; i < total_stocks; i++) {
        printf("Stock %d price: %d\n", i+1, stock_price[i]);
        average_price += stock_price[i];
    }

    average_price = average_price / total_stocks;
    printf("\nAverage stock price: %.2f\n\n", average_price);

    // Check if any stocks are currently under the average price
    for (i = 0; i < total_stocks; i++) {
        if (stock_price[i] < average_price) {
            printf("Stock %d is currently under the average price!\n", i+1);
        }
    }

    return 0;
}