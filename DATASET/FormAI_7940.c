//FormAI DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for stock data
struct StockData {
    char symbol[10];
    float price;
    float change;
};

int main() {
    // Declare and initialize an array of StockData structs
    struct StockData stocks[5] = {
        {"AAPL", 135.39, -0.32},
        {"GOOGL", 2447.44, 4.36},
        {"MSFT", 262.59, 2.15},
        {"AMZN", 3264.11, 5.78},
        {"FB", 316.24, 1.64}
    };
    
    // Print header
    printf("%-10s%-10s%-10s\n", "Symbol", "Price", "Change");
    
    // Print each stock's data
    for (int i = 0; i < 5; i++) {
        printf("%-10s%-10.2f", stocks[i].symbol, stocks[i].price);
        
        // Check if change is positive or negative and print in correct color
        if (stocks[i].change > 0) {
            printf("\033[1;32m+%.2f%%\033[0m\n", stocks[i].change);
        } else if (stocks[i].change < 0) {
            printf("\033[1;31m%.2f%%\033[0m\n", stocks[i].change);
        } else {
            printf("%.2f%%\n", stocks[i].change);
        }
    }
    
    return 0;
}