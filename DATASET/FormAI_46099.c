//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_STOCKS 100
#define MAX_SYMBOL_LENGTH 5

typedef struct Stock {
    char symbol[MAX_SYMBOL_LENGTH+1];
    double price;
} Stock;

Stock* createStock(char* symbol, double price) {
    Stock* stock = (Stock*) malloc(sizeof(Stock));
    strcpy(stock->symbol, symbol);
    stock->price = price;
    return stock;
}

void addStock(Stock** stocks, int* numStocks, char* symbol, double price) {
    if (*numStocks >= MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }

    stocks[*numStocks] = createStock(symbol, price);
    (*numStocks)++;
}

int main() {
    Stock* stocks[MAX_STOCKS];
    int numStocks = 0;

    // Example of adding stocks
    addStock(stocks, &numStocks, "AAPL", 128.98);
    addStock(stocks, &numStocks, "GOOGL", 2452.37);
    addStock(stocks, &numStocks, "TSLA", 561.23);

    // Displaying the stocks
    for (int i = 0; i < numStocks; i++) {
        printf("%s: $%.2f\n", stocks[i]->symbol, stocks[i]->price);
    }

    return 0;
}