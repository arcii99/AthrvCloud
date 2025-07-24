//FormAI DATASET v1.0 Category: Stock market tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); //seed for random number generator
    float stockPrices[5] = {50.00, 100.00, 150.00, 200.00, 250.00}; //initial stock prices
    int shifts[5] = {-10, -5, 0, 5, 10}; //potential value shifts
    int days = 1;
    float overallChange = 0.0;
    printf("Welcome to the Shape Shifting Stock Tracker!\n\n");
    printf("Starting Prices:\n");
    for(int i=0; i<5;i++){
        printf("Stock %d: $%.2f\n", i+1, stockPrices[i]);
    }
    printf("\n");
    while(days<=30){
        printf("Day %d:\n", days);
        float dailyChange = 0.0;
        for(int i=0; i<5;i++){
            int shiftIndex = rand()%5; //get random shift index
            stockPrices[i] = stockPrices[i] + shifts[shiftIndex]; //apply shift to stock price
            if(stockPrices[i]<0){ //ensure minimum price can't be negative
                stockPrices[i]=0.1;
            }
            printf("Stock %d: $%.2f (%+d)\n", i+1, stockPrices[i], shifts[shiftIndex]);
            dailyChange += shifts[shiftIndex];
        }
        printf("Daily Overall Change: $%.2f\n\n", dailyChange);
        overallChange += dailyChange;
        days++;
    }
    printf("\n");
    if(overallChange<0){
        printf("Over the past 30 days, there has been a decrease of $%.2f in the overall stock price.\n", -overallChange);
    }else{
        printf("Over the past 30 days, there has been an increase of $%.2f in the overall stock price.\n", overallChange);
    }
    return 0;
}