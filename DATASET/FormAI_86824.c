//FormAI DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

struct stock_market_info {
    char symbol[10];
    float price;
    char date[11];
};

int main() {
    int num_stocks;
    printf("Enter the number of stocks in the file: ");
    scanf("%d", &num_stocks);

    struct stock_market_info *market_data = (struct stock_market_info*)malloc(num_stocks * sizeof(struct stock_market_info));

    FILE *fp;
    fp = fopen("stock_market_data.txt", "r");
    if (fp == NULL) {
        printf("Error opening the file\n");
        return 1;
    }

    for (int i = 0; i < num_stocks; i++) {
        fscanf(fp, "%s %f %s", market_data[i].symbol, &market_data[i].price, market_data[i].date);
    }

    fclose(fp);

    printf("Stock Symbol\tPrice\tDate\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s\t\t%.2f\t%s\n", market_data[i].symbol, market_data[i].price, market_data[i].date);
    }

    printf("Enter a stock symbol to search: ");
    char search_symbol[10];
    scanf("%s", search_symbol);

    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(market_data[i].symbol, search_symbol) == 0) {
            printf("Stock Symbol\tPrice\tDate\n");
            printf("%s\t\t%.2f\t%s\n", market_data[i].symbol, market_data[i].price, market_data[i].date);
            break;
        }
    }

    free(market_data);
    return 0;
}