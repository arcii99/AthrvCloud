//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char company[20];
    float price;
    float change;
} Stock;

int main() {
    Stock stocks[5];
    strcpy(stocks[0].company, "AAPL");
    stocks[0].price = 148.48;
    stocks[0].change = 0.05;
    strcpy(stocks[1].company, "GOOG");
    stocks[1].price = 2703.80;
    stocks[1].change = -0.02;
    strcpy(stocks[2].company, "AMZN");
    stocks[2].price = 3334.69;
    stocks[2].change = 0.10;
    strcpy(stocks[3].company, "MSFT");
    stocks[3].price = 303.77;
    stocks[3].change = -0.01;
    strcpy(stocks[4].company, "TSLA");
    stocks[4].price = 746.36;
    stocks[4].change = -0.03;

    printf("%-10s  %-10s  %-10s\n", "Company", "Price", "Change");
    for (int i=0; i<5; i++) {
        printf("%-10s  %-10.2f  ", stocks[i].company, stocks[i].price);
        if (stocks[i].change > 0) {
            printf("+");
        } 
        printf("%.2f\n", stocks[i].change);
    }

    return 0;
}