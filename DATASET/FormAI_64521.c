//FormAI DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock {
    char name[50];
    float price;
    float change;
} Stock;

void printStock(Stock *s) {
    printf("%s\t\t%.2f\t\t%.2f%%\n", s->name, s->price, s->change);
}

int main() {
    Stock stockList[5];
    strcpy(stockList[0].name, "Apple Inc.");
    stockList[0].price = 134.50;
    stockList[0].change = 0.25;

    strcpy(stockList[1].name, "Amazon.com Inc.");
    stockList[1].price = 3126.00;
    stockList[1].change = -0.75;

    strcpy(stockList[2].name, "Facebook Inc.");
    stockList[2].price = 258.00;
    stockList[2].change = 1.50;

    strcpy(stockList[3].name, "Microsoft Corporation");
    stockList[3].price = 234.18;
    stockList[3].change = 0.50;

    strcpy(stockList[4].name, "Tesla, Inc.");
    stockList[4].price = 720.45;
    stockList[4].change = -2.00;

    printf("Stock Name\tPrice ($)\tChange\n");
    for(int i=0; i<5; i++) {
        printStock(&stockList[i]);
    }
    return 0;
}