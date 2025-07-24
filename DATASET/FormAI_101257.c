//FormAI DATASET v1.0 Category: Stock market tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COMPANY_COUNT 5
#define DAY_COUNT 5

int main() {

    // Random seed initialization for generating prices
    srand(time(NULL));

    // Create company names and stock prices arrays
    char* companies[COMPANY_COUNT] = {"Apple", "Microsoft", "Amazon", "Tesla", "Facebook"};
    float stockPrices[COMPANY_COUNT][DAY_COUNT];

    // Generate initial stock prices for each company
    printf("Initial stock prices:\n");
    for (int i = 0; i < COMPANY_COUNT; i++) {
        printf("%s: ", companies[i]);
        for (int j = 0; j < DAY_COUNT; j++) {
            stockPrices[i][j] = ((float) (rand() % 2000 + 1)) / 10.0f;
            printf("%.2f ", stockPrices[i][j]);
        }
        printf("\n");
    }

    // Daily fluctuations
    float fluctuations[COMPANY_COUNT][DAY_COUNT];
    for (int i = 0; i < COMPANY_COUNT; i++) {
        printf("\n%s fluctuations:\n", companies[i]);
        for (int j = 0; j < DAY_COUNT; j++) {
            fluctuations[i][j] = ((float) (rand() % 200 + 1)) / 100.0f - 1.0f;
            printf("%.2f ", fluctuations[i][j]);
        }
    }

    // Calculate closing prices for each day
    printf("\n\nClosing prices:\n");
    float closingPrices[DAY_COUNT];
    for (int i = 0; i < DAY_COUNT; i++) {
        float total = 0.0f;
        for (int j = 0; j < COMPANY_COUNT; j++) {
            total += stockPrices[j][i] + (stockPrices[j][i] * fluctuations[j][i]);
        }
        closingPrices[i] = total / COMPANY_COUNT;
        printf("Day %d: %.2f\n", i+1, closingPrices[i]);
    }

    // Calculate overall gains or losses per company
    printf("\nGains or losses per company:\n");
    float gainsLosses[COMPANY_COUNT];
    for (int i = 0; i < COMPANY_COUNT; i++) {
        float totalGainLoss = 0.0f;
        for (int j = 0; j < DAY_COUNT; j++) {
            totalGainLoss += (stockPrices[i][j] + (stockPrices[i][j] * fluctuations[i][j])) - stockPrices[i][0];
        }
        gainsLosses[i] = totalGainLoss;
        if (totalGainLoss >= 0) {
            printf("%s: +%.2f\n", companies[i], totalGainLoss);
        } else {
            printf("%s: %.2f\n", companies[i], totalGainLoss);
        }
    }

    return 0;
}