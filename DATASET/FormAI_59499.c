//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define STOCK_LIST_SIZE 10

struct stock {
    char symbol[10];
    float price;
    float change_pct;
    float high_price;
    float low_price;
    int volume;
} stocks[STOCK_LIST_SIZE];

void display_stock_details(struct stock s) {
    printf("\n%s\t\t%.2f\t%.2f%%\t%.2f\t%.2f\t%d", s.symbol, s.price, s.change_pct, s.high_price, s.low_price, s.volume);
}

void display_stocks() {
    printf("\nSymbol\t\tPrice\tChange\tHigh\tLow\tVolume");
    for(int i = 0; i < STOCK_LIST_SIZE; i++) {
        display_stock_details(stocks[i]);
    }
}

void update_stock(struct stock *s, float price, int volume) {
    if(price < s->low_price || s->low_price == 0) {
        s->low_price = price;
    }
    if(price > s->high_price) {
        s->high_price = price;
    }
    s->change_pct = ((price - s->price) / s->price) * 100;
    s->price = price;
    s->volume = s->volume + volume;
}

void simulate_stock_market() {
    for(int i = 0; i < STOCK_LIST_SIZE; i++) {
        float new_price = stocks[i].price + ((rand() % 20 - 10) / 10.0);
        int new_volume = rand() % 5000;
        update_stock(&stocks[i], new_price, new_volume);
    }
    printf("\nMarket Updated!\n");
}

int main() {
    strcpy(stocks[0].symbol, "AAPL");
    stocks[0].price = 145.80;
    stocks[0].high_price = 148.50;
    stocks[0].low_price = 140.80;
    stocks[0].volume = 10000;

    strcpy(stocks[1].symbol, "GOOG");
    stocks[1].price = 2478.38;
    stocks[1].high_price = 2510.00;
    stocks[1].low_price = 2402.45;
    stocks[1].volume = 5000;

    strcpy(stocks[2].symbol, "AMZN");
    stocks[2].price = 3422.90;
    stocks[2].high_price = 3500.00;
    stocks[2].low_price = 3329.04;
    stocks[2].volume = 3000;

    strcpy(stocks[3].symbol, "TSLA");
    stocks[3].price = 655.29;
    stocks[3].high_price = 666.14;
    stocks[3].low_price = 637.88;
    stocks[3].volume = 11000;

    strcpy(stocks[4].symbol, "MSFT");
    stocks[4].price = 277.01;
    stocks[4].high_price = 282.25;
    stocks[4].low_price = 262.10;
    stocks[4].volume = 2000;

    strcpy(stocks[5].symbol, "NVDA");
    stocks[5].price = 201.60;
    stocks[5].high_price = 209.76;
    stocks[5].low_price = 190.95;
    stocks[5].volume = 8000;

    strcpy(stocks[6].symbol, "PYPL");
    stocks[6].price = 274.98;
    stocks[6].high_price = 279.45;
    stocks[6].low_price = 266.03;
    stocks[6].volume = 1500;

    strcpy(stocks[7].symbol, "NFLX");
    stocks[7].price = 540.72;
    stocks[7].high_price = 550.00;
    stocks[7].low_price = 526.27;
    stocks[7].volume = 2500;

    strcpy(stocks[8].symbol, "FB");
    stocks[8].price = 343.18;
    stocks[8].high_price = 350.75;
    stocks[8].low_price = 335.22;
    stocks[8].volume = 4500;

    strcpy(stocks[9].symbol, "INTC");
    stocks[9].price = 54.63;
    stocks[9].high_price = 56.10;
    stocks[9].low_price = 52.87;
    stocks[9].volume = 6000;

    display_stocks();

    for(int i = 0; i < 5; i++) {
        simulate_stock_market();
        display_stocks();
    }

    return 0;
}