//FormAI DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>

// Define a struct for holding stock market data
typedef struct {
    char symbol[10];
    float price;
    int volume;
} Stock;

// Sample data for three stocks
Stock stock1 = {"AAPL", 145.29, 100000};
Stock stock2 = {"GOOG", 4240.99, 50000};
Stock stock3 = {"MSFT", 298.71, 75000};

int main() {
    // Print out the initial stock prices and volumes
    printf("Initial Stock Prices:\n");
    printf("%s - Price: %.2f, Volume: %d\n", stock1.symbol, stock1.price, stock1.volume);
    printf("%s - Price: %.2f, Volume: %d\n", stock2.symbol, stock2.price, stock2.volume);
    printf("%s - Price: %.2f, Volume: %d\n", stock3.symbol, stock3.price, stock3.volume);

    // Simulate updates to the stock prices and volumes
    stock1.price -= 2.50;
    stock1.volume += 25000;

    stock2.price *= 0.95;
    stock2.volume += 10000;

    stock3.price += 1.75;
    stock3.volume -= 5000;

    // Print out the updated stock prices and volumes
    printf("\nUpdated Stock Prices:\n");
    printf("%s - Price: %.2f, Volume: %d\n", stock1.symbol, stock1.price, stock1.volume);
    printf("%s - Price: %.2f, Volume: %d\n", stock2.symbol, stock2.price, stock2.volume);
    printf("%s - Price: %.2f, Volume: %d\n", stock3.symbol, stock3.price, stock3.volume);

    return 0;
}