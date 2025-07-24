//FormAI DATASET v1.0 Category: Stock market tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold stock information
typedef struct {
    char symbol[10];
    double price;
    int volume;
} Stock;

// Define a function to calculate the total value of a stock
double calculateValue(Stock stock) {
    return stock.price * stock.volume;
}

int main() {
    // Define an array of stock objects
    Stock stocks[5];
    
    // Populate the array with some sample stock data
    strcpy(stocks[0].symbol, "AAPL");
    stocks[0].price = 144.09;
    stocks[0].volume = 1000;
    
    strcpy(stocks[1].symbol, "MSFT");
    stocks[1].price = 259.43;
    stocks[1].volume = 500;
    
    strcpy(stocks[2].symbol, "GOOG");
    stocks[2].price = 2786.20;
    stocks[2].volume = 200;
    
    strcpy(stocks[3].symbol, "AMZN");
    stocks[3].price = 3626.39;
    stocks[3].volume = 300;
    
    strcpy(stocks[4].symbol, "TSLA");
    stocks[4].price = 709.67;
    stocks[4].volume = 150;
    
    // Print out the current value of each stock
    for (int i = 0; i < 5; i++) {
        printf("%s: $%.2lf (%d shares) = $%.2lf\n", stocks[i].symbol, stocks[i].price, stocks[i].volume, calculateValue(stocks[i]));
    }
    
    // Adjust the volume of a stock
    strcpy(stocks[2].symbol, "GOOGL");
    stocks[2].volume = 300;
    
    // Print out the updated value of the stock
    printf("%s: $%.2lf (%d shares) = $%.2lf\n", stocks[2].symbol, stocks[2].price, stocks[2].volume, calculateValue(stocks[2]));
    
    // Exit the program
    return 0;
}