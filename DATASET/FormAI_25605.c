//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char stockName[50];
    float currentValue;
    float change;
    float pChange;
} Stock;

int main() {
    int numStocks;
    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &numStocks);

    Stock* stocks = malloc(numStocks * sizeof(Stock));

    printf("Enter the stock names, current values and changes for each stock:\n");

    for (int i = 0; i < numStocks; i++) {
        printf("Stock #%d:\n", i + 1);
        scanf("%s %f %f", stocks[i].stockName, &stocks[i].currentValue, &stocks[i].change);
        stocks[i].pChange = stocks[i].change / stocks[i].currentValue;
    }

    printf("\nStock Market Tracker\n");
    printf("--------------------\n");
    printf("Stock Name\tCurrent Value\tChange\t\tPercentage Change\n");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%-s\t\t%.2f\t\t%.2f\t\t%.2f%%\n", stocks[i].stockName, stocks[i].currentValue, stocks[i].change, stocks[i].pChange * 100.0);
    }

    free(stocks);

    return 0;
}