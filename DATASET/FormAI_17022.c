//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stock {
  char name[50];
  float price;
  int quantity;
  float percentage_change;
};

struct stock market[] = {
  {"Tesla", 690.00, 300, 2.75},
  {"Apple", 135.00, 500, -1.25},
  {"Microsoft", 245.00, 1000, 0.50},
  {"Amazon", 3300.00, 50, 1.25},
  {"Facebook", 310.00, 250, -0.75}
};

int main(void) {
  printf("Welcome to the Stock Market Tracker!\n\n");

  int num_stocks = sizeof(market) / sizeof(market[0]);

  float total_value = 0.00;
  float market_change = 0.00;
  int gainers = 0;
  int losers = 0;

  printf("Here are the current stock prices and quantities:\n\n");
  printf("Name\t\tPrice\tQuantity\n");
  printf("--------------------------------------------------\n");
  
  for (int i = 0; i < num_stocks; i++) {
    printf("%s\t%.2f\t%d\n", market[i].name, market[i].price, market[i].quantity);
    total_value += market[i].price * market[i].quantity;
    market_change += (market[i].price * market[i].quantity * market[i].percentage_change) / 100;

    if (market[i].percentage_change > 0.00) {
      gainers++;
    } else if (market[i].percentage_change < 0.00) {
      losers++;
    }
  }

  printf("\nTotal portfolio value: $%.2f", total_value);
  printf("\nMarket change today: $%.2f", market_change);

  if (market_change > 0.00) {
    printf("\nOverall market gain today.\n");
  } else if (market_change < 0.00) {
    printf("\nOverall market loss today.\n");
  } else {
    printf("\nOverall market neither gained nor lost today.\n");
  }

  printf("\n");
  printf("There are %d winning stocks and %d losing stocks today.\n", gainers, losers);

  return 0;
}