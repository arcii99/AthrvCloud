//FormAI DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stock {
    char symbol[10];
    float price;
    float change;
} Stock;

int main() {
    Stock stocks[5];
    strcpy(stocks[0].symbol, "AAPL");
    strcpy(stocks[1].symbol, "GOOG");
    strcpy(stocks[2].symbol, "MSFT");
    strcpy(stocks[3].symbol, "TSLA");
    strcpy(stocks[4].symbol, "FB");

    for(int i=0; i<5; i++) {
        stocks[i].price = (float)(rand() % 1000 + 1);
        stocks[i].change = ((float)(rand() % 100 + 1))/100;
    }

    printf("  SYMBOL  |  PRICE  |  CHANGE\n");
    printf("_____________________________\n");

    for(int i=0; i<5; i++) {
        printf("   %s     $ %.2f    %.2f%%\n", stocks[i].symbol, stocks[i].price, stocks[i].change);
    }

    return 0;
}