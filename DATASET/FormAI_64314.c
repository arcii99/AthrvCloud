//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define the maximum number of stocks
#define MAX_STOCKS 10

// define a struct to represent a stock
typedef struct {
    char name[10];
    float price;
    float change;
} stock_t;

// function to get a random float in a specified range
float get_random_float(float min, float max) {
    return ((float)rand() / RAND_MAX) * (max - min) + min;
}

int main() {
    // initialize random seed
    srand(time(NULL));

    // initialize an array of stock_t structs
    stock_t stocks[MAX_STOCKS];

    // initialize stock names
    strcpy(stocks[0].name, "AAPL");
    strcpy(stocks[1].name, "GOOG");
    strcpy(stocks[2].name, "MSFT");
    strcpy(stocks[3].name, "AMZN");
    strcpy(stocks[4].name, "FB");
    strcpy(stocks[5].name, "TSLA");
    strcpy(stocks[6].name, "NVDA");
    strcpy(stocks[7].name, "PYPL");
    strcpy(stocks[8].name, "NFLX");
    strcpy(stocks[9].name, "INTC");

    // initialize stock prices
    for (int i = 0; i < MAX_STOCKS; i++) {
        stocks[i].price = get_random_float(100, 1000);
    }

    // print initial stock prices
    printf("Initial stock prices:\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }

    // simulate stock changes for 10 iterations
    for (int i = 1; i <= 10; i++) {
        // wait for 1 second
        sleep(1);

        // update stock prices
        for (int j = 0; j < MAX_STOCKS; j++) {
            float change = get_random_float(-10, 10);
            stocks[j].price += change;
            stocks[j].change = change;
        }

        // print current stock prices and changes
        printf("\nIteration %d:\n", i);
        for (int j = 0; j < MAX_STOCKS; j++) {
            printf("%s: $%.2f (%+.2f)\n", stocks[j].name, stocks[j].price, stocks[j].change);
        }
    }

    return 0;
}