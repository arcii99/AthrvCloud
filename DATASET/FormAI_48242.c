//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    float price[] = {10.00, 12.50, 11.25, 13.75, 14.00, 15.00};
    float sum = 0, avg;
    int i;

    printf("Stock Prices for the past 6 days:\n");
    for(i = 0; i < 6; i++) {
        printf("%.2f ", price[i]);
        sum += price[i];
    }
    avg = sum / 6;
    printf("\n\nAverage stock price for the past 6 days: %.2f\n", avg);

    return 0;
}