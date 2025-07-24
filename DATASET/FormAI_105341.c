//FormAI DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_DAY 7

int main() {
    srand(time(NULL)); // Seed the random number generator

    double stocks[MAX_STOCKS][MAX_DAY];
    char stock_names[MAX_STOCKS][20] = {"AAPL", "GOOGL", "AMZN", "FB", "TSLA", "MSFT", "NVDA", "ADBE", "NFLX", "PYPL"}; // Stock names
    double total_return[MAX_STOCKS] = {0};
    double weekly_return[MAX_STOCKS] = {0};

    // Generate stock prices for each day
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("%s stock prices for the week: \n", stock_names[i]);
        for (int j = 0; j < MAX_DAY; j++) {
            stocks[i][j] = (double) rand() / RAND_MAX * 100; // Random generated stock prices
            printf("%.2f ", stocks[i][j]);
        }
        printf("\n\n");
    }

    // Calculate total return for each stock
    for (int i = 0; i < MAX_STOCKS; i++) {
        for (int j = 0; j < MAX_DAY - 1; j++) {
            total_return[i] += (stocks[i][j + 1] - stocks[i][j]) / stocks[i][j]; // Calculates the total return using the formula (end stock price - start stock price) / start stock price
        }
    }

    printf("Total return for the week:\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("%s: %.2f%%\n", stock_names[i], total_return[i] * 100);
    }

    // Calculate weekly return for each stock
    for (int i = 0; i < MAX_STOCKS; i++) {
        weekly_return[i] = total_return[i] / (MAX_DAY - 1); // Calculates the weekly return using the formula total return / (number of days - 1)
    }

    printf("\nWeekly return for each stock:\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("%s: %.2f%%\n", stock_names[i], weekly_return[i] * 100);
    }

    return 0;
}