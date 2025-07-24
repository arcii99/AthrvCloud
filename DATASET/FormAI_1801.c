//FormAI DATASET v1.0 Category: Stock market tracker ; Style: genious
#include <stdio.h>

int main() {
  // Display greeting message
  printf("Welcome to the C Stock Market Tracker\n");

  // Declare variables for each stock we will be tracking
  int microsoft = 255;
  float apple = 134.56;
  double google = 2089.45;
  long facebook = 303;

  // Display initial prices for each stock
  printf("Microsoft: %d\n", microsoft);
  printf("Apple: %.2f\n", apple);
  printf("Google: %.2lf\n", google);
  printf("Facebook: %ld\n", facebook);

  // Simulate changes in stock prices
  microsoft += 5;
  apple -= 3.45;
  google *= 1.1;
  facebook += 15;

  // Display updated prices for each stock
  printf("\nStock prices have changed!\n");
  printf("Microsoft: %d\n", microsoft);
  printf("Apple: %.2f\n", apple);
  printf("Google: %.2lf\n", google);
  printf("Facebook: %ld\n", facebook);

  // Calculate the total value of all stocks together
  float total = microsoft + apple + google + facebook;
  printf("\nThe total value of all stocks is: $%.2f\n", total);

  return 0;
}