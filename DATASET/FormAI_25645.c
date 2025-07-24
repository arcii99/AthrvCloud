//FormAI DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_PRICE 1000

int main() {
    srand(time(NULL));

    // Initializing the prices of initial stocks
    int stocks[MAX_STOCKS];
    for(int i=0; i<MAX_STOCKS; i++) {
        stocks[i] = rand() % MAX_PRICE + 1;
    }

    // Starting the trading
    int day = 1;
    int transactions = 0;
    while(1) {
        // Printing the current state of the market
        printf("Day %d:\n", day);
        for(int i=0; i<MAX_STOCKS; i++) {
            printf("Stock %d: $%d\n", i+1, stocks[i]);
        }
        printf("\n");

        // Checking if market reached its peak
        int peak = 1;
        for(int i=1; i<MAX_STOCKS; i++) {
            if(stocks[i] > stocks[i-1]) {
                peak = 0;
                break;
            }
        }
        if(peak == 1) {
            printf("\nThe market reached its peak on day %d with %d transactions!\n", day-1, transactions);
            break;
        }

        // Choosing a random stock to buy/sell
        int stock = rand() % MAX_STOCKS;
        int action = rand() % 2;
        int price = rand() % MAX_PRICE + 1;

        // Executing the transaction
        if(action == 0 && stocks[stock] >= price) {
            stocks[stock] -= price;
            transactions++;
            printf("Transaction %d: Bought stock %d for $%d.\n\n", transactions, stock+1, price);
        }
        else if(action == 1) {
            stocks[stock] += price;
            transactions++;
            printf("Transaction %d: Sold stock %d for $%d.\n\n", transactions, stock+1, price);
        }

        // Moving to the next day
        day++;
    }

    return 0;
}