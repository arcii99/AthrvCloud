//FormAI DATASET v1.0 Category: Stock market tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float percent_change;

} Stock;

void print_stocks(Stock *stocks, int num_stocks) {
    printf("\n************ STOCK TRACKER ************\n\n");
    for (int i = 0; i < num_stocks; i++) {
        if (stocks[i].percent_change < 0) {
            printf("%s: $%.2f (%.2f%%)\t [ ALERT : PRICE DECREASED BY %.2f%% ]\n", stocks[i].name, stocks[i].price, stocks[i].percent_change, -1 * stocks[i].percent_change);
        } else if (stocks[i].percent_change > 0) {
            printf("%s: $%.2f (%.2f%%)\t [ ALERT : PRICE INCREASED BY %.2f%% ]\n", stocks[i].name, stocks[i].price, stocks[i].percent_change, stocks[i].percent_change);
        } else {
            printf("%s: $%.2f (%.2f%%)\n", stocks[i].name, stocks[i].price, stocks[i].percent_change);
        }
    }
    printf("\n****************************************\n\n");
}

void update_stocks(Stock *stocks, int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        float rand_num = ((float) rand() / (float) RAND_MAX);
        float percent_change = rand_num * 10 - 5;
        stocks[i].price *= (1 + (percent_change / 100));
        stocks[i].percent_change = percent_change;
    }
    printf("[ ALERT : STOCKS HAVE BEEN UPDATED ]\n");
}

int main() {
    srand(time(NULL));
    Stock stocks[MAX_STOCKS] = {
        {"AAPL", 145.86, 0},
        {"GOOGL", 2663.22, 0},
        {"CSCO", 57.42, 0},
        {"BA", 234.00, 0},
        {"AMZN", 3543.62, 0},
        {"FB", 345.65, 0},
        {"NVDA", 198.13, 0},
        {"NFLX", 522.64, 0},
        {"TSLA", 685.70, 0},
        {"NOK", 6.48, 0}
    };
    while (1) {
        update_stocks(stocks, MAX_STOCKS);
        print_stocks(stocks, MAX_STOCKS);
        printf("Press any key to continue...\n");
        getchar();
    }
    return 0;
}