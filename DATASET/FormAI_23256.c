//FormAI DATASET v1.0 Category: Stock market tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Array of stock prices from previous days
    float stockPrices[] = {100.0, 120.5, 110.2, 95.0, 105.8, 98.3, 101.5, 115.0, 120.5, 125.2, 130.0, 140.3, 135.7, 128.2, 130.5};
    
    // Random number generator for simulating daily fluctuations
    srand(time(NULL));
    
    // Loop through each day
    for(int day = 16; day <= 30; day++) {
        // Simulate daily fluctuation by generating random number between -5% and 5% of previous day's price
        float fluctuation = ((float) rand() / RAND_MAX)*10.0 - 5.0;
        float price = stockPrices[day-2]*(1 + fluctuation/100.0);
        stockPrices[day-1] = price;
        
        // Calculate moving average for past 10 days
        float sum = 0.0;
        for(int i = day-10; i < day; i++) {
            sum += stockPrices[i];
        }
        float movingAvg = sum/10.0;
        
        // Print stock price, fluctuation, and moving average for the day
        printf("Day %d | Price: %.2f | Fluctuation: %.2f%% | Moving Average: %.2f\n", day, price, fluctuation, movingAvg);
    }
    
    return 0;
}