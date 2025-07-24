//FormAI DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random stock prices
float generateStockPrice() {
    return (float)rand()/(float)(RAND_MAX/100);
}

int main() {
    srand(time(0)); // Seed for random number generation

    float currentPrice = generateStockPrice(); // Set initial stock price
    float prevPrice = currentPrice; // Keep track of previous stock price
    float maxPrice = currentPrice; // Keep track of highest stock price so far
    float minPrice = currentPrice; // Keep track of lowest stock price so far
    int numDays = 0; // Keep track of number of days the program has run

    printf("Welcome to the Mystery Stock Market Tracker!\n\n");
    printf("Today's stock price: $%.2f\n", currentPrice);
    printf("Highest stock price so far: $%.2f\n", maxPrice);
    printf("Lowest stock price so far: $%.2f\n\n", minPrice);

    while (1) { // Infinite loop
        prevPrice = currentPrice; // Set previous price to current price
        currentPrice = generateStockPrice(); // Generate new price

        if (currentPrice > maxPrice) { // Check if new price is the highest so far
            printf("Attention! New highest stock price of $%.2f reached!\n", currentPrice);
            maxPrice = currentPrice; // Update max price
        }

        if (currentPrice < minPrice) { // Check if new price is the lowest so far
            printf("Attention! New lowest stock price of $%.2f reached!\n", currentPrice);
            minPrice = currentPrice; // Update min price
        }

        printf("Today's stock price: $%.2f\n", currentPrice); // Print current price
        printf("Change since yesterday: $%.2f\n", currentPrice - prevPrice); // Print change in price since yesterday
        printf("Highest stock price so far: $%.2f\n", maxPrice); // Print highest price so far
        printf("Lowest stock price so far: $%.2f\n\n", minPrice); // Print lowest price so far
        
        numDays++; // Increment number of days

        if (numDays == 10) { // Check if program has run for 10 days
            printf("Congratulations! You have successfully tracked the Mystery Stock market for 10 days!\n");
            printf("Thank you for using the Mystery Stock Market Tracker.\n");
            break; // Exit infinite loop
        }

        // Wait for 3 seconds before printing new data
        printf("Waiting 3 seconds before generating new stock price...\n\n");
        sleep(3);
    }

    return 0; // End program
}