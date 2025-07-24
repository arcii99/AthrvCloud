//FormAI DATASET v1.0 Category: Stock market tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STOCKS 5
#define DAYS 7

int main(void) {
  // Seed random number generator
  srand(time(NULL));

  // Initialize stocks and prices
  char* stocks[STOCKS] = {"AAPL", "GOOG", "FB", "NFLX", "MSFT"};
  float prices[STOCKS][DAYS];

  // Populate prices array with random numbers between 100 and 150
  for (int i = 0; i < STOCKS; i++) {
    for (int j = 0; j < DAYS; j++) {
      prices[i][j] = (rand() % 51) + 100;
    }
  }

  // Display table headers
  printf("%-7s", "Stock");
  for (int i = 1; i <= DAYS; i++) {
    printf("%-7s", "Day");
    printf("%-6d", i);
  }
  printf("\n");

  // Display table contents
  for (int i = 0; i < STOCKS; i++) {
    printf("%-7s", stocks[i]);
    for (int j = 0; j < DAYS; j++) {
      printf("%-7s", "$");
      printf("%-5.2f", prices[i][j]);
    }
    printf("\n");
  }

  return 0;
}