//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stock {
    char symbol[10];
    float price;
    float change;
    float percent_change;
};

void display_stock(struct Stock);

int main() {
    struct Stock stocks[3] = {
        {"AAPL", 134.87, 0.53, 0.39},
        {"GOOG", 2345.68, 5.23, 0.22},
        {"TSLA", 621.44, -6.19, -0.99}
    };

    for (int i = 0; i < 3; i++) {
        display_stock(stocks[i]);
    }

    return 0;
}

void display_stock(struct Stock stock) {
    printf("Stock: %s\n", stock.symbol);
    printf("Price: $%.2f\n", stock.price);
    printf("Change: $%.2f (%.2f%)\n", stock.change, stock.percent_change);
}