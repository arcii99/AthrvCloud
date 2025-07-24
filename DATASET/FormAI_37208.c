//FormAI DATASET v1.0 Category: Stock market tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10

typedef struct {
    char symbol[10];
    double price;
    double change;
    double percent_change;
} Stock;

void printStock(Stock stock) {
    printf("%-10s %-10.2f %-10.2f %-10.2f%%\n", stock.symbol, stock.price, stock.change, stock.percent_change);
}

void printStockList(Stock stocks[], int numStocks) {
    printf("%-10s %-10s %-10s %-10s\n", "Symbol", "Price", "Change", "% Change");
    for (int i = 0; i < numStocks; i++) {
        printStock(stocks[i]);
    }
}

int main() {
    Stock stocks[MAX_STOCKS] = {
        {"AAPL", 143.16, -1.09, -0.76},
        {"GOOG", 2215.73, 12.75, 0.58},
        {"TSLA", 649.38, -0.62, -0.10},
        {"MSFT", 286.54, 0.48, 0.17}
    };
    int numStocks = 4;

    printStockList(stocks, numStocks);

    return 0;
}