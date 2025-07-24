//FormAI DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STOCKS 5

typedef struct Stock {
    char name[20];
    double price;
    double change;
} Stock;

void displayStocks(Stock* stocks) {
    printf("%-20s %-20s %-20s\n\n", "Name", "Price", "Change");
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("%-20s $%-19.2lf ", stocks[i].name, stocks[i].price);
        if (stocks[i].change > 0) {
            printf("+");
        }
        printf("%.2lf\n", stocks[i].change);
    }
}

void updateStocks(Stock* stocks) {
    srand(time(0));
    for (int i = 0; i < NUM_STOCKS; i++) {
        double change = ((double)rand()/(double)(RAND_MAX)) * 10 - 5;
        stocks[i].change = change;
        stocks[i].price += change;
    }
}

int main() {
    Stock stocks[NUM_STOCKS] = {{"AAPL", 148.48, 0.00},
                                 {"GOOGL", 2768.74, 0.00},
                                 {"TSLA", 757.13, 0.00},
                                 {"AMZN", 3274.12, 0.00},
                                 {"FB", 356.30, 0.00}};

    printf("---------------Initial Stock Prices---------------\n");
    displayStocks(stocks);

    for (int i = 0; i < 5; i++) {
        printf("\n\n");
        printf("-----------------Day %d-----------------\n", i+1);
        updateStocks(stocks);
        displayStocks(stocks);
    }
    return 0;
}