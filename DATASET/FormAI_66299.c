//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Define an array of stock prices for the last 10 days
    float stock_prices[10] = { 112.4, 115.2, 116.5, 117.9, 119.3, 121.1, 123.6, 121.8, 125.5, 127.9 };

    // Define variables to calculate the average price, highest price, and lowest price
    float sum = 0, avg_price = 0, highest = 0, lowest = stock_prices[0];

    // Calculate the sum of all the prices
    for (int i = 0; i < 10; i++) {
        sum += stock_prices[i];
    }

    // Calculate the average price
    avg_price = sum / 10;

    // Calculate the highest and lowest prices
    for (int i = 0; i < 10; i++) {
        if (stock_prices[i] > highest) {
            highest = stock_prices[i];
        }

        if (stock_prices[i] < lowest) {
            lowest = stock_prices[i];
        }
    }

    // Generate a random number between 1 and 100
    srand(time(NULL));
    int random_num = (rand() % 100) + 1;

    // Print the stock market tracker information
    printf("Stock Market Tracker\n");
    printf("----------------------------\n");
    printf("Today's Random Number: %d\n", random_num);
    printf("Average Price: %.1f\n", avg_price);
    printf("Highest Price: %.1f\n", highest);
    printf("Lowest Price: %.1f\n", lowest);

    // Determine whether the stock prices have gone up or down
    if (stock_prices[9] > stock_prices[0]) {
        printf("The stock prices have gone up in the last 10 days.\n");
    } else {
        printf("The stock prices have gone down in the last 10 days.\n");
    }

    return 0;
}