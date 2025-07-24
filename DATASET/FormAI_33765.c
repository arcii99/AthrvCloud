//FormAI DATASET v1.0 Category: Stock market tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random stock price
float randomStockPrice() {
    return (float)(rand() % 100) + ((float)(rand() % 100) / 100);
}

int main() {
    srand(time(NULL)); // Initialize the random number generator
    
    // Declare variables
    float stockA_price = randomStockPrice();
    float stockB_price = randomStockPrice();
    float stockC_price = randomStockPrice();
    int day = 1;
    
    printf("Post-Apocalyptic Stock Market Tracker\n\n");
    printf("Day\tStock A\tStock B\tStock C\n");
    
    // Loop for 30 days
    while(day <= 30) {
        // Generate new stock prices
        stockA_price += ((rand() % 21) - 10) / 100.0;
        stockB_price += ((rand() % 21) - 10) / 100.0;
        stockC_price += ((rand() % 21) - 10) / 100.0;
        
        // Ensure stock prices do not become negative
        if(stockA_price < 0) stockA_price = 0;
        if(stockB_price < 0) stockB_price = 0;
        if(stockC_price < 0) stockC_price = 0;
        
        // Print stock prices for the day
        printf("%d\t%.2f\t%.2f\t%.2f\n", day, stockA_price, stockB_price, stockC_price);
        day++;
    }
    
    return 0;
}