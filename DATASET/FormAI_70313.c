//FormAI DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int stockPrices[5] = {100, 200, 300, 400, 500}; // Initial stock prices

  srand(time(0)); // Seed for the random number generator

  printf("Stock prices are fluctuating!!!\n");

  for(int i = 0; i < 10; i++) { // Loop for generating 10 random stock prices
    int change = rand() % 101 - 50; // Random number from -50 to 50
    int index = rand() % 5; // Random index from 0 to 4
    int newPrice = stockPrices[index] + change; // Calculate new price

    if(newPrice < 0) { // Check if new price is negative
      printf("Stock %d has gone bankrupt!!!\n", index);
      stockPrices[index] = 0; // Set price to 0 in case of bankruptcy
    }
    else {
      printf("Stock %d has changed by %d points!!! New price is %d points.\n", index, change, newPrice);
      stockPrices[index] = newPrice; // Update price
    }
  }

  printf("Final stock prices are:\n");

  for(int i = 0; i < 5; i++) { // Loop for printing final stock prices
    printf("Stock %d: %d points.\n", i, stockPrices[i]);
  }

  return 0;
}