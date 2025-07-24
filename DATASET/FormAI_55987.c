//FormAI DATASET v1.0 Category: Stock market tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stock {
    char symbol[5]; // Stock symbol
    float current_price; // Current price of the stock
    float previous_price; // Price of the stock at the end of the previous trading session
    float percent_change; // Percentage change from previous price
} Stock;

int main() {
    int n; // Number of stocks
    printf("Enter the number of stocks: ");
    scanf("%d", &n);

    Stock* stocks = (Stock*)malloc(n * sizeof(Stock)); // Dynamically allocate memory for the stocks array

    for (int i = 0; i < n; i++) {
        printf("Enter the symbol of stock %d: ", i + 1);
        scanf("%s", stocks[i].symbol);
        printf("Enter the current price of stock %d: ", i + 1);
        scanf("%f", &stocks[i].current_price);
        printf("Enter the previous price of stock %d: ", i + 1);
        scanf("%f", &stocks[i].previous_price);

        // Calculate percentage change
        stocks[i].percent_change = (stocks[i].current_price - stocks[i].previous_price) / stocks[i].previous_price * 100;
    }

    // Print the stock table
    printf("Symbol\tCurrent Price\tPrevious Price\t%% Change\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%.2f\t\t%.2f\t\t%.2f%%\n", stocks[i].symbol, stocks[i].current_price, stocks[i].previous_price, stocks[i].percent_change);
    }

    free(stocks); // Free dynamically allocated memory
    return 0;
}