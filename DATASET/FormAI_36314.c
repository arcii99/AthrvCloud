//FormAI DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stock {
    char ticker[10];
    float current_price;
    float previous_price;
};

int main() {
    struct Stock stock1, stock2, stock3;
    struct Stock *ptr_stock1, *ptr_stock2, *ptr_stock3;

    ptr_stock1 = &stock1;
    ptr_stock2 = &stock2;
    ptr_stock3 = &stock3;

    strcpy(ptr_stock1 -> ticker, "AAPL");
    ptr_stock1 -> current_price = 145.48;
    ptr_stock1 -> previous_price = 145.60;

    strcpy(ptr_stock2 -> ticker, "GOOGL");
    ptr_stock2 -> current_price = 2670.39;
    ptr_stock2 -> previous_price = 2669.50;

    strcpy(ptr_stock3 -> ticker, "TSLA");
    ptr_stock3 -> current_price = 686.08;
    ptr_stock3 -> previous_price = 690.21;

    printf("Ticker\t\tCurrent Price\t\tPrevious Price\n");
    printf("%s\t\t%.2f\t\t\t%.2f\n", ptr_stock1 -> ticker, ptr_stock1 -> current_price, ptr_stock1 -> previous_price);
    printf("%s\t\t%.2f\t\t\t%.2f\n", ptr_stock2 -> ticker, ptr_stock2 -> current_price, ptr_stock2 -> previous_price);
    printf("%s\t\t%.2f\t\t\t%.2f\n", ptr_stock3 -> ticker, ptr_stock3 -> current_price, ptr_stock3 -> previous_price);

    return 0;
}