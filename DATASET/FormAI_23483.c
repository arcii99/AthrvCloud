//FormAI DATASET v1.0 Category: Stock market tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    int stockPrice = 1000; // starting stock price
    int maxChange = 50; // maximum change in stock price allowed
    
    printf("Starting stock price: $%d\n\n", stockPrice);
    
    for (int i = 1; i <= 10; i++) {
        int change = rand() % (maxChange+1) * (rand() % 2 ? 1 : -1); // generate random change in stock price
        
        stockPrice += change; // apply the change to the stock price
        
        if (stockPrice < 0) {
            stockPrice = 0; // prevent negative stock price
        }
        
        printf("Day %d: ", i);
        
        if (change > 0) {
            printf("Stock price increased by $%d to $%d\n", change, stockPrice);
        } else if (change < 0) {
            printf("Stock price decreased by $%d to $%d\n", abs(change), stockPrice);
        } else {
            printf("Stock price remained the same at $%d\n", stockPrice);
        }
        
        printf("\n");
    }
    
    return 0;
}