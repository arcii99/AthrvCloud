//FormAI DATASET v1.0 Category: Stock market tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5     // number of stocks to track
#define MAX 100 // maximum stock price
#define MIN 1   // minimum stock price

// function to generate a random stock price between MIN and MAX
int generate_price() {
    return (rand() % (MAX - MIN + 1)) + MIN;
}

// function to update stock prices asynchronously
void update_prices(int prices[]) {
    int i;
    for (i = 0; i < N; i++) {
        prices[i] = generate_price();
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // initialize stock prices
    int prices[N];
    int i;
    for (i = 0; i < N; i++) {
        prices[i] = generate_price();
    }

    // print initial stock prices
    printf("Initial Stock Prices:\n");
    for (i = 0; i < N; i++) {
        printf("Stock %d: $%d\n", i+1, prices[i]);
    }
    printf("\n");

    // simulate asynchronous updates to stock prices
    printf("Simulating asynchronous updates to stock prices:\n");
    while (1) {
        update_prices(prices);
        for (i = 0; i < N; i++) {
            printf("Stock %d: $%d ", i+1, prices[i]);
        }
        printf("\n");
        sleep(5); // wait for 5 seconds before updating prices again
    }

    return 0;
}