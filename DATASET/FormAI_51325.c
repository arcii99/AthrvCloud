//FormAI DATASET v1.0 Category: Stock market tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for a stock
struct Stock {
    char symbol[10];
    float price;
    float change;
};

// Function to display a stock's information
void displayStock(struct Stock stock) {
    printf("%-10s $%-10.2f %-10.2f%%\n", stock.symbol, stock.price, stock.change);
}

int main() {
    // Define an array of stocks
    struct Stock stocks[5] = {
        {"AAPL", 154.63, 0.72},
        {"MSFT", 282.51, 0.10},
        {"AMZN", 3467.42, -0.80},
        {"GOOGL", 2767.80, 0.20},
        {"FB", 358.99, -0.50}
    };

    // Display the header
    printf("%-10s %-15s %-10s\n", "Symbol", "Price", "Change");

    // Display each stock's information
    for (int i = 0; i < 5; i++) {
        displayStock(stocks[i]);
    }

    return 0;
}