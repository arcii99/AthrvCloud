//FormAI DATASET v1.0 Category: Stock market tracker ; Style: minimalist
#include <stdio.h>
#include <string.h>

typedef struct Stock {
    char name[50];
    double price;
} Stock;

int main() {
    Stock stocks[5]; // create an array of 5 stocks
    strcpy(stocks[0].name, "AAPL"); // add stock names and prices
    stocks[0].price = 136.87;
    strcpy(stocks[1].name, "GOOG");
    stocks[1].price = 2102.38;
    strcpy(stocks[2].name, "TSLA");
    stocks[2].price = 666.23;
    strcpy(stocks[3].name, "NFLX");
    stocks[3].price = 527.58;
    strcpy(stocks[4].name, "MSFT");
    stocks[4].price = 240.06;

    while (1) { // continuously track stock prices
        int choice;
        printf("Enter 1 to track AAPL, 2 for GOOG, 3 for TSLA, 4 for NFLX, 5 for MSFT, or 0 to exit: ");
        scanf("%d", &choice);
        if (choice == 0) break; // exit program
        printf("%s stock price: $%.2lf\n", stocks[choice-1].name, stocks[choice-1].price);
    }

    return 0;
}