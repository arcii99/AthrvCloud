//FormAI DATASET v1.0 Category: Stock market tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 50
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10
#define MAX_DATE_LEN 10

struct Stock {
    char name[MAX_NAME_LEN];
    float price;
    char date[MAX_DATE_LEN];
};

struct Stock stocks[MAX_STOCKS];

int add_stock(char name[], float price, char date[]) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0] == '\0') {
            strcpy(stocks[i].name, name);
            stocks[i].price = price;
            strcpy(stocks[i].date, date);
            return 1;
        }
    }

    return 0;
}

void print_stocks() {
    printf("-------------------------------------------------\n");
    printf("|%-20s |%-10s |%-10s |\n", "Name", "Price", "Date");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0] != '\0') {
            printf("|%-20s |%-10.2f |%-10s |\n", stocks[i].name, stocks[i].price, stocks[i].date);
        }
    }

    printf("-------------------------------------------------\n");
}

void update_prices(float percentage) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0] != '\0') {
            stocks[i].price *= (1 + percentage);
        }
    }
}

int main() {
    add_stock("Microsoft", 120.50, "2021-06-05");
    add_stock("Apple", 145.00, "2021-06-05");
    add_stock("Tesla", 590.00, "2021-06-05");

    printf("Initial Stocks:\n");
    print_stocks();

    printf("Updating prices by 5 percent...\n");
    update_prices(0.05);

    printf("Updated Stocks:\n");
    print_stocks();

    return 0;
}