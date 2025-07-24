//FormAI DATASET v1.0 Category: Stock market tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int stock_price = 100;
  int num_days = 0;
  int max_price = 0;
  int min_price = 1000000;

  printf("Welcome to the Wacky Stock Market Tracker!\n\n");

  while (stock_price > 0)
  {
    printf("Day %d: The stock price is %d.\n", num_days+1, stock_price);

    if (stock_price > max_price)
      max_price = stock_price;

    if (stock_price < min_price)
      min_price = stock_price;

    srand(time(0)); // make sure we get random numbers
    int change = rand() % 11 - 5; // get random number between -5 and 5
    stock_price += change;

    if (stock_price < 0)
    {
      stock_price = 0;
      printf("Oh no! The stock has gone bankrupt and is now worthless.\n");
    }

    num_days++;
  }

  printf("\nYou tracked the stock for %d days.\n", num_days);
  printf("The highest price was %d and the lowest price was %d.\n", max_price, min_price);
  printf("Thanks for using the Wacky Stock Market Tracker! Remember, no refunds!\n");

  return 0;
}