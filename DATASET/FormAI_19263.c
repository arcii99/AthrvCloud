//FormAI DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// function to display stock data
void display_data(char* stock, float price, float change_percent) {
  printf("\n---\n%s\nCurrent Price: $%.2f\nPercent Change: %.2f%%\n---\n", stock, price, change_percent);
}

int main() {
  char stock_name[5][10] = {"APPL", "GOOG", "AMZN", "TSLA", "FB"}; // list of stocks to track
  float stock_price[5] = {127.79, 1831.73, 3346.83, 821.49, 275.00}; // current stock price
  float stock_change[5] = {1.23, -0.56, 2.45, -1.17, 0.99}; // percentage change
  int selection; // user input for stock selection

  printf("Welcome to the Energetic Stock Tracker!\n");
  printf("Choose a stock to view:\n");
  for (int i=0; i<5; i++) {
    printf("%d. %s\n", i+1, stock_name[i]);
  }
  printf("Enter the number of the stock you want to view: ");
  scanf("%d", &selection);

  // check if selection is valid
  while (selection<1 || selection>5) {
    printf("Invalid selection. Please enter a number between 1 and 5.");
    scanf("%d", &selection);
  }

  // display stock data
  display_data(stock_name[selection-1], stock_price[selection-1], stock_change[selection-1]);

  return 0;
}