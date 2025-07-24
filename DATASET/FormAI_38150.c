//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialising random seed
    
    int stock_price = 100; // starting stock price
    int volatility = 5; // initial volatility value
    int change; // stock price change
    
    printf("Welcome to the CyberStock market tracker!\n");
    printf("Initial stock price: $%d\n", stock_price);
    printf("Initial volatility: %d%%\n", volatility);
    
    for(int i = 1; i <= 50; i++) // tracking stock price changes for 50 rounds
    {
        change = (rand() % (volatility * 2 + 1)) - volatility; // generating random stock price change
        stock_price += change; // updating stock price
        
        if(stock_price < 0) // stock price cannot be negative
        {
            stock_price = 0;
        }
        
        printf("\nRound %d:\n", i);
        if(change > 0)
        {
            printf("Stock price increased by $%d\n", change);
        }
        else if(change < 0)
        {
            printf("Stock price decreased by $%d\n", -change);
        }
        else
        {
            printf("Stock price stayed the same\n");
        }
        
        volatility += (rand() % 3) - 1; // updating volatility
        
        if(volatility < 0) // volatility cannot be negative
        {
            volatility = 0;
        }
        else if(volatility > 10) // volatility cannot exceed 10%
        {
            volatility = 10;
        }
        
        printf("New stock price: $%d\n", stock_price);
        printf("New volatility: %d%%\n", volatility);
    }
    
    printf("\nThank you for using CyberStock market tracker!\n");
    
    return 0;
}