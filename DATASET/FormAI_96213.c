//FormAI DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <string.h>
#define MAX_STOCKS 20 // maximum number of stocks we can track

// structure for stock data
struct Stock {
    char symbol[10];
    float price;
    int volume;
};

int main() {
    struct Stock stocks[MAX_STOCKS];
    int numStocks = 0;
    
    // loop to add stocks
    while (numStocks < MAX_STOCKS) {
        printf("Enter stock symbol (or 'done' to finish adding stocks): ");
        scanf("%s", stocks[numStocks].symbol);
        
        if (strcmp(stocks[numStocks].symbol, "done") == 0) {
            break;
        }
        
        printf("Enter stock price: ");
        scanf("%f", &stocks[numStocks].price);
        
        printf("Enter stock volume: ");
        scanf("%d", &stocks[numStocks].volume);
        
        numStocks++; // increment number of stocks
    }
    
    // print table of stocks
    printf("\n%-10s %-10s %-10s\n", "Symbol", "Price", "Volume");
    for (int i = 0; i < numStocks; i++) {
        printf("%-10s %-10.2f %-10d\n", stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }
    
    return 0;
}