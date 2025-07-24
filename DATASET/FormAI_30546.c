//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>

int main() {
  float current_price = 52.50; // current price of the stock
  float last_price = 50.00; // last closing price of the stock
  float price_change = current_price - last_price;

  printf("Name: XYZ Corp.\n");
  printf("Symbol: XYZ\n");
  printf("Current Price: $%.2f\n", current_price);

  if (price_change > 0) {
    printf("Price Change: +$%.2f\n", price_change);
    printf("Percentage Change: +%.2f%%\n", (price_change / last_price) * 100);
  } else if (price_change < 0) {
    printf("Price Change: -$%.2f\n", price_change * -1);
    printf("Percentage Change: -%.2f%%\n", (price_change / last_price) * 100 * -1);
  } else {
    printf("Price Change: $%.2f\n", price_change);
    printf("Percentage Change: 0.00%%\n");
  }

  return 0;
}