//FormAI DATASET v1.0 Category: Stock market tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main() {
    float prices[5] = {10.50, 15.25, 8.70, 14.00, 12.50};
    float changes[5] = {0.25, -0.50, 0.75, -0.30, 0.10};
    float percentChange[5];
    float total = 0, average, max = 0, min = prices[0], sumOfChanges = 0;
    int maxIndex, minIndex, i;
    
    for(i = 0; i < 5; i++) {
        total += prices[i];
        percentChange[i] = changes[i] / prices[i];
        sumOfChanges += changes[i];
        
        if(prices[i] > max) {
            max = prices[i];
            maxIndex = i;
        }
        
        if(prices[i] < min) {
            min = prices[i];
            minIndex = i;
        }
    }
    
    average = total / 5;
    
    printf("Stock Prices:\n");
    for(i = 0; i < 5; i++) {
        printf("$%.2f\t", prices[i]);
    }
    
    printf("\n\nStock Price Changes:\n");
    for(i = 0; i < 5; i++) {
        printf("%.2f\t", changes[i]);
    }
    
    printf("\n\nPercent Change of Each Stock:\n");
    for(i = 0; i < 5; i++) {
        printf("%.2f%%\t", percentChange[i] * 100);
    }
    
    printf("\n\nAverage Stock Price: $%.2f", average);
    printf("\nMaximum Stock Price: $%.2f (Stock %d)", max, maxIndex+1);
    printf("\nMinimum Stock Price: $%.2f (Stock %d)", min, minIndex+1);
    printf("\nTotal Change in Stock Prices: %.2f", sumOfChanges);
    
    return 0;
}