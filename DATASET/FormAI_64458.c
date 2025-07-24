//FormAI DATASET v1.0 Category: Stock market tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 5
#define STOCK_NAME_LENGTH 15

// Struct for a single stock
typedef struct Stock {
    char name[STOCK_NAME_LENGTH];
    float price;
    float change;
} Stock;

// Function to print a single stock
void print_stock(Stock stock) {
    printf("%15s%10.2f%10.2f%%\n", stock.name, stock.price, stock.change);
}

int main() {
    // Create an array of stocks
    Stock stocks[MAX_STOCKS] = {
        {"AAPL", 130.21, 0.69},
        {"GOOG", 2558.19, 1.12},
        {"AMZN", 3478.05, -0.48},
        {"TSLA", 701.98, 2.88},
        {"NFLX", 522.41, -1.75}
    };

    // Print table headers
    printf("%15s%10s%10s\n", "Stock", "Price", "Change");

    // Loop through all stocks and print them
    for (int i = 0; i < MAX_STOCKS; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}