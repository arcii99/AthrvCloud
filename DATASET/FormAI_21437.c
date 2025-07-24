//FormAI DATASET v1.0 Category: Stock market tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define UPDATE_INTERVAL 5
#define NUMBER_OF_STOCKS 5

typedef struct stock {
    char name[10];
    double price;
} stock_t;

stock_t stocks[NUMBER_OF_STOCKS] = {
    {"AAPL", 115.32},
    {"GOOG", 1699.92},
    {"TSLA", 420.00},
    {"AMZN", 3116.78},
    {"MSFT", 213.25},
};

void print_stocks() {
    int i;
    printf("%-10s %-10s\n", "Name", "Price");
    for (i = 0; i < NUMBER_OF_STOCKS; i++) {
        printf("%-10s %-10.2f\n", stocks[i].name, stocks[i].price);
    }
    printf("\n");
}

void *update_stocks(void *arg) {
    while (1) {
        int i;
        for (i = 0; i < NUMBER_OF_STOCKS; i++) {
            // Randomly add or subtract up to 10% of the current price
            stocks[i].price += stocks[i].price * (rand() % 20 - 10) / 100.0;
        }
        sleep(UPDATE_INTERVAL);
    }
    return NULL;
}

int main() {
    int i;
    char input[BUFFER_SIZE];
    pthread_t update_thread;

    printf("Welcome to the Stock Market Tracker!\n\n");

    // Start the thread to update the stock prices
    pthread_create(&update_thread, NULL, update_stocks, NULL);

    while (1) {
        // Clear the screen
        system("clear");

        // Print the current stock prices
        print_stocks();

        // Read user input
        printf("Enter the name of a stock to track:\n");
        fgets(input, BUFFER_SIZE, stdin);
        input[strcspn(input, "\n")] = 0;

        // Find the matching stock and print its price
        for (i = 0; i < NUMBER_OF_STOCKS; i++) {
            if (strcmp(input, stocks[i].name) == 0) {
                printf("The current price of %s is %.2f\n\n", input, stocks[i].price);
                break;
            }
        }

        // If the user didn't enter a valid stock name, print an error message
        if (i == NUMBER_OF_STOCKS) {
            printf("Error: Could not find stock %s\n\n", input);
        }

        // Wait for a few seconds before refreshing the screen
        sleep(3);
    }

    return 0;
}