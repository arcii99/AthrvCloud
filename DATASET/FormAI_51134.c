//FormAI DATASET v1.0 Category: Stock market tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Define an array to hold stock symbols
  char* stocks[] = {"AAPL", "GOOG", "MSFT", "AMZN", "TSLA", "FB", "NVDA", "NFLX", "PYPL", "INTC"};

  // Define an array to hold stock prices (initialized with random values)
  float prices[10];
  for (int i = 0; i < 10; i++) {
    prices[i] = ((float)(rand() % 20000)) / 100.0;
  }

  // Define an array to hold number of shares (initialized with random values)
  int shares[10];
  for (int i = 0; i < 10; i++) {
    shares[i] = rand() % 1000;
  }

  // Define an array to hold total value of each stock
  float total_values[10];
  for (int i = 0; i < 10; i++) {
    total_values[i] = prices[i] * shares[i];
  }

  // Print heading
  printf("Symbol\tPrice\tShares\tValue\n");
  printf("----------------------------------------\n");

  // Print stock information
  for (int i = 0; i < 10; i++) {
    printf("%s\t%.2f\t%d\t%.2f\n", stocks[i], prices[i], shares[i], total_values[i]);
  }

  // Calculate and print total portfolio value
  float portfolio_value = 0;
  for (int i = 0; i < 10; i++) {
    portfolio_value += total_values[i];
  }
  printf("----------------------------------------\n");
  printf("Total portfolio value: %.2f\n", portfolio_value);

  return 0;
}