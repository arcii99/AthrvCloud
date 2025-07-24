//FormAI DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>

int main() {
    int stock_prices[] = {50, 62, 88, 72, 95, 102, 65, 78};
    int n = sizeof(stock_prices) / sizeof(stock_prices[0]);
    int highest_price = 0;
    int lowest_price = stock_prices[0];

    printf("Darling, let me track the stock market for you today.\n");
    printf("I will be your eyes and ears and let you know the highs and lows of the stocks.\n");

    for (int i = 0; i < n; i++) {
        if (stock_prices[i] > highest_price) {
            highest_price = stock_prices[i];
        }
        if (stock_prices[i] < lowest_price) {
            lowest_price = stock_prices[i];
        }
    }

    printf("My love, the highest stock price for today is: %d\n", highest_price);
    printf("The lowest stock price for today is: %d\n", lowest_price);

    return 0;
}