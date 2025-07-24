//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STOCKS 10

typedef struct Stock {
    char symbol[5];
    double price;
    double prev_price;
} Stock;

void updatePrices(Stock *stocks, int num) {
    for (int i = 0; i < num; i++) {
        stocks[i].prev_price = stocks[i].price;
        stocks[i].price += ((double)rand() / RAND_MAX) * 10 - 5;
    }
}

int main() {
    srand(time(NULL));
    Stock stocks[NUM_STOCKS] = {
        {"AAPL", 150.99, 150.99},
        {"GOOG", 1239.99, 1239.99},
        {"FB", 330.49, 330.49},
        {"AMZN", 3256.92, 3256.92},
        {"TSLA", 654.87, 654.87},
        {"NVDA", 195.34, 195.34},
        {"MSFT", 295.46, 295.46},
        {"NFLX", 566.21, 566.21},
        {"DIS", 171.12, 171.12},
        {"NKE", 123.56, 123.56}
    };

    printf("Welcome to the Stock Market Tracker!\n\n");

    while (1) {
        updatePrices(stocks, NUM_STOCKS);

        printf("Symbol\tCurrent Price\tPrev. Price\tChange\n");
        for (int i = 0; i < NUM_STOCKS; i++) {
            printf("%s\t%.2f\t\t%.2f\t\t%.2f%%\n", stocks[i].symbol, stocks[i].price, stocks[i].prev_price, (stocks[i].price - stocks[i].prev_price) / stocks[i].prev_price * 100);
        }

        printf("\n");
        printf("Press ENTER to update prices or type 'quit' to exit.\n");

        char input[5];
        fgets(input, 5, stdin);

        if (input[0] == 'q' && input[1] == 'u' && input[2] == 'i' && input[3] == 't') {
            printf("Thanks for using the Stock Market Tracker!\n");
            break;
        }

        system("clear");
    }

    return 0;
}