//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seeding random number generator
    
    char stock_names[5][20] = {"AAPL", "GOOG", "TSLA", "FB", "AMZN"}; // array of stock names
    double stock_prices[5] = {150.00, 1100.00, 800.00, 300.00, 1800.00}; // array of initial stock prices
    double stock_volume[5] = {5000000, 2000000, 3500000, 7500000, 1000000}; // array of initial stock volumes
    double stock_changes[5] = {0, 0, 0, 0, 0}; // array of initial stock changes
    
    printf("Welcome to the Verona Stock Market Tracker!\n");
    printf("Our top 5 stocks are:\n");
    for(int i=0; i<5; i++) {
        printf("%s\n", stock_names[i]);
    }
    printf("\n");
    
    for(int day=1; day<=5; day++) { // simulating 5 days of stock market activity
        
        printf("Day %d of the Verona Stock Market Tracker:\n\n", day);
        
        for(int i=0; i<5; i++) { // iterating through each stock
            
            double price_change = ((double) rand() / (RAND_MAX)) * 20 - 10; // generating random price change
            
            stock_prices[i] += price_change; // updating stock price
            if(stock_prices[i] < 0) { // preventing negative stock prices
                stock_prices[i] = 0;
            }
            
            double volume_change = ((double) rand() / (RAND_MAX)) * 1000000 - 500000; // generating random volume change
            
            stock_volume[i] += volume_change; // updating stock volume
            if(stock_volume[i] < 0) { // preventing negative stock volumes
                stock_volume[i] = 0;
            }
            
            stock_changes[i] = ((stock_prices[i] - 150.00) / 150.00) * 100; // calculating percentage change in stock price
        }
        
        printf("Today's Stock Prices:\n");
        for(int i=0; i<5; i++) {
            printf("%s: $%.2f (%.2f%%)\n", stock_names[i], stock_prices[i], stock_changes[i]);
        }
        printf("\n");
        
        printf("Today's Stock Volumes:\n");
        for(int i=0; i<5; i++) {
            printf("%s: %.0f\n", stock_names[i], stock_volume[i]);
        }
        printf("\n");
        
        printf("************************************************\n\n");
        
    }
    
    return 0;
}