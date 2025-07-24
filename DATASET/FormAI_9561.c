//FormAI DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define maximum and minimum values for stock prices
#define MAX_PRICE 1000
#define MIN_PRICE 1

// Define stock data structure with name and price attributes
struct Stock {
    char name[20];
    int price;
};

// Define function to generate random price within range
int generatePrice() {
    return rand() % (MAX_PRICE - MIN_PRICE + 1) + MIN_PRICE;
}

int main() {
    // Declare array of 5 stocks
    struct Stock stocks[5];

    // Initialize stock names
    strcpy(stocks[0].name, "AAPL");
    strcpy(stocks[1].name, "GOOG");
    strcpy(stocks[2].name, "TSLA");
    strcpy(stocks[3].name, "FB");
    strcpy(stocks[4].name, "AMZN");

    // Initialize stock prices
    for (int i = 0; i < 5; i++) {
        stocks[i].price = generatePrice();
    }

    // Loop to display stock prices every second
    bool exit = false;
    while (!exit) {
        system("clear");
        printf("==============================\n");
        printf("|   STOCK MARKET TRACKER     |\n");
        printf("==============================\n\n");
        printf("Stock name\tPrice\n");
        for (int i = 0; i < 5; i++) {
            printf("%s\t\t%d\n", stocks[i].name, stocks[i].price);
            stocks[i].price += (rand() % 50 - 25);
            if (stocks[i].price < MIN_PRICE) {
                stocks[i].price = MIN_PRICE;
            } else if (stocks[i].price > MAX_PRICE) {
                stocks[i].price = MAX_PRICE;
            }
        }
        printf("\nPress 'q' to quit...\n");
        if (getchar() == 'q') {
            exit = true;
        } else {
            sleep(1);
        }
    }

    return 0;
}