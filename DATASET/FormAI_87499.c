//FormAI DATASET v1.0 Category: Stock market tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for holding stock market data
typedef struct {
    char *symbol;
    double price;
} stock;

// Define the stock market array (can hold up to 5 stocks)
stock market[5];

// Define a function to print all the stocks in the market
void displayMarket() {
    int i;
    printf("Stock Market:\n");
    for(i = 0; i < 5; i++) {
        if(market[i].symbol != NULL) {
            printf("%s: $%.2f\n", market[i].symbol, market[i].price);
        }
    }
}

// Define a function to add a stock to the market
void addStock(char *symbol, double price) {
    int i;
    for(i = 0; i < 5; i++) {
        if(market[i].symbol == NULL) {
            market[i].symbol = symbol;
            market[i].price = price;
            printf("%s has been added to the stock market at $%.2f.\n", symbol, price);
            return;
        }
    }
    printf("Sorry, the stock market is full.\n");
}

// Define a function to remove a stock from the market
void removeStock(char *symbol) {
    int i;
    for(i = 0; i < 5; i++) {
        if(market[i].symbol != NULL && strcmp(market[i].symbol, symbol) == 0) {
            printf("%s has been removed from the stock market.\n", symbol);
            market[i].symbol = NULL;
            market[i].price = 0.0;
            return;
        }
    }
    printf("Sorry, %s is not in the stock market.\n", symbol);
}

// Define the main function
int main() {
    // Initialize the market with 3 stocks
    market[0].symbol = "AAPL";
    market[0].price = 150.25;
    market[1].symbol = "GOOG";
    market[1].price = 1005.50;
    market[2].symbol = "AMZN";
    market[2].price = 1762.96;
    // Display the market
    displayMarket();
    // Add a new stock
    addStock("FB", 178.19);
    // Remove a stock
    removeStock("AAPL");
    // Display the market again
    displayMarket();
    // Exit the program
    return 0;
}