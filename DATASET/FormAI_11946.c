//FormAI DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
  // declare variables
  char symbol[10];
  float price;
  float previous_price;

  // prompt user for stock symbol
  printf("Enter the stock symbol: ");
  fgets(symbol, 10, stdin);

  // prompt user for previous day's price
  printf("Enter the previous day's price: ");
  scanf("%f", &previous_price);

  // prompt user for current price
  printf("Enter the current price: ");
  scanf("%f", &price);

  // calculate percentage change
  float percentage_change = ((price - previous_price) / previous_price) * 100;

  // output results
  printf("\n----------------------");
  printf("\nSymbol: %s", symbol);
  printf("Previous Price: $%.2f\n", previous_price);
  printf("Current Price: $%.2f\n", price);
  printf("Percentage Change: %.2f%%\n", percentage_change);
  printf("----------------------\n");

  return 0;
}