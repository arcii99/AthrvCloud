//FormAI DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include<stdio.h>

int main()
{
  int stock_price[5] = {50, 75, 100, 125, 150}; // initializing the stock prices for the last 5 days
  int current_price = stock_price[4]; // current stock price is the price of the last day
  
  printf("Today's stock price: %d\n", current_price);
  
  int temp_price = current_price;
  int target_price = current_price + (0.05 * current_price); // setting the target price to be 5% higher than the current price
  
  printf("Target price: %d\n", target_price);
  
  while(temp_price <= target_price) // keep updating the stock price until it reaches the target
  {
    temp_price += (0.01 * temp_price); // increment the stock price by 1% each time
    printf("Current stock price: %d\n", temp_price);
  }
  
  printf("Stock price has reached the target!\n");
  
  return 0;
}