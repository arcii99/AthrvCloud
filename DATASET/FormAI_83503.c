//FormAI DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20

// Define a structure to represent a stock
typedef struct {
    char name[MAX_NAME_LENGTH];
    double current_price;
    double previous_price;
} Stock;

// Function to update the current price of a stock randomly
void update_price(Stock* stock) {
    // Generate a random value between -5 and 5
    double change = (rand() % 11) - 5;
    // Update the current price
    stock->previous_price = stock->current_price;
    stock->current_price += change;
}

// Function to print the details of a stock
void print_stock(Stock stock) {
    printf("%s - Current Price: $%.2f, Previous Price: $%.2f\n", stock.name, stock.current_price, stock.previous_price);
}

int main() {
    // Declare an array of stocks
    Stock stocks[MAX_STOCKS];
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the stocks
    strcpy(stocks[0].name, "AAPL");
    stocks[0].current_price = 150.00;
    stocks[0].previous_price = 150.00;
    strcpy(stocks[1].name, "GOOG");
    stocks[1].current_price = 1000.00;
    stocks[1].previous_price = 1000.00;
    strcpy(stocks[2].name, "FB");
    stocks[2].current_price = 200.00;
    stocks[2].previous_price = 200.00;
    strcpy(stocks[3].name, "AMZN");
    stocks[3].current_price = 3000.00;
    stocks[3].previous_price = 3000.00;
    strcpy(stocks[4].name, "TSLA");
    stocks[4].current_price = 600.00;
    stocks[4].previous_price = 600.00;
    strcpy(stocks[5].name, "MSFT");
    stocks[5].current_price = 300.00;
    stocks[5].previous_price = 300.00;
    strcpy(stocks[6].name, "SBUX");
    stocks[6].current_price = 110.00;
    stocks[6].previous_price = 110.00;
    strcpy(stocks[7].name, "NFLX");
    stocks[7].current_price = 500.00;
    stocks[7].previous_price = 500.00;
    strcpy(stocks[8].name, "NVDA");
    stocks[8].current_price = 700.00;
    stocks[8].previous_price = 700.00;
    strcpy(stocks[9].name, "DIS");
    stocks[9].current_price = 150.00;
    stocks[9].previous_price = 150.00;
    
    // Continuously update the prices and print the details of the stocks
    while (1) {
        for (int i = 0; i < MAX_STOCKS; i++) {
            update_price(&stocks[i]);
            print_stock(stocks[i]);
        }
        printf("\n");
        // Pause for 1 second
        sleep(1);
    }
    
    return 0;
}