//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
} Stock;

int main() {
    Stock stocks[5];

    strcpy(stocks[0].name, "AAPL");
    stocks[0].price = 124.09;

    strcpy(stocks[1].name, "GOOG");
    stocks[1].price = 1739.52;

    strcpy(stocks[2].name, "MSFT");
    stocks[2].price = 225.95;

    strcpy(stocks[3].name, "TSLA");
    stocks[3].price = 849.46;

    strcpy(stocks[4].name, "AMZN");
    stocks[4].price = 3299.30;

    printf("Current stock prices:\n");

    for (int i=0; i<5; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }

    return 0;
}