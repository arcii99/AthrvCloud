//FormAI DATASET v1.0 Category: Stock market tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol[10];
    double price;
    double percent_change;
} Stock;

int main(int argc, char *argv[]) {
    Stock stocks[5] = {
        {"AAPL", 134.95, -0.61},
        {"GOOGL", 2317.36, 1.06},
        {"TSLA", 711.32, -0.64},
        {"FB", 307.10, 2.15},
        {"MSFT", 248.08, -0.07}
    };
    
    printf("Welcome to the Stock Market Tracker!\n\n");
    printf("Symbol\tPrice\tPercent Change\n");
    
    for (int i = 0; i < 5; i++) {
        printf("%s\t$%.2f\t%.2f%%\n", stocks[i].symbol, stocks[i].price, stocks[i].percent_change);
    }
    
    printf("\nEnter the symbol of the stock you want to track: ");
    char input[10];
    fgets(input, 10, stdin);
    
    for (int i = 0; i < 5; i++) {
        if (strcmp(input, stocks[i].symbol) == 0) {
            printf("%s is currently trading at $%.2f, up %.2f%% today.\n", stocks[i].symbol, stocks[i].price, stocks[i].percent_change);
            exit(0);
        }
    }
    
    printf("Sorry, we could not find that stock symbol.\n");
    
    return 0;
}