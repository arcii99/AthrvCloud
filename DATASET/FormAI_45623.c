//FormAI DATASET v1.0 Category: Stock market tracker ; Style: realistic
// This is a program that tracks stock market data using C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_STOCKS 100
#define MAX_DATA_POINTS 500

// Define a struct to hold stock data
struct stock_data {
    char name[MAX_NAME];
    float prices[MAX_DATA_POINTS];
    int num_data_points;
};

// Define a struct to hold all the stocks
struct stock_market {
    struct stock_data stocks[MAX_STOCKS];
    int num_stocks;
};

// Function to find the average price of a stock
float average_price(struct stock_data stock) {
    float sum = 0;
    for (int i = 0; i < stock.num_data_points; i++) {
        sum += stock.prices[i];
    }
    return sum / stock.num_data_points;
}

int main() {

    // Initialize the stock market
    struct stock_market market = {0};

    // Add some sample stock data
    struct stock_data stock1 = {"AAPL", {100, 110, 120, 130, 140}, 5};
    struct stock_data stock2 = {"GOOGL", {500, 510, 520, 530, 540}, 5};
    market.stocks[0] = stock1;
    market.stocks[1] = stock2;
    market.num_stocks = 2;

    // Print the average price of each stock
    for (int i = 0; i < market.num_stocks; i++) {
        printf("Average price of %s: $%.2f\n", market.stocks[i].name, average_price(market.stocks[i]));
    }

    return 0;
}