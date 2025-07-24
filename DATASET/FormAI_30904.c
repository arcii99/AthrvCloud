//FormAI DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initialize random seed
  int stock_price = 100; // initial stock price
  int days = 100; // number of days to track
  int prices[days]; // array to store daily stock prices
  prices[0] = stock_price;

  printf("Day 1: $%d\n", prices[0]);

  for(int i = 1; i < days; i++) {
    int price_change = rand() % (21) - 10; // random price change between -10 and 10
    int new_price = prices[i-1] + price_change; // calculate new stock price
    if(new_price <= 0) { // check if stock has gone bankrupt
      printf("Day %d: BANKRUPTCY\n", i+1);
      return 0;
    }
    prices[i] = new_price; // store new stock price in array
    printf("Day %d: $%d\n", i+1, prices[i]);
  }

  return 0;
}