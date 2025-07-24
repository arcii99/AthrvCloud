//FormAI DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stock {
  char symbol[6];
  double price;
  double change;
} stock;

void update_stock_price(stock* s) {
  // Use a random function to update the price and change
  double rand_num = ((double) rand() / (RAND_MAX));
  s->price = s->price + rand_num;
  s->change = rand_num;
}

int main() {
  // Initialize an array of 5 stock objects
  stock stocks[5] = {
    {"AAPL", 135.46, 0},
    {"GOOG", 2273.42, 0},
    {"MSFT", 260.92, 0},
    {"TSLA", 685.7, 0},
    {"AMZN", 3467.42, 0}
  };

  // Print the header for the stock market tracker
  printf("Symbol\tPrice\tChange\n");

  // Loop through the stocks and print their current price and change
  for (int i = 0; i < 5; i++) {
    update_stock_price(&stocks[i]);
    printf("%s\t%.2f\t%.2f%%\n", stocks[i].symbol, stocks[i].price, stocks[i].change * 100);
  }

  // Simulate updating the stock prices every second for 10 seconds
  for (int i = 1; i <= 10; i++) {
    printf("Updating stock prices (%d/10)\n", i);
    for (int j = 0; j < 5; j++) {
      update_stock_price(&stocks[j]);
      printf("%s\t%.2f\t%.2f%%\n", stocks[j].symbol, stocks[j].price, stocks[j].change * 100);
    }
    printf("\n");
  }

  return 0;
}