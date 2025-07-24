//FormAI DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int stock_price = 100; // starting stock price
    srand(time(0)); // setting up random seed

    printf("Welcome to the C Stock Market Tracker!\n");
    printf("Starting stock price: %d\n", stock_price);

    for(int i = 1; i <= 5; i++){
        
        int random_number = rand() % 21 - 10; // random number between -10 and 10
        int prev_stock_price = stock_price;
        stock_price += random_number;
        
        printf("Day %d: Stock price ", i);

        if(stock_price > prev_stock_price){
            printf("increased ");
        } else if(stock_price < prev_stock_price){
            printf("decreased ");
        } else {
            printf("stayed the same ");
        }

        printf("by %d points to %d\n", abs(random_number), stock_price);
    }

    printf("Thank you for using the C Stock Market Tracker!\n");

    return 0;
}