//FormAI DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 25

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    while (numStocks < MAX_STOCKS) {
        printf("Enter the name of stock #%d (or 'QUIT' to exit): ", numStocks + 1);
        scanf("%s", stocks[numStocks].name);

        if (strcmp(stocks[numStocks].name, "QUIT") == 0) {
            break;
        }

        printf("Enter the price of stock #%d: ", numStocks + 1);
        scanf("%f", &stocks[numStocks].price);

        numStocks++;
    }

    // Display stock prices
    printf("\nStock prices:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }

    // Determine average stock price
    float total = 0.0;
    for (int i = 0; i < numStocks; i++) {
        total += stocks[i].price;
    }
    float average = total / numStocks;

    // Display average stock price
    printf("\nThe average stock price is: $%.2f\n", average);

    return 0;
}