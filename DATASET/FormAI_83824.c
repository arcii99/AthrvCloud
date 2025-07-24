//FormAI DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_STOCKS 5

struct stock {
    char name[20];
    float current_price;
    float last_price;
    float open_price;
    float high_price;
    float low_price;
};

void update_stock_prices(struct stock *stocks);
void print_stock_info(struct stock *stocks);
void wait(int sec);

int main() {
    struct stock stocks[NUM_STOCKS];

    // Initialize stock values
    strcpy(stocks[0].name, "AAPL");
    stocks[0].current_price = 132.05;
    stocks[0].last_price = 130.48;
    stocks[0].open_price = 132.04;
    stocks[0].high_price = 132.34;
    stocks[0].low_price = 130.93;

    strcpy(stocks[1].name, "GOOGL");
    stocks[1].current_price = 2231.55;
    stocks[1].last_price = 2209.49;
    stocks[1].open_price = 2234.56;
    stocks[1].high_price = 2236.80;
    stocks[1].low_price = 2216.11;

    strcpy(stocks[2].name, "MSFT");
    stocks[2].current_price = 244.49;
    stocks[2].last_price = 245.17;
    stocks[2].open_price = 242.89;
    stocks[2].high_price = 244.67;
    stocks[2].low_price = 242.57;

    strcpy(stocks[3].name, "TSLA");
    stocks[3].current_price = 743.62;
    stocks[3].last_price = 744.12;
    stocks[3].open_price = 749.69;
    stocks[3].high_price = 751.00;
    stocks[3].low_price = 742.12;

    strcpy(stocks[4].name, "AMZN");
    stocks[4].current_price = 3623.59;
    stocks[4].last_price = 3604.49;
    stocks[4].open_price = 3635.45;
    stocks[4].high_price = 3639.18;
    stocks[4].low_price = 3602.17;

    printf("Initial Stock Info:\n");
    print_stock_info(stocks);

    // Continuously update stock prices
    while (1) {
        update_stock_prices(stocks);

        printf("Updated Stock Info:\n");
        print_stock_info(stocks);

        wait(5); // Wait for 5 seconds before updating prices again
    }

    return 0;
}

// Updates current prices of each stock
void update_stock_prices(struct stock *stocks) {
    for (int i = 0; i < NUM_STOCKS; i++) {
        stocks[i].last_price = stocks[i].current_price;
        float price_diff = (rand() % 101) / 100.0 * 5.0; // Generate a random price difference between -5% to 5%
        if (rand() % 2 == 0) { // 50% chance of the price increasing or decreasing
            stocks[i].current_price += price_diff;
        } else {
            stocks[i].current_price -= price_diff;
        }
        if (stocks[i].current_price > stocks[i].high_price) {
            stocks[i].high_price = stocks[i].current_price;
        }
        if (stocks[i].current_price < stocks[i].low_price) {
            stocks[i].low_price = stocks[i].current_price;
        }
    }
}

// Prints info of each stock
void print_stock_info(struct stock *stocks) {
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("%s:\n", stocks[i].name);
        printf("\tCurrent Price: %.2f\n", stocks[i].current_price);
        printf("\tChange: %.2f (%.2f%%)\n", (stocks[i].current_price - stocks[i].last_price), (stocks[i].current_price - stocks[i].last_price) / stocks[i].last_price * 100.0);
        printf("\tOpen Price: %.2f\n", stocks[i].open_price);
        printf("\tHigh Price: %.2f\n", stocks[i].high_price);
        printf("\tLow Price: %.2f\n", stocks[i].low_price);
        printf("\n");
    }
}

// Wait for specified number of seconds
void wait(int sec) {
    time_t end = time(NULL) + sec;
    while (time(NULL) < end);
}