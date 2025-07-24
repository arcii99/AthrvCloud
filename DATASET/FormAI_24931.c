//FormAI DATASET v1.0 Category: Stock market tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define THRESHOLD 0.05

// Function to generate random stock prices
float generateStockPrice(float min, float max) {
    return ((max - min) * ((float)rand() / RAND_MAX)) + min;
}

int main() {
    float prices[SIZE];
    int i, j;
    float prevPrice = 0;

    // Generate initial stock prices
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        prices[i] = generateStockPrice(100, 200);
    }

    // Print initial stock prices
    printf("Initial stock prices: \n");
    for (i = 0; i < SIZE; i++) {
        printf("%f ", prices[i]);
    }

    // Start tracking stock prices
    while (1) {
        // Update stock prices
        for (i = 0; i < SIZE; i++) {
            prices[i] = generateStockPrice(prices[i]*(1-THRESHOLD), prices[i]*(1+THRESHOLD));
        }

        // Find the maximum and minimum stock prices
        float max = prices[0];
        float min = prices[0];
        for (i = 1; i < SIZE; i++) {
            if (prices[i] > max) {
                max = prices[i];
            }
            if (prices[i] < min) {
                min = prices[i];
            }
        }

        // Print current stock prices
        printf("\nCurrent stock prices: \n");
        for (i = 0; i < SIZE; i++) {
            printf("%f ", prices[i]);
        }

        // Determine if there is a significant change in the stock prices
        float diff = (max - min)/prevPrice;
        if (diff > THRESHOLD) {
            printf("\n\nALERT: Significant change in stock prices!\n\n");
        }

        // Wait for some time before updating stock prices again
        printf("\n\nWaiting...\n");
        sleep(5);

        // Store the previous maximum and minimum stock prices
        prevPrice = max - min;
    }

    return 0;
}