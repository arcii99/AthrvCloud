//FormAI DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Stock market tracker for lovers */
int main() {
  srand(time(NULL));
  int days = 30; // number of days
  float stock_price = 100; // starting stock price
  float balance = 1000; // starting balance
  int bought = 0; // number of stocks bought
  int sold = 0; // number of stocks sold
  float max_price = 100; // maximum stock price seen
  float min_price = 100; // minimum stock price seen
  for(int i = 1; i <= days; i++) {
    float change = ((float)rand()/(float)(RAND_MAX)) * 20 - 10; // random price change
    stock_price += change;
    if(stock_price > max_price) {
      max_price = stock_price;
    }
    if(stock_price < min_price) {
      min_price = stock_price;
    }
    printf("Day %d:\n", i);
    printf("Stock price: %.2f\n", stock_price);
    if(balance > 0) {
      if(rand() % 2 == 0) {
        // buy stocks
        int max_buy = (int)(balance / stock_price);
        if(max_buy > 0) {
          int buy = rand() % max_buy + 1;
          bought += buy;
          balance -= buy * stock_price;
          printf("Bought %d stocks\n", buy);
        }
      } else {
        // sell stocks
        if(bought > sold) {
          int max_sell = bought - sold;
          int sell = rand() % max_sell + 1;
          sold += sell;
          balance += sell * stock_price;
          printf("Sold %d stocks\n", sell);
        }
      }
    }
    printf("Balance: %.2f\n", balance);
    printf("Total stocks owned: %d\n", bought - sold);
    printf("Max price seen: %.2f\n", max_price);
    printf("Min price seen: %.2f\n\n", min_price);
    printf("******************\n");
  }
  printf("Final Balance: %.2f\n", balance);
  printf("Total stocks owned at the end: %d\n", bought - sold);
  return 0;
}