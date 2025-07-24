//FormAI DATASET v1.0 Category: Stock market tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    float currentPrice;
    int quantity;
} Stock;

void printPortfolio(Stock portfolio[], int numStocks) {
    printf("\n");
    printf("Portfolio:\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%s - Quantity: %d - Current Price: %.2f - Total Value: %.2f\n",
               portfolio[i].name,
               portfolio[i].quantity,
               portfolio[i].currentPrice,
               portfolio[i].currentPrice * portfolio[i].quantity);
    }

    printf("\n");
}

void updatePrices(Stock portfolio[], int numStocks, float newPrices[]) {
    printf("\n");
    printf("Updated Prices:\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%s - Current Price: %.2f -> %.2f\n",
               portfolio[i].name,
               portfolio[i].currentPrice,
               newPrices[i]);

        portfolio[i].currentPrice = newPrices[i];
    }

    printf("\n");
}

int main() {
    float prices1[] = {10.50, 20.75, 15.00, 8.25, 12.50};
    float prices2[] = {12.00, 21.25, 16.75, 7.50, 14.00};

    Stock portfolio[MAX_STOCKS] = {
        {"AAPL", 10.50, 100},
        {"GOOG", 20.75, 50},
        {"AMZN", 15.00, 75},
        {"TSLA", 8.25, 200},
        {"MSFT", 12.50, 125}
    };

    int numStocks = 5;

    printPortfolio(portfolio, numStocks);
    updatePrices(portfolio, numStocks, prices1);
    printPortfolio(portfolio, numStocks);
    updatePrices(portfolio, numStocks, prices2);
    printPortfolio(portfolio, numStocks);

    return 0;
}