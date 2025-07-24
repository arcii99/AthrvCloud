//FormAI DATASET v1.0 Category: Stock market tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>

struct stock {
    char symbol[6];
    float price;
    int volume;
};

int main() {
    int num_stocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &num_stocks);

    struct stock *stocks = (struct stock*) malloc(num_stocks * sizeof(struct stock));
    
    // read in stock information
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the symbol, price, and volume of stock %d (separated by spaces): ", i+1);
        scanf("%s%f%d", stocks[i].symbol, &stocks[i].price, &stocks[i].volume);
    }
    
    // print out stock information
    printf("\nSymbol  Price   Volume\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-6s  $%-6.2f %d\n", stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }

    // calculate total value of all stocks
    float total_value = 0;
    for (int i = 0; i < num_stocks; i++) {
        total_value += (stocks[i].price * stocks[i].volume);
    }

    // print out total value
    printf("\nTotal value of all stocks: $%.2f\n", total_value);

    free(stocks);
    return 0;
}