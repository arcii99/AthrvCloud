//FormAI DATASET v1.0 Category: Stock market tracker ; Style: calm
#include<stdio.h>

int main() {

    // array of stock prices
    float stocks[5] = { 25.15, 21.02, 30.27, 12.45, 5.65 };

    // loop through each stock and print current value
    for(int i = 0; i < 5; i++) {
        printf("Stock %d: $%.2f\n", i+1, stocks[i]);
    }

    // calculate and print change in value from previous day
    printf("\nChange in value from previous day:\n");
    for(int i = 0; i < 5; i++) {
        float change = stocks[i] * 0.02; // assume 2% change
        printf("Stock %d: $%.2f\n", i+1, change);
    }

    return 0;
}