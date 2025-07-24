//FormAI DATASET v1.0 Category: Stock market tracker ; Style: recursive
#include <stdio.h>

void stockMarketTracker(char* stocks[], double prices[], int n) {
    if (n == 0) {
        return;
    } else {
        stockMarketTracker(stocks, prices, n-1);
        printf("%s: $%.2lf\n", stocks[n-1], prices[n-1]);
    }
}

int main(void) {
    char* stocks[] = {"AAPL", "AMZN", "GOOGL", "TSLA", "MSFT"};
    double prices[] = {124.97, 3125.00, 2132.74, 661.75, 260.74};

    int n = sizeof(stocks) / sizeof(stocks[0]);

    printf("Welcome to the stock market tracker!\n\n");
    printf("Today's stock prices:\n");

    stockMarketTracker(stocks, prices, n);

    return 0;
}