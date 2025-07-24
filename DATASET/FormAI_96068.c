//FormAI DATASET v1.0 Category: Stock market tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STOCK_NUM 5  // number of stocks to track

typedef struct {
    char symbol[6];
    double price;
    double change;
    double percent_change;
    char trend[4];
} Stock;

void update_prices(Stock *stocks) {
    // simulate price changes using random numbers
    srand(time(NULL));
    for (int i = 0; i < STOCK_NUM; i++) {
        double change = (double)(rand() % 101 - 50) / 100;
        stocks[i].price += change;
        stocks[i].change = change;
        stocks[i].percent_change = change / stocks[i].price * 100;
        if (change > 0) {
            strcpy(stocks[i].trend, "up");
        } else if (change < 0) {
            strcpy(stocks[i].trend, "down");
        } else {
            strcpy(stocks[i].trend, "stable");
        }
    }
}

void print_stock(Stock stock) {
    printf("%-6s $%6.2f %s $%6.2f (%6.2f%%)\n", 
            stock.symbol, stock.price, stock.trend, 
            stock.change, stock.percent_change);
}

int main() {
    // initialize stocks
    Stock stocks[STOCK_NUM];
    strcpy(stocks[0].symbol, "AAPL");
    strcpy(stocks[1].symbol, "GOOGL");
    strcpy(stocks[2].symbol, "AMZN");
    strcpy(stocks[3].symbol, "FB");
    strcpy(stocks[4].symbol, "TSLA");

    // initialize prices
    stocks[0].price = 120.14;
    stocks[1].price = 1749.48;
    stocks[2].price = 3143.87;
    stocks[3].price = 266.63;
    stocks[4].price = 306.21;

    // main loop
    while (1) {
        printf("====== Stock Prices ======\n");
        printf("%-6s %-9s %-10s %s\n", "Symbol", "Price", "Trend", "Change");
        update_prices(stocks);
        for (int i = 0; i < STOCK_NUM; i++) {
            print_stock(stocks[i]);
        }
        printf("\nPress Enter to update prices, or Ctrl+C to quit.\n");
        getchar();
    }

    return 0;
}