//FormAI DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const float MAX_CHANGE = 2.5; // Maximum percentage change per day
    const float START_PRICE = 150.0; // Starting price of stock
    float current_price = START_PRICE;

    // Seed random number generator
    srand(time(NULL));

    // Display initial stock price
    printf("Starting stock price: $%.2f\n", START_PRICE);

    // Simulate 30 days of stock prices
    for (int i = 1; i <= 30; i++) {
        // Generate a random percentage change
        float percentage_change = (float)rand() / RAND_MAX * MAX_CHANGE * 2 - MAX_CHANGE;

        // Calculate the new price
        float new_price = current_price * (1 + percentage_change / 100);

        // Ensure new price is positive
        if (new_price <= 0) {
            new_price = 0.01;
        }

        // Display the new price
        printf("Day %d: $%.2f (%+.2f%%)\n", i, new_price, percentage_change);

        // Set the current price to the new price
        current_price = new_price;
    }

    // Display final stock price
    printf("Final stock price: $%.2f\n", current_price);

    return 0;
}