//FormAI DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>
#define NUM_STOCKS 5

typedef struct {
    char symbol[10];
    float current_price;
    float open_price;
} stock_t;

int main() {
    stock_t stocks[NUM_STOCKS] = {
        {"AAPL", 111.23, 110.50},
        {"GOOG", 1702.00, 1701.50},
        {"AMZN", 3117.00, 3100.00},
        {"NFLX", 504.43, 500.00},
        {"TSLA", 420.00, 419.00}
    };

    printf("Welcome to the Stock Market Tracker\n");
    printf("Enter the symbol of a stock to track: ");
    char input[10];
    scanf("%s", input);

    int found = 0;
    for (int i = 0; i < NUM_STOCKS; i++) {
        if (strcmp(input, stocks[i].symbol) == 0) {
            found = 1;
            printf("%s\n", stocks[i].symbol);
            printf("Current price: $%.2f\n", stocks[i].current_price);
            printf("Open price: $%.2f\n", stocks[i].open_price);
            printf("%% Change: %.2f%%\n", (stocks[i].current_price - stocks[i].open_price) / stocks[i].open_price * 100);
        }
    }

    if (!found) {
        printf("Sorry, symbol not found.\n");
    }

    return 0;
}