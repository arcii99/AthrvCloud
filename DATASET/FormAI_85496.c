//FormAI DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information about the stock
typedef struct {
    char symbol[10];
    double price;
    int volume;
} Stock;

// Define a function to print the information of a given stock
void printStock(Stock s) {
    printf("Symbol: %s\tPrice: %.2f\tVolume: %d\n", s.symbol, s.price, s.volume);
}

int main() {
    // Define an array of stocks
    Stock stocks[5];

    // Initialize the stocks
    strcpy(stocks[0].symbol, "AAPL");
    stocks[0].price = 156.72;
    stocks[0].volume = 87465134;

    strcpy(stocks[1].symbol, "GOOG");
    stocks[1].price = 1054.18;
    stocks[1].volume = 25697896;

    strcpy(stocks[2].symbol, "TSLA");
    stocks[2].price = 326.87;
    stocks[2].volume = 15369876;

    strcpy(stocks[3].symbol, "NFLX");
    stocks[3].price = 366.96;
    stocks[3].volume = 8796523;

    strcpy(stocks[4].symbol, "AMZN");
    stocks[4].price = 1699.81;
    stocks[4].volume = 6897453;

    // Print all of the stocks
    printf("Stock Market Tracker:\n\n");
    for(int i = 0; i < 5; i++) {
        printStock(stocks[i]);
    }

    // Find the highest priced stock
    int maxIndex = 0;
    for(int i = 1; i < 5; i++) {
        if(stocks[i].price > stocks[maxIndex].price) {
            maxIndex = i;
        }
    }

    // Print the highest priced stock
    printf("\nHighest Priced Stock:\n\n");
    printStock(stocks[maxIndex]);

    // Find the most traded stock
    maxIndex = 0;
    for(int i = 1; i < 5; i++) {
        if(stocks[i].volume > stocks[maxIndex].volume) {
            maxIndex = i;
        }
    }

    // Print the most traded stock
    printf("\nMost Traded Stock:\n\n");
    printStock(stocks[maxIndex]);

    return 0;
}