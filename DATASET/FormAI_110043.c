//FormAI DATASET v1.0 Category: Stock market tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to generate a random stock price
float generateStockPrice() {
    float price = (float) (rand() % 100 + 1); // generating a random price between 1 and 100
    price += (float) (rand() % 100) / 100; // generating a random decimal value for cents
    return price;
}

// function to update the stock prices and display them
void updateStockPrices(float *stockPrices, int numStocks) {
    printf("\nCurrent Stock Prices: \n");
    for (int i = 0; i < numStocks; i++) {
        float newPrice = generateStockPrice(); // generating a new random price for the stock
        printf("Stock %d: $%.2f -> $%.2f\n", i+1, stockPrices[i], newPrice); // displaying the new and old prices
        stockPrices[i] = newPrice; // updating the stock prices array with the new value
    }
}

int main() {
    srand(time(NULL)); // initializing the random seed
    int numStocks; // variable to store the number of stocks
    printf("Welcome to the Artistic Stock Market Tracker Program!\n\n");
    printf("Please enter the number of stocks you want to track: ");
    scanf("%d", &numStocks); // getting the number of stocks from the user
    float stockPrices[numStocks]; // creating an array to store the stock prices
    printf("\nEnter the initial stock prices below:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("Stock %d: $", i+1);
        scanf("%f", &stockPrices[i]); // getting the initial stock prices from the user
    }
    while (1) { // running an infinite loop to update the stock prices
        updateStockPrices(stockPrices, numStocks); // calling the function to update the stock prices
        printf("\nPress 1 to update stock prices again or 0 to exit: ");
        int choice; // variable to store the user's choice
        scanf("%d", &choice); // getting the user's choice
        if (choice == 0) break; // breaking the loop if the user chooses to exit
    }
    printf("\nThank you for using the Artistic Stock Market Tracker Program!\n");
    return 0;
}