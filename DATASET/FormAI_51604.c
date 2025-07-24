//FormAI DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    char stocks[10][10] = {"AAPL", "GOOGL", "FB", "AMZN", "NFLX", "MSFT", "TSLA", "NVDA", "AMD", "INTC"};
    
    int stock_prices[10];
    
    for(int i=0; i<10; i++)
    {
        stock_prices[i] = rand() % 200 + 50;
    }
    
    printf("*********************************************\n");
    printf("***        Welcome to Stock Tracker        ***\n");
    printf("*********************************************\n");
    printf("\n");
    
    printf("Today's Stock Prices:\n");
    printf("---------------------------------------------\n");
    for(int i=0; i<10; i++)
    {
        printf("%s : $%d\n", stocks[i], stock_prices[i]);
    }
    printf("\n");
    
    int total_value = 0;
    for(int i=0; i<10; i++)
    {
        total_value += stock_prices[i];
    }
    
    printf("Your total investment value for today is: $%d\n", total_value);
    printf("\n");
    
    // Simulating stock market changes
    
    int day_change[10];
    
    for(int i=0; i<10; i++)
    {
        day_change[i] = rand() % 50 - 25;
    }
    
    printf("Today's Stock Market Changes:\n");
    printf("---------------------------------------------\n");
    for(int i=0; i<10; i++)
    {
        printf("%s : %d%%\n", stocks[i], day_change[i]);
    }
    printf("\n");
    
    for(int i=0; i<10; i++)
    {
        double percent_change = day_change[i] / 100.0;
        stock_prices[i] += (int) (percent_change * stock_prices[i]); // Rounding down to the nearest integer
    }
    
    printf("New Stock Prices:\n");
    printf("---------------------------------------------\n");
    for(int i=0; i<10; i++)
    {
        printf("%s : $%d\n", stocks[i], stock_prices[i]);
    }
    printf("\n");
    
    int new_total_value = 0;
    for(int i=0; i<10; i++)
    {
        new_total_value += stock_prices[i];
    }
    
    if(new_total_value > total_value)
    {
        printf("Congratulations! You have made a profit of $%d today!\n", new_total_value - total_value);
    }
    else if(new_total_value < total_value)
    {
        printf("Oops! You have incurred a loss of $%d today!\n", total_value - new_total_value);
    }
    else
    {
        printf("Your investment value remained unchanged today.\n");
    } 
    
    return 0;
}