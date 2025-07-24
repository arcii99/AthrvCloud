//FormAI DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_STOCKS 5
#define MAX_NAME_LENGTH 50

typedef struct stock {
    char name[MAX_NAME_LENGTH];
    float current_price;
} stock_t;

float get_random_price();

int main() {
    stock_t stocks[NUM_STOCKS];
    float prices[NUM_STOCKS];
    srand(time(NULL)); // Seed random number generator with current time

    // Populate stocks array with random stock names and current prices
    for (int i = 0; i < NUM_STOCKS; i++) {
        // Generate random stock name
        char name[MAX_NAME_LENGTH];
        for (int j = 0; j < MAX_NAME_LENGTH; j++) {
            name[j] = (rand() % 26) + 'A'; // Generate uppercase letter
        }
        strcpy(stocks[i].name, name);

        // Generate random current price
        stocks[i].current_price = get_random_price();
        prices[i] = stocks[i].current_price;
    }

    // Print out initial stock prices
    printf("Initial stock prices:\n");
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].current_price);
    }

    // Track stock prices for simulated trading day
    for (int hour = 1; hour <= 8; hour++) {
        // Wait for 1 second to simulate an hour passing
        printf("\nWaiting for 1 hour\n");
        sleep(1);

        printf("\nHour %d stock prices:\n", hour);
        for (int i = 0; i < NUM_STOCKS; i++) {
            float price_change = get_random_price() - prices[i];
            stocks[i].current_price += price_change;
            prices[i] = stocks[i].current_price;
            printf("%s: $%.2f (%+.2f)\n", stocks[i].name, stocks[i].current_price, price_change);
        }
    }

    printf("\nFinal stock prices:\n");
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].current_price);
    }

    return 0;
}

// Helper function to generate random price changes
float get_random_price() {
    return ((float)rand()/(float)(RAND_MAX)) * 20.0 - 10.0; // Random float between -10.0 and 10.0
}