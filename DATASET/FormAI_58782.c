//FormAI DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define NUM_STOCKS 10

int main() {

    int i;

    // stock prices for 10 companies
    float prices[NUM_STOCKS] = {100.50, 67.25, 43.75, 80.00, 112.15, 55.80, 92.45, 135.70, 76.90, 110.25};

    // calculate mean of stock prices
    float sum = 0;
    for (i = 0; i < NUM_STOCKS; i++) {
        sum += prices[i];
    }
    float mean_price = sum / NUM_STOCKS;

    // calculate standard deviation of stock prices
    float std_dev = 0;
    for (i = 0; i < NUM_STOCKS; i++) {
        std_dev += pow(prices[i] - mean_price, 2);
    }
    std_dev = sqrt(std_dev / NUM_STOCKS);

    // calculate relative standard deviation of stock prices
    float rel_std_dev = (std_dev / mean_price) * 100;

    // print results
    printf("Stock prices:\n");
    for (i = 0; i < NUM_STOCKS; i++) {
        printf("%.2f ", prices[i]);
    }
    printf("\n\nMean price: %.2f\n", mean_price);
    printf("Standard deviation: %.2f\n", std_dev);
    printf("Relative standard deviation: %.2f%%\n", rel_std_dev);

    return 0;
}