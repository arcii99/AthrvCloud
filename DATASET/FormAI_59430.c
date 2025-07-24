//FormAI DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STOCKS 5

struct Stock {
    char name[20];
    float current_price;
    float open_price;
    float close_price;
};

typedef struct Stock Stock;

void update_price(Stock *stock) {
    srand(time(NULL));
    float price_difference = ((float) rand() / RAND_MAX) * (10.0 - (-10.0)) + (-10.0);
    stock->current_price = stock->open_price + price_difference;
    stock->close_price = stock->current_price;
}

void print_stock(Stock *stock) {
    printf("%-20s%.2f\t%.2f\t%.2f\n", stock->name, stock->open_price, stock->current_price, stock->close_price);
}

int main() {
    Stock stocks[NUM_STOCKS];

    // initialize stock data
    strcpy(stocks[0].name, "APPL");
    stocks[0].open_price = 250.00;
    update_price(&stocks[0]);

    strcpy(stocks[1].name, "GOOG");
    stocks[1].open_price = 1500.00;
    update_price(&stocks[1]);

    strcpy(stocks[2].name, "AMZN");
    stocks[2].open_price = 2000.00;
    update_price(&stocks[2]);

    strcpy(stocks[3].name, "NFLX");
    stocks[3].open_price = 500.00;
    update_price(&stocks[3]);

    strcpy(stocks[4].name, "TSLA");
    stocks[4].open_price = 1000.00;
    update_price(&stocks[4]);

    // print header
    printf("%-20s%-10s%-10s%-10s\n", "STOCK NAME", "OPEN", "CURRENT", "CLOSE");

    // print stock data
    for (int i = 0; i < NUM_STOCKS; i++) {
        print_stock(&stocks[i]);
    }
    
    return 0;
}