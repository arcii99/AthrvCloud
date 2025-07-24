//FormAI DATASET v1.0 Category: Stock market tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of company stocks that will be tracked
#define NUM_STOCKS 5

// Define a structure to hold information about a company's stock
typedef struct {
    char name[20];
    float price;
    float change_percent;
} Stock;

int main() {
    // Create an array of Stock structures
    Stock stocks[NUM_STOCKS];

    // Set initial values for each stock
    strcpy(stocks[0].name, "Apple Inc.");
    stocks[0].price = 143.64;
    stocks[0].change_percent = -0.27;

    strcpy(stocks[1].name, "Amazon.com Inc.");
    stocks[1].price = 2875.73;
    stocks[1].change_percent = 0.13;

    strcpy(stocks[2].name, "Tesla Inc.");
    stocks[2].price = 687.20;
    stocks[2].change_percent = -2.45;

    strcpy(stocks[3].name, "Microsoft Corporation");
    stocks[3].price = 228.99;
    stocks[3].change_percent = 0.48;

    strcpy(stocks[4].name, "Google (Alphabet) Inc.");
    stocks[4].price = 2280.67;
    stocks[4].change_percent = 3.25;

    // Display the initial values for each stock
    printf("Initial stock values:\n");
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("%s: $%.2f (%.2f%%)\n", stocks[i].name, stocks[i].price, stocks[i].change_percent);
    }

    // Wait for user input to update stock prices
    printf("\nPress any key to update stock prices...");
    getchar();

    // Update stock prices randomly within a certain range
    for (int i = 0; i < NUM_STOCKS; i++) {
        // Generate a random price change between -2% and 2%
        float random_change = ((float)rand()/(float)(RAND_MAX)) * 4 - 2;
        stocks[i].price += (stocks[i].price * random_change / 100);

        // Update the percent change
        stocks[i].change_percent = (stocks[i].price - 143.64) / 143.64 * 100;
    }

    // Display the updated values for each stock
    printf("\nUpdated stock values:\n");
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("%s: $%.2f (%.2f%%)\n", stocks[i].name, stocks[i].price, stocks[i].change_percent);
    }

    return 0;
}