//FormAI DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 5
#define MAX_NAME_LEN 50

// Struct to hold stock information
typedef struct Stock {
    char name[MAX_NAME_LEN];
    float currentPrice;
    float previousPrice;
    float percentChange;
} Stock;

// Function to get current price for a stock
float getCurrentPrice(char *stockName) {
    float price;
    // implementation of getting current price for a stock from the internet
    return price;
}

// Function to calculate percent change
float getPercentChange(float current, float previous) {
    return ((current - previous) / previous) * 100;
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;
    char input[MAX_NAME_LEN];
    do {
        printf("Enter stock name (or 'done' to finish): ");
        fgets(input, MAX_NAME_LEN, stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline
        if (strcmp(input, "done") == 0) {
            break;
        }
        if (numStocks >= MAX_STOCKS) {
            printf("Maximum number of stocks reached.\n");
            break;
        }
        // Check if stock has already been added
        int alreadyAdded = 0;
        for (int i = 0; i < numStocks; i++) {
            if (strcmp(input, stocks[i].name) == 0) {
                alreadyAdded = 1;
                printf("Stock already added.\n");
                break;
            }
        }
        if (alreadyAdded) {
            continue;
        }
        // Add stock
        strncpy(stocks[numStocks].name, input, MAX_NAME_LEN);
        stocks[numStocks].currentPrice = getCurrentPrice(input);
        stocks[numStocks].previousPrice = 0;
        stocks[numStocks].percentChange = 0;
        numStocks++;
    } while (1);
    // Track stocks
    while (1) {
        printf("\nCurrent Stock Prices:\n");
        for (int i = 0; i < numStocks; i++) {
            printf("%s: %.2f (%.2f%%)\n", stocks[i].name, stocks[i].currentPrice, stocks[i].percentChange);
        }
        printf("\nEnter stock name to update prices (or 'done' to exit): ");
        fgets(input, MAX_NAME_LEN, stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline
        if (strcmp(input, "done") == 0) {
            break;
        }
        int stockIndex = -1;
        for (int i = 0; i < numStocks; i++) {
            if (strcmp(input, stocks[i].name) == 0) {
                stockIndex = i;
                break;
            }
        }
        if (stockIndex == -1) {
            printf("Stock not found.\n");
            continue;
        }
        // Update stock price and percent change
        stocks[stockIndex].previousPrice = stocks[stockIndex].currentPrice;
        stocks[stockIndex].currentPrice = getCurrentPrice(input);
        stocks[stockIndex].percentChange = getPercentChange(stocks[stockIndex].currentPrice, stocks[stockIndex].previousPrice);
    }
    printf("Exiting program.\n");
    return 0;
}