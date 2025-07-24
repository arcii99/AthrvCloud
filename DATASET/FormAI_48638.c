//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator with current time
  
  float price = 100.00; // starting price of stock
  float volatility = 0.20; // the volatility of the stock
  float drift = 0.10; // the rate at which the stock price drifts
  
  printf("Starting stock price: $%.2f\n", price);
  
  for(int i = 1; i <= 50; i++) {
    float rand_num = ((float)rand() / (float)RAND_MAX) * 2.0 - 1.0; // generate a random number between -1.0 and 1.0
    float change = volatility * rand_num + drift; // calculate the change in the stock price for the current day
    
    if(price + change > 0) { // ensure the stock price doesn't drop below zero
      price += change; // update the stock price
    }
    
    printf("Day %d: $%.2f\n", i, price); // print the stock price for the current day
  }
  
  return 0;
}