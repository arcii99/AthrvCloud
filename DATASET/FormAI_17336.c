//FormAI DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a struct for the stock market's data
struct StockMarket {
    char stockName[10];
    float price;
    float change;
};

int main() {
    // Define five different stocks
    struct StockMarket stocks[5] = {
        {"AAPL", 158.73, -2.34},
        {"GOOG", 1210.21, 6.32},
        {"AMZN", 2023.05, -3.69},
        {"FB", 180.77, 1.25},
        {"NFLX", 345.56, -2.87}
    };
    
    // Print out the current stock data
    printf("Current Stock Data:\n");
    for (int i=0; i<5; i++) {
        printf("%s: $%.2f (%.2f%%)\n", stocks[i].stockName, stocks[i].price, stocks[i].change);
    }
    
    // Calculate the average price of all the stocks
    float total = 0;
    for (int i=0; i<5; i++) {
        total += stocks[i].price;
    }
    float average = total / 5;
    
    // Print out the average stock price
    printf("\nAverage Stock Price: $%.2f\n", average);
    
    // Calculate the standard deviation of the stock prices
    float sum = 0;
    for (int i=0; i<5; i++) {
        sum += pow(stocks[i].price - average, 2);
    }
    float stdDev = sqrt(sum / 5);
    
    // Print out the standard deviation of the stock prices
    printf("Standard Deviation: $%.2f\n\n", stdDev);
    
    // Allow the user to search for a stock by name
    printf("Search for a Stock:\n");
    char stockSearch[10];
    printf("Enter the stock symbol: ");
    scanf("%s", stockSearch);
    
    // Use a linear search to find the stock and return its data
    for (int i=0; i<5; i++) {
        if (strcmp(stocks[i].stockName, stockSearch) == 0) {
            printf("\n%s: $%.2f (%.2f%%)\n", stocks[i].stockName, stocks[i].price, stocks[i].change);
            break;
        }
        if (i == 4) {
            printf("Stock not found.\n");
        }
    }
    
    return 0;
}