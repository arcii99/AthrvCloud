//FormAI DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>

int main() {
    int stock_prices[] = {50, 70, 80, 90, 100, 120, 150, 160, 170, 190, 200};   // array of stock prices
    int n = sizeof(stock_prices) / sizeof(stock_prices[0]);    // calculating the size of the array
    int curr_min = stock_prices[0];     // initializing the current minimum as the first element
    
    printf("Stock Market Tracker\n\n");
    printf("Date\t\tPrice\n");
    
    for(int i=0; i<n; i++) {
        if(stock_prices[i] < curr_min) {      // if current element is less than current minimum
            curr_min = stock_prices[i];       // update the current minimum
        }
        printf("%d-%d-%d\t$%d\n", 1, i+1, 2022, stock_prices[i]);     // print the date and price of the stock
        printf("Current minimum price: $%d\n", curr_min);     // print the current minimum price
    }
    return 0;
}