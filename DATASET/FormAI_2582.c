//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Set random seed based on time

  double stock_price = 100.0; // Initial stock price
  double volatility = 0.2; // Volatility percentage
  int days = 365; // Number of trading days in a year
  double starting_capital = 10000.0; // Starting capital

  for (int i = 0; i < days; i++) {
    double random_number = (double)rand() / RAND_MAX; // Generate a random number between 0 and 1
    double change_percentage = 2 * volatility * random_number; // Calculate the percentage change based on volatility and random number
    double change_amount = stock_price * change_percentage; // Calculate the change in the stock price
    stock_price += change_amount; // Update the stock price

    double capital_change = starting_capital * change_percentage; // Calculate the corresponding capital change
    starting_capital += capital_change; // Update the capital

    printf("Day %d: Stock price=%.2f Capital=%.2f\n", i+1, stock_price, starting_capital); // Print the current state
  }

  return 0;
}