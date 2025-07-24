//FormAI DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random stock prices
double generateStockPrice(){
    double price = rand() % 10000 + 1; // Generating price between $1 and $10,000
    price /= 100; // Dividing by 100 to get cents
    return price;
}

// Function to calculate change in stock price
double calculateChange(double currentPrice, double previousPrice){
    double change = (currentPrice - previousPrice) / previousPrice * 100; // Calculating percentage change
    return change;
}

int main(){
    srand(time(NULL)); // Seed for random number generator
    int numStocks = 10; // Number of stocks to track
    double currentPrices[numStocks]; // Array to store current prices of stocks
    double previousPrices[numStocks]; // Array to store previous prices of stocks

    // Initializing current and previous prices
    for(int i=0;i<numStocks;i++){
        currentPrices[i] = generateStockPrice();
        previousPrices[i] = currentPrices[i];
    }

    // Loop to track the stock prices
    while(1){
        // Generating new prices for each stock
        for(int i=0;i<numStocks;i++){
            double change = generateStockPrice() / 10; // Maximum change is 10% of current price
            if(rand() % 2 == 1){ // Randomly deciding to increase or decrease the price
                currentPrices[i] += change;
            }else{
                currentPrices[i] -= change;
            }
        }

        // Printing the changes in stock prices
        printf("Stock\tCurrent\t\tChange\n");
        for(int i=0;i<numStocks;i++){
            double change = calculateChange(currentPrices[i], previousPrices[i]);
            printf("%d\t$%.2lf\t\t%.2lf%%\n", i+1, currentPrices[i], change);
            previousPrices[i] = currentPrices[i]; // Updating previous price
        }
        printf("\n");

        // Delaying the program for 2 seconds
        for(int i=0;i<200000000;i++);
    }

    return 0;
}