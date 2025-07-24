//FormAI DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
  float price = 0.0;
  float change = 0.0;
  char symbol[10];

  printf("Enter the stock symbol: ");
  scanf("%s", symbol);

  printf("Enter the current price of %s stock: $", symbol);
  scanf("%f", &price);

  printf("Enter the change in %s stock price: ", symbol);
  scanf("%f", &change);

  printf("\n%s stock is currently trading at $%.2f, a change of %.2f%%.\n", symbol, price, (change/price)*100);

  return 0;
}