//FormAI DATASET v1.0 Category: Stock market tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define the maximum stock symbols to track
#define MAX_STOCK 100

//define a stock structure to track stock data
typedef struct {
    char symbol[10];
    float price;
} Stock;

//function to retrieve stock data and update prices
int getStockData(Stock *stockList, int numStock) {
    //simulate getting new stock data from external source
    //for demo purposes, we will randomly update current prices
    for(int i = 0; i < numStock; i++) {
        float change = (float)(rand() % 2001 - 1000) / 100;
        stockList[i].price += change;
    }
    return 0;
}

//function to display current stock prices
void displayStockPrices(Stock *stockList, int numStock) {
    printf("\nCurrent Stock Prices:\n");
    for(int i = 0; i < numStock; i++) {
        printf("%s: $%.2f\n", stockList[i].symbol, stockList[i].price);
    }
}

//main function to track stocks
int main() {
    //initialize variables
    int numStock = 0;
    Stock stockList[MAX_STOCK];
    char userInput[10];
    int choice = 0;

    //set up initial stock data
    strcpy(stockList[0].symbol, "AAPL");
    stockList[0].price = 154.12;

    strcpy(stockList[1].symbol, "GOOG");
    stockList[1].price = 1085.15;

    numStock = 2;

    //display initial stock prices
    displayStockPrices(stockList, numStock);

    //main loop to track stocks
    while(choice != 3) {
        //get user choice
        printf("\n\nChoose an option:\n");
        printf("1. Add a new stock\n");
        printf("2. Update stock prices\n");
        printf("3. Quit\n");
        printf("\nChoice: ");
        fgets(userInput, 10, stdin);
        choice = atoi(userInput);

        //handle user choice
        switch(choice) {
            case 1:
                //add a new stock
                if(numStock < MAX_STOCK) {
                    printf("\nEnter the stock symbol: ");
                    fgets(userInput, 10, stdin);
                    strcpy(stockList[numStock].symbol, userInput);

                    printf("Enter the current price: ");
                    fgets(userInput, 10, stdin);
                    stockList[numStock].price = atof(userInput);

                    numStock++;
                    printf("\nNew stock added!\n");
                } else {
                    printf("\nMax number of stocks reached.\n");
                }
                break;
            case 2:
                //update stock prices
                getStockData(stockList, numStock);
                displayStockPrices(stockList, numStock);
                break;
            case 3:
                //quit program
                printf("\nGoodbye!\n");
                break;
            default:
                //invalid choice
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}