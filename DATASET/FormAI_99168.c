//FormAI DATASET v1.0 Category: Stock market tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed random number generator with current time
  int stockPrices[10]; // Array to hold 10 stock prices
  int i, j;
  int change; // Variable to hold price change
  int currentPrice; // Variable to hold current price

  // Initialize stock prices
  for(i = 0; i < 10; i++) {
    stockPrices[i] = rand() % 101; // Generate random number from 0 to 100
  }

  printf("Welcome to the Retro Stock Market Tracker!\n\n");

  // Loop to simulate changes in stock prices
  for(i = 0; i < 5; i++) {
    printf("Day %d:\n", i+1);
    for(j = 0; j < 10; j++) {
      currentPrice = stockPrices[j];
      change = rand() % 21 - 10; // Generate random change from -10 to 10
      stockPrices[j] += change;
      printf("Stock %d: $%d -> $%d\n", j+1, currentPrice, stockPrices[j]);
    }
    printf("\n");
  }

  printf("Final Stock Prices:\n");
  for(i = 0; i < 10; i++) {
    printf("Stock %d: $%d\n", i+1, stockPrices[i]);
  }

  return 0;
}