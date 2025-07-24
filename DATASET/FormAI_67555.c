//FormAI DATASET v1.0 Category: Stock market tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
} Stock;

Stock stocks[MAX_STOCKS];
int numStocks = 0;

bool addStock(char name[], char symbol[], double price) {
    if (numStocks >= MAX_STOCKS) {
        return false;
    }
    strcpy(stocks[numStocks].name, name);
    strcpy(stocks[numStocks].symbol, symbol);
    stocks[numStocks].price = price;
    numStocks++;
    return true;
}

void displayStocks() {
    printf("------------------------------------------\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s (%s): %.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
    printf("------------------------------------------\n");
}

void updateStock(char symbol[], double newPrice) {
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            stocks[i].price = newPrice;
            return;
        }
    }
}

int main() {
    addStock("Apple Inc.", "AAPL", 150.23);
    addStock("Microsoft Corporation", "MSFT", 238.84);
    addStock("Amazon.com, Inc.", "AMZN", 3265.45);
    addStock("Alphabet Inc. Class A", "GOOGL", 2091.51);
    addStock("Tesla, Inc.", "TSLA", 670.97);

    printf("Initial stock prices:\n");
    displayStocks();

    updateStock("AAPL", 152.36);
    updateStock("MSFT", 240.88);

    printf("Updated stock prices:\n");
    displayStocks();

    if (!addStock("Facebook, Inc.", "FB", 322.38)) {
        printf("Failed to add stock. Maximum number of stocks reached.\n");
    }

    return 0;
}