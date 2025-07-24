//FormAI DATASET v1.0 Category: Stock market tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define maximum number of stocks to track
#define MAX_STOCKS 10

// Define struct for each stock
typedef struct {
    char symbol[10];
    float current_price;
    float previous_close;
    bool trending_up;
} Stock;

// Function to print stock details
void printStock(Stock s) {
    printf("%s\nCurrent Price: $%.2f \nPrevious Close: $%.2f \nTrending Up: %s\n\n", s.symbol, s.current_price, s.previous_close, s.trending_up ? "YES" : "NO");
}

int main() {
    // Declare array of stocks
    Stock stocks[MAX_STOCKS];

    // Populate stock data (can be replaced with user input)
    strcpy(stocks[0].symbol, "AAPL");
    stocks[0].current_price = 142.06;
    stocks[0].previous_close = 142.65;
    stocks[0].trending_up = false;

    strcpy(stocks[1].symbol, "AMZN");
    stocks[1].current_price = 3339.29;
    stocks[1].previous_close = 3352.15;
    stocks[1].trending_up = true;

    strcpy(stocks[2].symbol, "TSLA");
    stocks[2].current_price = 726.13;
    stocks[2].previous_close = 739.88;
    stocks[2].trending_up = false;

    int num_stocks = 3; // Number of stocks in array (for now)

    // Print all stock details
    for (int i = 0; i < num_stocks; i++) {
        printStock(stocks[i]);
    }

    // Add new stock (if there's space)
    if (num_stocks < MAX_STOCKS) {
        num_stocks++;
        strcpy(stocks[num_stocks-1].symbol, "GOOG");
        stocks[num_stocks-1].current_price = 2434.05;
        stocks[num_stocks-1].previous_close = 2421.28;
        stocks[num_stocks-1].trending_up = true;
    }

    // Print all stock details again (including new stock)
    for (int i = 0; i < num_stocks; i++) {
        printStock(stocks[i]);
    }

    return 0;
}