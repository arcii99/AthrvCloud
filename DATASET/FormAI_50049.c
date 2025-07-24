//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKER_LENGTH 5
#define MAX_TICKERS 100

typedef struct {
    char ticker[MAX_TICKER_LENGTH + 1];
    double price;
} stock;

int main() {
    stock portfolio[MAX_TICKERS];
    int portfolio_size = 0;

    // prompt user for input
    printf("Enter number of tickers to add to portfolio: ");
    scanf("%d", &portfolio_size);

    // validate portfolio size
    if (portfolio_size > MAX_TICKERS) {
        printf("Maximum number of tickers allowed is %d\n", MAX_TICKERS);
        exit(EXIT_FAILURE);
    }

    // read the portfolio data
    for (int i = 0; i < portfolio_size; i++) {
        printf("Enter the ticker symbol for stock %d (max %d characters): ", i+1, MAX_TICKER_LENGTH);
        scanf("%s", portfolio[i].ticker);

        printf("Enter the current price for stock %d: ", i+1);
        scanf("%lf", &portfolio[i].price);
    }

    // display stock portfolio
    printf("Your stock portfolio:\n");
    for (int i = 0; i < portfolio_size; i++) {
        printf("Ticker: %s, Price: %.2lf\n", portfolio[i].ticker, portfolio[i].price);
    }

    return 0;
}