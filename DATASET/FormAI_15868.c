//FormAI DATASET v1.0 Category: Stock market tracker ; Style: automated
#include <stdio.h>

int main(void) {
  float stock_price[5] = {150.25, 120.50, 180.75, 90.00, 135.50};
  char stock_name[5][10] = {"AAPL", "GOOGL", "TSLA", "AMZN", "FB"};

  float highest_price = stock_price[0];
  int highest_index = 0, lowest_index = 0;
  float lowest_price = stock_price[0];
  float average_price = 0.0;

  for(int i = 0; i < 5; i++) {
    if(stock_price[i] > highest_price) {
      highest_price = stock_price[i];
      highest_index = i;
    }

    if(stock_price[i] < lowest_price) {
      lowest_price = stock_price[i];
      lowest_index = i;
    }

    average_price += stock_price[i];
  }

  average_price = average_price / 5;

  printf("Stock Summary\n");
  printf("-----------------------\n");
  printf("Name\tPrice\n");

  for(int i = 0; i < 5; i++) {
    printf("%s\t%.2f\n", stock_name[i], stock_price[i]);
  }

  printf("-----------------------\n");
  printf("Highest Price: %s at $%.2f\n", stock_name[highest_index], highest_price);
  printf("Lowest Price: %s at $%.2f\n", stock_name[lowest_index], lowest_price);
  printf("Average Price: $%.2f\n", average_price);

  return 0;
}