//FormAI DATASET v1.0 Category: Stock market tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random stock prices
float generateStockPrice()
{
    return (float)(rand() % 1000) / 10.0; // Generate a random float between 0 and 100
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize variables
    char companies[5][20] = {"Apple", "Google", "Microsoft", "Facebook", "Amazon"};
    float prices[5][30];
    int i, j;

    // Generate initial stock prices for each company
    for(i = 0; i < 5; i++)
    {
        printf("%s stock prices: ", companies[i]);
        for(j = 0; j < 30; j++)
        {
            prices[i][j] = generateStockPrice();
            printf("%.2f ", prices[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Track the stock prices for 10 days
    for(i = 0; i < 10; i++)
    {
        printf("Day %d:\n", i+1);
        for(j = 0; j < 5; j++)
        {
            // Generate a percentage change in stock price
            float delta = generateStockPrice();
            int sign = rand() % 2 ? -1 : 1; // Randomly choose either -1 or 1

            // Calculate the new stock price
            float newPrice = prices[j][i] * (1 + sign * delta / 100);

            // Update the stock price
            prices[j][i+1] = newPrice;

            // Display the company, old price, delta, and new price
            printf("%s: %.2f (%+.2f%%) => %.2f\n", companies[j], prices[j][i], delta, newPrice);
        }
        printf("\n");
    }

    return 0;
}