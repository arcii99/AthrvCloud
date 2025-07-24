//FormAI DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 5
#define MAX_PRICE_CHANGE 10

struct stock {
    char name[20];
    float price;
};

void print_stock(struct stock s) {
    printf("%s: $%.2f\n", s.name, s.price);
}

int main() {
    srand(time(NULL));

    struct stock stocks[MAX_STOCKS] = {
        {"AAPL", 150.54},
        {"GOOG", 762.41},
        {"TSLA", 312.34},
        {"GM", 42.29},
        {"FB", 174.67}
    };
    int num_stocks = MAX_STOCKS;

    printf("Welcome to the Intelligent Stock Market Tracker!\n");
    printf("We are tracking %d stocks:\n", num_stocks);
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    while (1) {
        printf("\n");

        // Randomly choose a stock to update
        int stock_index = rand() % num_stocks;
        struct stock s = stocks[stock_index];

        // Generate a random price change for the stock
        float price_change = ((float) rand() / RAND_MAX) * MAX_PRICE_CHANGE * 2 - MAX_PRICE_CHANGE;

        // Update the price
        float new_price = s.price + price_change;
        if (new_price < 0) {
            new_price = 0;
        }
        stocks[stock_index].price = new_price;

        printf("Updated price of %s:\n", s.name);
        print_stock(stocks[stock_index]);

        // Wait for 2 seconds before updating again
        printf("Waiting for 2 seconds...\n");
        sleep(2);
    }

    return 0;
}