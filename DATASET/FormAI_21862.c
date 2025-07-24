//FormAI DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    printf("Welcome to the C Stock Market Tracker Program!\n\n");

    srand(time(NULL));
    int stock_prices[10];

    //Generating random stock prices
    printf("Today's Stock Prices: ");
    for(int i = 0; i < 10; i++){
        stock_prices[i] = rand() % 100 + 1; //Generating random integer between 1 and 100
        printf("%d ", stock_prices[i]);
    }

    //Calculating average stock price
    int total_price = 0;
    for(int i = 0; i < 10; i++){
        total_price += stock_prices[i];
    }
    float average_price = total_price / 10.0;

    printf("\n\nAverage Stock Price: $%.2f\n\n", average_price);

    //Identifying highest and lowest stock prices
    int highest_price = stock_prices[0];
    int lowest_price = stock_prices[0];
    for(int i = 1; i < 10; i++){
        if(stock_prices[i] > highest_price){
            highest_price = stock_prices[i];
        }
        if(stock_prices[i] < lowest_price){
            lowest_price = stock_prices[i];
        }
    }

    printf("Highest Stock Price: $%d\n", highest_price);
    printf("Lowest Stock Price: $%d\n", lowest_price);

    return 0;
}