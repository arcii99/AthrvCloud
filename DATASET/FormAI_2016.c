//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multivariable
#include <stdio.h>

int main () {

    // Initialize variables for stock prices and number of shares
    float stock1_price = 10.5;
    int stock1_shares = 200;
    float stock2_price = 25.8;
    int stock2_shares = 150;
    
    // Calculate the initial value of each stock and print to console
    float stock1_value = stock1_price * stock1_shares;
    float stock2_value = stock2_price * stock2_shares;
    printf("Initial Stock Values:\nStock 1: $%.2f\nStock 2: $%.2f\n", stock1_value, stock2_value);

    // Simulate stock price changes
    float stock1_change = 0.1;
    float stock2_change = -0.05;

    // Update stock prices and calculate new values
    stock1_price += stock1_change;
    stock2_price += stock2_change;
    float new_stock1_value = stock1_price * stock1_shares;
    float new_stock2_value = stock2_price * stock2_shares;

    // Print updated stock prices and values to console
    printf("Updated Stock Prices:\nStock 1: $%.2f\nStock 2: $%.2f\n", stock1_price, stock2_price);
    printf("New Stock Values:\nStock 1: $%.2f\nStock 2: $%.2f\n", new_stock1_value, new_stock2_value);

    // Calculate total portfolio value
    float portfolio_value = new_stock1_value + new_stock2_value;
    printf("Total Portfolio Value: $%.2f\n", portfolio_value);

    return 0;
}