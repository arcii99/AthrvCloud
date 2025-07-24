//FormAI DATASET v1.0 Category: Stock market tracker ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

#define MAX_STOCKS 10

typedef struct {
    char* name;
    float current_price;
    float last_day_price;
    float percentage_change;
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char* name, float current_price, float last_day_price) {
    stocks[num_stocks].name = name;
    stocks[num_stocks].current_price = current_price;
    stocks[num_stocks].last_day_price = last_day_price;
    stocks[num_stocks].percentage_change = ((current_price - last_day_price) / last_day_price) * 100;
    num_stocks++;
}

void print_stocks() {
    printf("Stock Name\tCurrent Price\tLast Day Price\t%% Change\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s\t\t%.2f\t\t%.2f\t\t%.2f%%\n", 
            stocks[i].name, 
            stocks[i].current_price, 
            stocks[i].last_day_price, 
            stocks[i].percentage_change);
    }
}

int main() {
    add_stock("Apple", 123.45, 120.50);
    add_stock("Microsoft", 85.60, 87.25);
    add_stock("Amazon", 1760.00, 1745.50);
    print_stocks();
    return 0;
}