//FormAI DATASET v1.0 Category: Stock market tracker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

typedef struct {
    char stock_name[MAX_LENGTH];
    double stock_price;
} Stock;

int main(void) {

    Stock google_stock = {"Google", 1500.00};
    Stock apple_stock = {"Apple", 200.00};

    printf("Name: %s, Price: %.2lf\n", google_stock.stock_name, google_stock.stock_price);
    printf("Name: %s, Price: %.2lf\n", apple_stock.stock_name, apple_stock.stock_price);

    google_stock.stock_price = 1550.00;
    apple_stock.stock_price = 220.00;

    printf("After price update:\n");
    printf("Name: %s, Price: %.2lf\n", google_stock.stock_name, google_stock.stock_price);
    printf("Name: %s, Price: %.2lf\n", apple_stock.stock_name, apple_stock.stock_price);

    return 0;
}