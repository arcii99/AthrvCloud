//FormAI DATASET v1.0 Category: Stock market tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 1000
#define MAX_STOCKS 10

struct Stock {
    char name[20];
    double price;
    int volume;
};

struct StockPortfolio {
    char name[20];
    struct Stock stocks[MAX_STOCKS];
    int num_of_stocks;
};

int main() {
    int choice = 0, i, j;
    struct StockPortfolio portfolio;
    strcpy(portfolio.name, "My Portfolio");
    portfolio.num_of_stocks = 0;
    while (choice != 4) {
        printf("\n\n==== %s ====\n\n", portfolio.name);
        printf("1. Add stock\n2. Remove stock\n3. View stocks\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (portfolio.num_of_stocks >= MAX_STOCKS) {
                    printf("Maximum number of stocks reached!\n");
                    break;
                }
                printf("Enter stock name, price, and volume: ");
                scanf("%s %lf %d", portfolio.stocks[portfolio.num_of_stocks].name,
                      &portfolio.stocks[portfolio.num_of_stocks].price,
                      &portfolio.stocks[portfolio.num_of_stocks].volume);
                portfolio.num_of_stocks++;
                printf("Stock added successfully!\n");
                break;
            case 2:
                if (portfolio.num_of_stocks == 0) {
                    printf("No stocks to remove!\n");
                    break;
                }
                printf("Enter the index of the stock to remove: ");
                scanf("%d", &i);
                if (i >= portfolio.num_of_stocks) {
                    printf("Index out of range!\n");
                    break;
                }
                for (j = i; j < portfolio.num_of_stocks - 1; j++) {
                    portfolio.stocks[j] = portfolio.stocks[j + 1];
                }
                portfolio.num_of_stocks--;
                printf("Stock removed successfully!\n");
                break;
            case 3:
                if (portfolio.num_of_stocks == 0) {
                    printf("No stocks to view!\n");
                    break;
                }
                printf("Name\tPrice\tVolume\n");
                for (i = 0; i < portfolio.num_of_stocks; i++) {
                    printf("%s\t%.2lf\t%d\n", portfolio.stocks[i].name,
                           portfolio.stocks[i].price, portfolio.stocks[i].volume);
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}