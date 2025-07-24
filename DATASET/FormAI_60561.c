//FormAI DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STOCK_COUNT 5

typedef struct {
    char *name;
    float price;
    float change;
} Stock;

void printStock(Stock s);
void updateStock(Stock *s);
void printHeader();
void printFooter();

int main() {
    srand(time(NULL));
    Stock stocks[STOCK_COUNT] = {
        {"AAPL", 126.08, -0.12},
        {"GOOGL", 2427.62, 0.45},
        {"MSFT", 260.74, 1.32},
        {"AMZN", 3306.83, -0.67},
        {"TSLA", 684.90, 3.45}
    };

    printHeader();

    while(1) {
        for(int i = 0; i < STOCK_COUNT; i++) {
            updateStock(&stocks[i]);
            printStock(stocks[i]);
        }
        printFooter();
        usleep(1000000);
    }

    return 0;
}

void printStock(Stock s) {
    printf("| %4s | %8.2f | %8.2f%% |\n", s.name, s.price, s.change);
}

void updateStock(Stock *s) {
    float r = ((float)rand()/(float)(RAND_MAX)) * 2.0 - 1.0;
    s->price += r * 10.0;
    s->change = r * 100.0 / s->price;
}

void printHeader() {
    printf("|------+----------+----------|\n");
    printf("| CODE |   PRICE  |  CHANGE  |\n");
    printf("|------+----------+----------|\n");
}

void printFooter() {
    printf("|------+----------+----------|\n");
}