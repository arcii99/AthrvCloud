//FormAI DATASET v1.0 Category: Stock market tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL)); //seed the random number generator with current time

    float c_stock_price = 100.00; //initialize the current stock price to 100.00
    float stock_value = 10000.00; //initialize the stock value to 10,000.00
    float num_shares = stock_value / c_stock_price; //calculate the number of shares
    int i;

    printf("Initial stock price: $%.2f\n", c_stock_price);
    printf("Your stock value: $%.2f\n", stock_value);
    printf("Number of shares owned: %.2f\n", num_shares);

    //simulate stock price changes for 50 days
    for(i=1; i<=50; i++)
    {
        int change = rand() % 21 - 10; //generate a random number between -10 and 10
        float percentage_change = change / 100.00; //convert the change to a percentage
        float price_change = c_stock_price * percentage_change; //calculate the actual price change
        c_stock_price += price_change; //update the current stock price
        stock_value = c_stock_price * num_shares; //calculate the new stock value

        if(price_change >= 0) {
            printf("Day %d: Stock price increased by $%.2f\n", i, price_change);
        } else {
            printf("Day %d: Stock price decreased by $%.2f\n", i, -price_change);
        }

        printf("Current stock price: $%.2f\n", c_stock_price);
        printf("Your stock value: $%.2f\n", stock_value);
        printf("Number of shares owned: %.2f\n", num_shares);
        printf("\n");
    }

    return 0; //end the program
}