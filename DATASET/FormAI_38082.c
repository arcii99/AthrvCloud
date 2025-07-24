//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_STOCKS 50

typedef struct stock {
    char name[20];
    double price;
    double change;
} stock;

void clear_screen() {
    if (system("CLS")) system("clear");
}

void print_header() {
    printf("\n%-10s | %-10s | %-10s\n", "Name", "Price", "Change");
    printf("----------------------------------------\n");
}

void print_stock(stock s) {
    printf("%-10s | $ %-9.2lf | %-+9.2lf%%\n", s.name, s.price, s.change);
}

void update_stock(stock *s) {
    double multiplier = (double) rand() / RAND_MAX;
    double change = (multiplier * 5) - 2.5;

    s->change = change;
    s->price += change;
}

int main() {
    srand(time(NULL));

    stock stocks[MAX_STOCKS] = {
        {"AAPL", 154.23, 0.0},
        {"GOOG", 1012.32, 0.0},
        {"AMZN", 1712.34, 0.0},
        {"MSFT", 75.43, 0.0},
        {"NFLX", 366.78, 0.0},
        {"FB", 167.98, 0.0},
        {"TSLA", 255.34, 0.0},
        {"NVDA", 265.12, 0.0},
        {"INTC", 45.23, 0.0},
        {"CSCO", 47.56, 0.0}
    };

    int num_stocks = sizeof(stocks) / sizeof(stocks[0]);

    clear_screen();
    print_header();

    while (1) {
        for (int i = 0; i < num_stocks; i++) {
            update_stock(&stocks[i]);
            print_stock(stocks[i]);
        }

        print_header();
        sleep(2);
        clear_screen();
    }

    return 0;
}