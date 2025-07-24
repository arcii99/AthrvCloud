//FormAI DATASET v1.0 Category: Stock market tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol[10];
    float price;
    float change;
} Stock;

int main() {
    Stock stocks[5];
    
    strcpy(stocks[0].symbol, "AAPL");
    stocks[0].price = 127.35;
    stocks[0].change = -0.23;
    
    strcpy(stocks[1].symbol, "GOOG");
    stocks[1].price = 2717.10;
    stocks[1].change = 1.87;
    
    strcpy(stocks[2].symbol, "TSLA");
    stocks[2].price = 609.89;
    stocks[2].change = -2.34;
    
    strcpy(stocks[3].symbol, "FB");
    stocks[3].price = 332.46;
    stocks[3].change = 0.89;
    
    strcpy(stocks[4].symbol, "AMZN");
    stocks[4].price = 3271.12;
    stocks[4].change = 0.04;
    
    printf("Symbol\tPrice\tChange\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t$%.2f\t%.2f%%\n", stocks[i].symbol, stocks[i].price, stocks[i].change);
    }
    
    return 0;
}