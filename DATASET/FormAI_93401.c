//FormAI DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define STOCK_COUNT 5   //Define the number of stocks to track
#define MAX_PRICE 100   //Define the maximum value for stock prices

//Function to generate random stock price
int generateRandomPrice(){
    return rand() % MAX_PRICE + 1;
}

int main(){
    srand(time(NULL)); //Seed the random generator with current time

    char stockNames[STOCK_COUNT][10] = {"apple", "microsoft", "google", "amazon", "facebook"}; //Define the names of stocks to track
    int stockPrices[STOCK_COUNT];   //Array to store the present stock prices
    int prevStockPrices[STOCK_COUNT];  //Array to store the previous stock prices

    //Initialize the stock prices
    for(int i = 0; i < STOCK_COUNT; i++){
        stockPrices[i] = generateRandomPrice();
        prevStockPrices[i] = stockPrices[i];
    }

    printf("======== Current Stock Prices ========\n");
    printf("StockName\tPrice\n");

    //Printing the initial stock prices
    for(int i = 0; i < STOCK_COUNT; i++){
        printf("%s\t\t %d\n", stockNames[i], stockPrices[i]);
    }

    //Loop to track the stock prices every 5 seconds
    while(1){
        printf("\nSleeping for 5 seconds...\n");
        sleep(5); //Sleep for 5 seconds

        printf("======== Updated Stock Prices ========\n");
        printf("StockName\tPrice\tIncrease/Decrease\n");

        //Loop to update and print stock prices
        for(int i = 0; i < STOCK_COUNT; i++){
            prevStockPrices[i] = stockPrices[i];
            stockPrices[i] = generateRandomPrice();

            //Printing the stock price with increase/decrease
            if(stockPrices[i] > prevStockPrices[i]){
                printf("%s\t\t %d\t+\n", stockNames[i], stockPrices[i]);
            }
            else if(stockPrices[i] < prevStockPrices[i]){
                printf("%s\t\t %d\t-\n", stockNames[i], stockPrices[i]);
            }
            else{
                printf("%s\t\t %d\t-\n", stockNames[i], stockPrices[i]);
            }
        }
    }

    return 0;
}