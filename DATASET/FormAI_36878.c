//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_stocks;
    printf("Enter the number of stocks in your portfolio: ");
    scanf("%d", &num_stocks);
    
    //Defining the structure to hold stock information
    struct stock {
        char ticker[10];
        float price;
        int quantity;
        float value;
    };
    struct stock portfolio[num_stocks];
    
    //Getting stock information from the user
    for(int i=0; i<num_stocks; i++) {
        printf("Enter the ticker symbol of stock %d: ", i+1);
        scanf("%s", portfolio[i].ticker);
        
        printf("Enter the price per share of stock %d: ", i+1);
        scanf("%f", &portfolio[i].price);
        
        printf("Enter the number of shares of stock %d: ", i+1);
        scanf("%d", &portfolio[i].quantity);
        
        portfolio[i].value = portfolio[i].price * portfolio[i].quantity;
    }
    
    //Printing the portfolio summary
    printf("\n\nPortfolio Summary: \n\n");
    printf("Ticker\tPrice\tQuantity\tValue\n");
    float total_value = 0;
    for(int i=0; i<num_stocks; i++) {
        printf("%s\t%.2f\t%d\t\t%.2f\n", portfolio[i].ticker, portfolio[i].price, portfolio[i].quantity, portfolio[i].value);
        total_value += portfolio[i].value;
    }
    printf("\nTotal Portfolio Value: $%.2f\n", total_value);
    
    //Calculating and printing the average stock price
    float average_price = 0;
    for(int i=0; i<num_stocks; i++) {
        average_price += portfolio[i].price;
    }
    average_price /= num_stocks;
    printf("\nAverage Stock Price: $%.2f\n", average_price);
    
    //Finding and printing the stock with highest value
    struct stock max_stock = portfolio[0];
    for(int i=1; i<num_stocks; i++) {
        if(portfolio[i].value > max_stock.value) {
            max_stock = portfolio[i];
        }
    }
    printf("\nStock with highest value: %s\n", max_stock.ticker);
    
    return 0;
}