//FormAI DATASET v1.0 Category: Stock market tracker ; Style: future-proof
#include <stdio.h>

// Declare a struct to hold stock information
typedef struct {
    char *symbol;
    double price;
    double change;
} Stock;

// Define a function to display stock information
void display_stock(Stock stock) {
    printf("%s:\n", stock.symbol);
    printf("Price: $%.2f\n", stock.price);
    printf("Change: $%.2f\n", stock.change);
}

int main() {
    // Declare an array of stocks
    Stock stocks[] = {
        {"AAPL", 123.45, 1.23},
        {"GOOG", 678.90, -2.34},
        {"TSLA", 987.65, 5.67}
    };

    // Print out the stocks
    for (int i = 0; i < 3; i++) {
        display_stock(stocks[i]);
    }

    // Update a stock price
    stocks[0].price = 130.00;
    stocks[0].change = 6.55;

    // Print out the updated stock
    display_stock(stocks[0]);

    return 0;
}