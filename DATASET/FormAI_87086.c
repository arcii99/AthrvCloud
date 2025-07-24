//FormAI DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10

typedef struct {
    int id;
    char name[20];
    double current_price;
    double prev_price;
} Stock;

void print_stock(Stock s) {
    printf("ID: %d | Name: %s | Current Price: %.2lf | Previous Price: %.2lf\n", s.id, s.name, s.current_price, s.prev_price);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    // Add some sample stocks
    stocks[num_stocks++] = (Stock) { 1, "AAPL", 145.33, 148.48 };
    stocks[num_stocks++] = (Stock) { 2, "GOOG", 2578.90, 2620.86 };
    stocks[num_stocks++] = (Stock) { 3, "MSFT", 264.11, 261.97 };

    // Seed random number generator
    srand(time(NULL));

    while (1) {
        // Update prices of each stock
        for (int i = 0; i < num_stocks; i++) {
            // Save current price as previous price before updating
            stocks[i].prev_price = stocks[i].current_price;

            // Generate random price change
            double price_change = (rand() % 21 - 10) / 100.0;

            // Update current price
            stocks[i].current_price += price_change * stocks[i].current_price;
        }

        // Print updated prices
        printf("\nStock Prices:\n");
        for (int i = 0; i < num_stocks; i++) {
            print_stock(stocks[i]);
        }

        // Wait for some time before updating again
        printf("\nWaiting for next update...\n");
        sleep(5);
    }

    return 0;
}