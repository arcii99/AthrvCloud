//FormAI DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // initialize random seed
    float c_stock_prices[10];
    int i;
    for (i = 0; i < 10; i++) {
        c_stock_prices[i] = (float) rand() / (float) (RAND_MAX/1000);  // generate random stock prices between 0 and 1000
    }
    float max_price = c_stock_prices[0];  // initialize max price to first stock price
    float min_price = c_stock_prices[0];  // initialize min price to first stock price
    float total_price = 0;  // initialize variable to hold total of all stock prices
    for (i = 0; i < 10; i++) {
        if (c_stock_prices[i] > max_price) {  // check if current stock price is greater than max price
            max_price = c_stock_prices[i];  // if so, update max price
        }
        if (c_stock_prices[i] < min_price) {  // check if current stock price is less than min price
            min_price = c_stock_prices[i];  // if so, update min price
        }
        total_price += c_stock_prices[i];  // add current stock price to total price
    }
    float avg_price = total_price / 10;  // calculate average price
    printf("C stock prices for the day:\n");
    for (i = 0; i < 10; i++) {
        printf("$%.2f\n", c_stock_prices[i]);  // print out each stock price formatted as US dollars
    }
    printf("Highest stock price: $%.2f\n", max_price);  // print out highest stock price formatted as US dollars
    printf("Lowest stock price: $%.2f\n", min_price);  // print out lowest stock price formatted as US dollars
    printf("Average stock price: $%.2f\n", avg_price);  // print out average stock price formatted as US dollars
    return 0;
}