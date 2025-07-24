//FormAI DATASET v1.0 Category: Stock market tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20

typedef struct stock {
    char name[MAX_NAME_LENGTH];
    float price;
    float change;
} Stock;

void printStock(Stock *s) {
    printf("%-10s %-10.2f %-10.2f\n", s->name, s->price, s->change);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;
    
    // Populate the list of stocks
    strcpy(stocks[numStocks].name, "AAPL");
    stocks[numStocks].price = 144.40;
    stocks[numStocks].change = 1.22;
    numStocks++;

    strcpy(stocks[numStocks].name, "GOOG");
    stocks[numStocks].price = 2260.46;
    stocks[numStocks].change = -2.34;
    numStocks++;
    
    strcpy(stocks[numStocks].name, "MSFT");
    stocks[numStocks].price = 265.15;
    stocks[numStocks].change = 0.57;
    numStocks++;

    printf("%-10s %-10s %-10s\n", "Name", "Price", "Change");
    printf("----------------------------------\n");

    for (int i = 0; i < numStocks; i++) {
        printStock(&stocks[i]);
    }

    return 0;
}