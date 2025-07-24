//FormAI DATASET v1.0 Category: Stock market tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int stock_price = 100;
    int ticker_count = 0;
    float portfolio_value = 0.0;
    float cash_balance = 10000.0;
    float net_worth = cash_balance + portfolio_value;
    srand(time(NULL));
    
    printf("Welcome to the Stock Market Tracker!");
    printf("\n\nStarting cash balance: $%.2f\n", cash_balance);
    printf("Starting portfolio value: $%.2f\n", portfolio_value);
    printf("Starting net worth: $%.2f\n\n", net_worth);
    
    for (int day = 1; day <= 30; day++)
    {
        printf("Day %d Ticker Report:\n", day);
        printf("Current stock price: $%d\n", stock_price);
        
        int ticker = rand() % 2; // generate a random 0 or 1
        
        if (ticker == 0)
        {
            printf("Ticker: Sell\n");
            int shares_sold = rand() % 100 + 1;
            float sale_price = shares_sold * stock_price * 0.95; // 5% commission
            printf("Sold %d shares for $%.2f\n", shares_sold, sale_price);
            portfolio_value -= sale_price;
            cash_balance += sale_price;
            net_worth = cash_balance + portfolio_value;
            ticker_count++;
        }
        else
        {
            printf("Ticker: Buy\n");
            int shares_bought = rand() % 100 + 1;
            float buy_price = shares_bought * stock_price * 1.05; // 5% markup
            printf("Bought %d shares for $%.2f\n", shares_bought, buy_price);
            portfolio_value += buy_price;
            cash_balance -= buy_price;
            net_worth = cash_balance + portfolio_value;
            ticker_count++;
        }
        
        printf("End of Day %d Report:\n", day);
        printf("Current cash balance: $%.2f\n", cash_balance);
        printf("Current portfolio value: $%.2f\n", portfolio_value);
        printf("Current net worth: $%.2f\n\n", net_worth);
        
        stock_price += rand() % 21 - 10; // randomly change stock price by +/- $10
    }
    
    printf("*** End of 30-day Report ***\n");
    printf("Total Ticker Count: %d\n", ticker_count);
    printf("Final Cash Balance: $%.2f\n", cash_balance);
    printf("Final Portfolio Value: $%.2f\n", portfolio_value);
    printf("Final Net Worth: $%.2f\n", net_worth);
    
    return 0;
}