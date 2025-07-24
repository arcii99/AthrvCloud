//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    // read stock info from file
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: File not found!");
        return 1;
    }
    char line[MAX_NAME_LENGTH + 10];
    while (fgets(line, sizeof(line), fp)) {
        char *name = strtok(line, ",");
        if (name == NULL) continue;
        double price = atof(strtok(NULL, ","));
        if (price == 0) continue;
        Stock newStock;
        strncpy(newStock.name, name, MAX_NAME_LENGTH);
        newStock.price = price;
        stocks[numStocks++] = newStock;
    }

    // show stock info
    printf("Stock Name\tPrice\n");
    printf("--------------------\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%-15s\t%.2f\n", stocks[i].name, stocks[i].price);
    }

    // calculate average price
    double totalPrice = 0;
    for (int i = 0; i < numStocks; i++) {
        totalPrice += stocks[i].price;
    }
    double avgPrice = totalPrice / numStocks;

    // show average and highest price
    double highestPrice = 0;
    char highestName[MAX_NAME_LENGTH];
    for (int i = 0; i < numStocks; i++) {
        if (stocks[i].price > highestPrice) {
            highestPrice = stocks[i].price;
            strncpy(highestName, stocks[i].name, MAX_NAME_LENGTH);
        }
    }
    printf("\nAverage price: %.2f\n", avgPrice);
    printf("Highest price: %.2f (%s)\n", highestPrice, highestName);

    return 0;
}