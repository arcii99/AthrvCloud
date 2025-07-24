//FormAI DATASET v1.0 Category: Stock market tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCK_NUMBER 100
#define MAX_COMPANY_NAME_LENGTH 50

typedef struct {
    char name[MAX_COMPANY_NAME_LENGTH];
    int currentPrice;
    int previousPrice;
} Stock;

int getRandomPrice(int, int);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Generate random stock market data
    Stock stocks[MAX_STOCK_NUMBER];
    for (int i = 0; i < MAX_STOCK_NUMBER; i++) {
        // Generate random company name
        sprintf(stocks[i].name, "Company#%d", i+1);
        // Generate random stock prices
        stocks[i].currentPrice = getRandomPrice(5, 300);
        stocks[i].previousPrice = getRandomPrice(5, 300);
    }

    // Display the stock market data
    printf("Company Name\t Current Price\t Previous Price\t Change\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < MAX_STOCK_NUMBER; i++) {
        int change = stocks[i].currentPrice - stocks[i].previousPrice;
        printf("%-15s\t %-15d\t %-15d\t %-15d\n", stocks[i].name, stocks[i].currentPrice, stocks[i].previousPrice, change);
    }

    return 0;
}

// Generates a random number between min and max (inclusive)
int getRandomPrice(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}