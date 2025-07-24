//FormAI DATASET v1.0 Category: Stock market tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numOfStocks, stockPrice;
    int totalValue = 0;
    
    printf("Welcome to the Stock Market Tracker %c%c%c\n", ':', ')', '\n');
    printf("Please enter the number of stocks you want to track: ");
    scanf("%d", &numOfStocks);
    
    if(numOfStocks > 0)
    {
        for(int i = 1; i <= numOfStocks; i++)
        {
            printf("Enter the current price for Stock %d:", i);
            scanf("%d", &stockPrice);
            totalValue += stockPrice;
        }
        
        printf("\nYou are currently tracking %d stocks with a total value of %d.\n", numOfStocks, totalValue);
        printf("Thank you for using the Stock Market Tracker!\n");
    }
    else 
    {
        printf("Invalid input! Please enter a positive number of stocks.\n");
    }
    
    return 0;
}