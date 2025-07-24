//FormAI DATASET v1.0 Category: Stock market tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize seed for random numbers

    int stockPrices[10]; // declare array for 10 stock prices

    // initialize array with random stock prices between 50 and 200
    for (int i = 0; i < 10; i++) {
        stockPrices[i] = (rand() % 151) + 50;
    }

    printf("Today's Stock Market Tracker: \n\n");

    // print header for table
    printf("%-10s%-10s\n", "Stock", "Price");

    // print each stock and its price
    for (int i = 0; i < 10; i++) {
        switch (i) {
            case 0: printf("%-10s$%d\n", "AAPL", stockPrices[i]); break;
            case 1: printf("%-10s$%d\n", "TSLA", stockPrices[i]); break;
            case 2: printf("%-10s$%d\n", "AMZN", stockPrices[i]); break;
            case 3: printf("%-10s$%d\n", "GOOG", stockPrices[i]); break;
            case 4: printf("%-10s$%d\n", "MSFT", stockPrices[i]); break;
            case 5: printf("%-10s$%d\n", "NFLX", stockPrices[i]); break;
            case 6: printf("%-10s$%d\n", "FB", stockPrices[i]); break;
            case 7: printf("%-10s$%d\n", "NVDA", stockPrices[i]); break;
            case 8: printf("%-10s$%d\n", "JPM", stockPrices[i]); break;
            case 9: printf("%-10s$%d\n", "AA", stockPrices[i]); break;
        }
    }

    return 0;
}