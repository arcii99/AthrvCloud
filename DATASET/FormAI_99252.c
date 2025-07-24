//FormAI DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
  float stock_prices[] = {23.5, 45.2, 32.1, 90.0, 56.8, 73.9, 88.7, 65.4, 70.2, 42.1};
  int num_of_stocks = sizeof(stock_prices) / sizeof(stock_prices[0]);
  float stock_total = 0.0, stock_average = 0.0, stock_high = 0.0, stock_low = 999999.0;

  for(int i = 0; i < num_of_stocks; i++) {
    stock_total += stock_prices[i];

    if(stock_prices[i] > stock_high) {
      stock_high = stock_prices[i];
    }

    if(stock_prices[i] < stock_low) {
      stock_low = stock_prices[i];
    }
  }

  stock_average = stock_total / num_of_stocks;

  printf("Stock prices for the last 10 days:\n");

  for(int i = 0; i < num_of_stocks; i++) {
    printf("%.1f ", stock_prices[i]);
  }

  printf("\n\n");

  printf("Stock average: %.2f\n", stock_average);
  printf("Stock highest: %.2f\n", stock_high);
  printf("Stock lowest: %.2f\n", stock_low);

  return 0;
}