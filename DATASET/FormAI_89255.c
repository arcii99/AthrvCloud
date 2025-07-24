//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 5

typedef struct stock {
    char ticker[6];
    float price;
    int volume;
    float change;
} Stock;

typedef struct stocks {
    Stock stockList[MAX_STOCKS];
    int numStocks;
} Stocks;

Stocks createStocks(void);
void updateStocksPrice(Stocks *stocks);
void updateStocksVolume(Stocks *stocks);
void displayStocks(Stocks stocks);

int main(void) {
    Stocks stocks = createStocks();

    while (1) {
        printf("Update stocks? (y/n)\n");
        char input;
        scanf(" %c", &input);
        if (input == 'y') {
            updateStocksPrice(&stocks);
            updateStocksVolume(&stocks);
            displayStocks(stocks);
        } else if (input == 'n') {
            break;
        }
    }

    return 0;
}

Stocks createStocks(void) {
    Stocks stocks;
    strcpy(stocks.stockList[0].ticker, "AAPL");
    stocks.stockList[0].price = 136.90;
    stocks.stockList[0].volume = 19840805;
    stocks.stockList[0].change = 1.26;

    strcpy(stocks.stockList[1].ticker, "AMZN");
    stocks.stockList[1].price = 3117.02;
    stocks.stockList[1].volume = 2534263;
    stocks.stockList[1].change = -0.99;

    strcpy(stocks.stockList[2].ticker, "GOOGL");
    stocks.stockList[2].price = 2062.52;
    stocks.stockList[2].volume = 884698;
    stocks.stockList[2].change = -2.98;

    strcpy(stocks.stockList[3].ticker, "MSFT");
    stocks.stockList[3].price = 230.48;
    stocks.stockList[3].volume = 21293001;
    stocks.stockList[3].change = -0.27;

    strcpy(stocks.stockList[4].ticker, "TSLA");
    stocks.stockList[4].price = 661.75;
    stocks.stockList[4].volume = 20200041;
    stocks.stockList[4].change = 0.97;

    stocks.numStocks = MAX_STOCKS;

    return stocks;
}

void updateStocksPrice(Stocks *stocks) {
    for (int i = 0; i < stocks->numStocks; i++) {
        stocks->stockList[i].price += (float) (rand() % 101 - 50) / 100.0;
    }
}

void updateStocksVolume(Stocks *stocks) {
    for (int i = 0; i < stocks->numStocks; i++) {
        stocks->stockList[i].volume += rand() % 50001 - 25000;
    }
}

void displayStocks(Stocks stocks) {
    printf("\tTicker\tPrice\tVolume\tChange\n");
    for (int i = 0; i < stocks.numStocks; i++) {
        printf("%d.\t%s\t%.2f\t%d\t%.2f\n", i+1, stocks.stockList[i].ticker,
            stocks.stockList[i].price, stocks.stockList[i].volume,
            stocks.stockList[i].change);
    }
    printf("\n");
}