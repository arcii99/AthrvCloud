//FormAI DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stock {
    char symbol[20];
    double price;
    double change;
} Stock;

int numStocks = 3;

void printStocks(Stock stocks[]) {
    printf("Symbol\tPrice\tChange\n");
    printf("========================\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s\t$%.2lf\t%.2lf%%\n", stocks[i].symbol, stocks[i].price, stocks[i].change);
    }
}

int findStock(Stock stocks[], char symbol[20]) {
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            return i;
        }
    }
    return -1;
}

void updatePrice(Stock stocks[], char symbol[20], double price) {
    int index = findStock(stocks, symbol);
    if (index == -1) {
        printf("Stock not found\n");
    }
    else {
        stocks[index].change = ((price - stocks[index].price) / stocks[index].price) * 100;
        stocks[index].price = price;
        printf("%s updated\n", symbol);
    }
}

int main() {
    Stock stocks[numStocks];
    
    strcpy(stocks[0].symbol, "AAPL");
    stocks[0].price = 132.05;
    stocks[0].change = 1.23;
    
    strcpy(stocks[1].symbol, "GOOG");
    stocks[1].price = 2145.14;
    stocks[1].change = -0.76;
    
    strcpy(stocks[2].symbol, "TSLA");
    stocks[2].price = 795.44;
    stocks[2].change = 2.34;
    
    printStocks(stocks);
    
    updatePrice(stocks, "AAPL", 133.25);
    updatePrice(stocks, "GOOG", 2165.81);
    updatePrice(stocks, "TSLA", 820.12);
    
    printStocks(stocks);
    
    return 0;
}