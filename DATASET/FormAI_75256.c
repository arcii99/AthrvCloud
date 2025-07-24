//FormAI DATASET v1.0 Category: Stock market tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int stock_prices[5] = {25, 32, 18, 40, 55};
    
    printf("Welcome to the surreal stock market tracker!\n");
    printf("Here are today's stock prices:\n");
    
    for (int i = 0; i < 5; i++) {
        printf("Stock %d: $%d\n", i + 1, stock_prices[i]);
    }
    
    time_t t;
    srand((unsigned) time(&t));
    
    int random_stock = rand() % 5;
    int random_change = rand() % 20 - 10;
    
    printf("\nSuddenly, the market takes a surreal turn!\n");
    printf("Stock %d experiences a %d%% change in price!\n", random_stock + 1, random_change);
    
    stock_prices[random_stock] += (stock_prices[random_stock] * random_change) / 100;
    
    printf("\nHere are the new stock prices:\n");
    
    for (int i = 0; i < 5; i++) {
        printf("Stock %d: $%d\n", i + 1, stock_prices[i]);
    }
    
    return 0;
}