//FormAI DATASET v1.0 Category: Stock market tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int stock_price = 100; //Initial stock price
    int demand = 500; //Initial demand
    int supply = 400; //Initial supply
    int day = 1; //Initial day
    
    printf("Welcome to the Stock Market Tracker!\n");
    printf("Day %d: Stock price is %d\n", day, stock_price);
    
    while (day <= 365) //Loop for a year
    {
        int change = rand()%21 - 10; //Random change in demand/supply
        
        if (change > 0) //Increase in demand
        {
            printf("Day %d: Demand has increased by %d\n", day, change);
            demand += change;
        }
        else if (change < 0) //Decrease in supply
        {
            printf("Day %d: Supply has decreased by %d\n", day, abs(change));
            supply -= abs(change);
        }
        else //No change
        {
            printf("Day %d: No change in demand/supply\n", day);
        }
        
        //Calculate new stock price based on demand and supply
        stock_price = 1000*(demand-supply)/(demand+supply);
        
        printf("Day %d: Stock price is %d\n", day, stock_price);
        
        day++; //Move to the next day
    }
    
    printf("Thank you for using the Stock Market Tracker!\n");
    
    return 0;
}