//FormAI DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include <stdio.h>

// Macro to get the number of elements in an array
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

int main() {
    // Stock prices for the last 7 days
    float prices[] = {101.2, 105.5, 103.2, 101.8, 99.2, 97.5, 99.8};
    
    // Calculate the average price of the stock for the week
    float sum = 0;
    int i;
    for (i = 0; i < ARRAY_SIZE(prices); i++) {
        sum += prices[i];
    }
    float avg_price = sum / ARRAY_SIZE(prices);
    
    // Calculate the standard deviation of the stock prices for the week
    float sum_squared_diff = 0;
    for (i = 0; i < ARRAY_SIZE(prices); i++) {
        float diff = prices[i] - avg_price;
        sum_squared_diff += diff * diff;
    }
    float std_dev = sqrt(sum_squared_diff / ARRAY_SIZE(prices));
    
    // Print the results
    printf("The average price of the stock for the week is: %.2f\n", avg_price);
    printf("The standard deviation of the stock prices for the week is: %.2f\n", std_dev);
    
    return 0;
}