//FormAI DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>

int main() {

  float stockPrice;
  float prevPrice;
  float change;

  printf("Welcome to the Awesome Stock Market Tracker!\n\n");

  // Prompt user for previous day's closing price
  printf("Please enter yesterday's closing price: $");
  scanf("%f", &prevPrice);

  // Prompt user for current day's stock price
  printf("\nPlease enter today's stock price: $");
  scanf("%f", &stockPrice);

  // Calculate the change in stock price
  change = stockPrice - prevPrice;

  // Print out the current stock price and the change
  printf("\nToday's stock price is: $%.2f\n", stockPrice);

  if (change > 0) {
    printf("The stock has gone up by $%.2f from yesterday!\n", change);
  } else if (change < 0) {
    printf("The stock has gone down by $%.2f from yesterday :(\n", change);
  } else {
    printf("The stock price hasn't changed from yesterday.\n");
  }

  printf("\nThank you for using the Awesome Stock Market Tracker!");

  return 0;
}