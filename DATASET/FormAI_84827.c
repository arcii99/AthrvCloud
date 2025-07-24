//FormAI DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME 20

typedef struct {
    char name[MAX_NAME];
    double price;
} Stock;

int numStocks = 0;
Stock stocks[MAX_STOCKS];

bool addStock(char name[], double price) {
    if (numStocks >= MAX_STOCKS) {
        return false;
    }
    strcpy(stocks[numStocks].name, name);
    stocks[numStocks].price = price;
    numStocks++;
    return true;
}

void printStocks() {
    printf("\n%-10s %-10s\n\n", "Name", "Price");
    for (int i = 0; i < numStocks; i++) {
        printf("%-10s %-10.2f\n", stocks[i].name, stocks[i].price);
    }
}

int main() {
    addStock("AAPL", 127.12);
    addStock("GOOGL", 2755.32);
    addStock("FB", 326.44);
    addStock("TSLA", 623.31);

    printf("Welcome to the Stock Market Tracker!\n\n");
    printf("Current Stocks:\n");
    printStocks();

    return 0;
}