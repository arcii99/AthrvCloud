//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STOCKS 5
#define MAX_PRICE_CHANGE 20

int main(void) {
    srand(time(NULL));  // Seed the random number generator
    
    char *stock_names[NUM_STOCKS] = {"AAPL", "GOOGL", "AMZN", "FB", "TSLA"};
    int stock_prices[NUM_STOCKS] = {100, 200, 300, 400, 500};
    
    printf("Welcome to the multiplayer stock market tracker! Press CTRL+C to exit.\n");
    
    while (1) {
        printf("\nCurrent stock prices:\n");
        
        // Print out each stock's name and price
        for (int i = 0; i < NUM_STOCKS; i++) {
            printf("%s: $%d\n", stock_names[i], stock_prices[i]);
        }
        
        // Generate random changes to the prices of each stock
        for (int i = 0; i < NUM_STOCKS; i++) {
            int price_change = rand() % (2 * MAX_PRICE_CHANGE + 1) - MAX_PRICE_CHANGE;
            stock_prices[i] += price_change;
        }
        
        // Wait a few seconds before updating the prices again
        printf("\nWaiting for other players to catch up...\n");
        sleep(3);
    }
    
    return 0;
}