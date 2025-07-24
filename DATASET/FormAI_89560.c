//FormAI DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to calculate the mean of a given array
double mean(double arr[], int size) {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum/size;
}

// Function to calculate the standard deviation of a given array
double stdDev(double arr[], int size) {
    double meanValue = mean(arr, size);
    double sumOfSquares = 0;

    for(int i = 0; i < size; i++) {
        sumOfSquares += pow((arr[i] - meanValue), 2);
    }

    return sqrt(sumOfSquares/size);
}

// Stock structure to hold stock properties
struct Stock {
    char symbol[10];
    double price;
    double priceChange;
};

int main() {
    // Initializing an array of Stock structs
    struct Stock stocks[5] = {
        {"AAPL", 137.09, 0.57},
        {"MSFT", 259.50, -0.89},
        {"GOOG", 2585.32, 2.23},
        {"TSLA", 725.64, -1.62},
        {"AMZN", 3340.30, 1.32}
    };

    int numStocks = sizeof(stocks)/sizeof(stocks[0]);

    // Initializing arrays to hold stock prices and price changes
    double stockPrices[numStocks];
    double stockPriceChanges[numStocks];

    for(int i = 0; i < numStocks; i++) {
        stockPrices[i] = stocks[i].price;
        stockPriceChanges[i] = stocks[i].priceChange;
    }

    double stockPricesMean = mean(stockPrices, numStocks);
    double stockPricesStdDev = stdDev(stockPrices, numStocks);

    double stockPriceChangesMean = mean(stockPriceChanges, numStocks);
    double stockPriceChangesStdDev = stdDev(stockPriceChanges, numStocks);

    printf("Statistical review of stock data:\n\n");
    printf("%-10s%-10s%-10s\n", "Symbol", "Price", "Change");

    for(int i = 0; i < numStocks; i++) {
        printf("%-10s%.2lf     %+0.2lf\n", stocks[i].symbol, stocks[i].price, stocks[i].priceChange);
    }

    printf("\nMean stock price: %.2lf\n", stockPricesMean);
    printf("Standard deviation of stock prices: %.2lf\n\n", stockPricesStdDev);

    printf("Mean stock price change: %+0.2lf\n", stockPriceChangesMean);
    printf("Standard deviation of stock price changes: %.2lf\n", stockPriceChangesStdDev);

    return 0;
}