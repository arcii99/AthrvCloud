//FormAI DATASET v1.0 Category: Stock market tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define some random stock names for the program
char* stock_names[] = {"Google", "Amazon", "Tesla", "Apple", "Microsoft", "Facebook", "Netflix", "Uber", "Zoom", "Twitter"};

// Helper function to generate random stock price
float random_price()
{
    return (float) (rand() % 10000) / 100.0;  // Return a float value between 0 and 99.99
}

int main()
{
    srand(time(0));  // Initialize random seed based on current time

    int num_stocks = sizeof(stock_names) / sizeof(stock_names[0]);  // Calculate the number of stocks in the program
    
    // Initialize price arrays for each stock
    float current_prices[num_stocks];
    float previous_prices[num_stocks];
    for (int i = 0; i < num_stocks; i++)
    {
        current_prices[i] = random_price();
        previous_prices[i] = current_prices[i];
    }

    printf("Welcome to the most fun stock market tracker ever!\n");
    printf("To make this experience even more fun, we'll be tracking the prices of some of the most ridiculous stocks out there!\n");
    printf("Let's get started!\n\n");

    // Loop forever to keep updating stock prices
    while (1)
    {
        printf("----------------------------------------------------\n");
        printf("Stock Name         Current Price       Previous Price\n");
        printf("----------------------------------------------------\n");

        // Loop through all stocks and update their prices
        for (int i = 0; i < num_stocks; i++)
        {
            // Generate a random deviation between -10 and 10
            float deviation = (float) (rand() % 2001 - 1000) / 100.0;

            // Update the current and previous prices
            previous_prices[i] = current_prices[i];
            current_prices[i] += deviation;

            // Make sure the current price is not negative
            if (current_prices[i] < 0.0)
            {
                current_prices[i] = 0.0;
            }

            // Print the stock details
            printf("%-18s $%9.2f        $%9.2f\n", stock_names[i], current_prices[i], previous_prices[i]);
        }

        printf("----------------------------------------------------\n\n");

        // Sleep for 2 seconds to simulate real-time updates
        printf("Waiting for the next update...\n\n");
        sleep(2);
    }

    return 0;
}