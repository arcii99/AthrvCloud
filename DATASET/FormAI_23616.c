//FormAI DATASET v1.0 Category: Stock market tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the FunStock market tracker! Sit back and watch your money rise and fall like a rollercoaster!\n");
    
    int stocksOwned = 0;
    double initialInvestment = 0.0;
    
    printf("How many stocks do you currently own? ");
    scanf("%d", &stocksOwned);
    printf("What was your initial investment? ");
    scanf("%lf", &initialInvestment);
    
    double stockPrice = 130.0;
    double moneyInvested = initialInvestment + (double)stocksOwned * stockPrice;
    int randomVar = rand() % 100 + 1; // Random variable to simulate stock fluctuations
    
    printf("\nInitial investment: $%.2lf\nCurrent market value of stocks: $%.2lf\nNet gain/loss: $%.2lf", 
           initialInvestment, moneyInvested + (randomVar-50)/100.0*moneyInvested, (randomVar-50)/100.0*moneyInvested);
           
    printf("\n\nLet's check on your stocks once every second! Press Ctrl+C to exit.\n");
    
    while(1){
        randomVar = rand() % 100 + 1;
        printf("\nMarket value: $%.2lf", stockPrice + (randomVar-50)/100.0*stockPrice);
        sleep(1);
    }
    
    return 0;
}