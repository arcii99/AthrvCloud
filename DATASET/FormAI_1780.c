//FormAI DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>

int main() {
  float stockPrice = 50.0; // Starting stock price
  int day = 1; // Starting day
  float change; // Amount of change in stock price

  printf("Day %d: $%.2f\n", day, stockPrice); // Print starting stock price

  // Loop through 30 days
  for (int i = 1; i <= 30; i++) {
    day++; // Increment day
    change = (float)((rand() % 100) - 50) / 100.0; // Generate random price change between -0.50 and 0.50
    stockPrice += change; // Update stock price
    printf("Day %d: $%.2f", day, stockPrice); // Print stock price for the day
    if (change > 0) {
      printf(" (+%.2f)", change); // Print positive change with a plus sign
    } else if (change < 0) {
      printf(" (%.2f)", change); // Print negative change with no sign
    }
    printf("\n"); // Move to next line
  }

  return 0;
}