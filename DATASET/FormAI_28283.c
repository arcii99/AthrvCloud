//FormAI DATASET v1.0 Category: Stock market tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STOCKS 10
#define INTERVAL 3

// Function to generate random stock prices
float generatePrice() {
    float price = (float)(rand() % 1000) / 10.0;
    return price;
}

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Initialize the array of stock names and prices
    char stockNames[STOCKS][20] = {
        {"Apple Inc."},
        {"Microsoft Corporation"},
        {"Alphabet Inc."},
        {"Amazon.com, Inc."},
        {"Facebook, Inc."},
        {"Tesla, Inc."},
        {"Nvidia Corporation"},
        {"Procter & Gamble Co"},
        {"Johnson & Johnson"},
        {"Berkshire Hathaway Inc."}
    };
    float stockPrices[STOCKS];

    // Set the initial stock prices
    for (int i = 0; i < STOCKS; i++) {
        stockPrices[i] = generatePrice();
    }

    // Print the headers
    printf("%-25s %-10s %-10s %-10s\n", "Stock Name", "Price", "Change", "Percent");

    // Loop through the intervals
    for (int j = 0; j < INTERVAL; j++) {
        // Loop through the stocks and update the prices
        for (int i = 0; i < STOCKS; i++) {
            float oldPrice = stockPrices[i];
            float change = generatePrice() - 5.0;
            stockPrices[i] += change;
            float percent = (stockPrices[i] - oldPrice) / oldPrice * 100.0;

            // Print the stock information
            printf("%-25s $%-9.2f %-+9.2f %-+9.2f%%\n", stockNames[i], stockPrices[i], change, percent);
        }
        printf("\n");
        // Sleep for 1 second before updating the prices again
        sleep(1);
    }

    return 0;
}