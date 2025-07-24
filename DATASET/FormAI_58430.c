//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>

#define MAX_STOCKS 50

struct stock {
    char name[20];
    float price;
};

int main() {
    struct stock stocks[MAX_STOCKS];
    int num_stocks;
    float total_price = 0;
    float avg_price;

    printf("Enter the number of stocks: ");
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i+1);
        scanf("%s", stocks[i].name);

        printf("Enter the price of stock %d: ", i+1);
        scanf("%f", &stocks[i].price);

        total_price += stocks[i].price;
    }

    avg_price = total_price / num_stocks;

    printf("\nStocks details:\n");
    printf("%-20s %s\n", "Stock Name", "Price");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s $%.2f\n", stocks[i].name, stocks[i].price);
        if (stocks[i].price > avg_price) {
            printf("This stock is above average price.\n");
        } else {
            printf("This stock is below average price.\n");
        }
    }

    printf("\nThe average price of all stocks is $%.2f\n", avg_price);

    return 0;
}