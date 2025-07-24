//FormAI DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>

// Function to display stock data
void display_data(char* stock, float price){
    printf("%s's current price is $%.2f.\n", stock, price);
}

// Function to increase stock price by a certain percentage
float increase_price(float price, float percent){
    return price + (price * percent / 100);
}

// Function to decrease stock price by a certain percentage
float decrease_price(float price, float percent){
    return price - (price * percent / 100);
}

// Main function
int main(){
    // Declare variables for stock data
    char* stock = "Apple Inc.";
    float price = 148.48;
    
    // Display initial stock data
    display_data(stock, price);
    
    // Simulate stock price changes
    price = increase_price(price, 5);
    display_data(stock, price);
    
    price = decrease_price(price, 2);
    display_data(stock, price);
    
    price = decrease_price(price, 10);
    display_data(stock, price);
    
    price = increase_price(price, 15);
    display_data(stock, price);

    return 0;
}